/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 06:54:43 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/21 07:39:15 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include "rtv1.h"

t_object	*get_lastlink(t_object *obj)
{
	while (obj && obj->next)
	{
		obj = obj->next;
	}
	return (obj);
}

void	object_translate(t_vector *pos, int key)
{
	if (pos != NULL)
	{
		if (key == KEY_UP)
			pos->z += 0.1;
		else if (key == KEY_DOWN)
			pos->z -= 0.1;
		else if (key == KEY_RIGHT)
			pos->x += 0.1;
		else if (key == KEY_LEFT)
			pos->x -= 0.1;
		else if (key == KEY_PLUS)
			pos->y += 0.1;
		else if (key == KEY_LESS)
			pos->y -= 0.1;
	}
}

t_vector	*get_vec(t_object *obj, int v)
{
	if (obj->type == RT_CYL)
		return ((v == 'p') ? &(obj->u_fig.cyl.pos) : &(obj->u_fig.cyl.dir));
	else if (obj->type == RT_CONE)
		return ((v == 'p') ? &(obj->u_fig.cone.pos) : &(obj->u_fig.cone.dir));
	else if (obj->type == RT_PLANE)
		return ((v == 'p') ? &(obj->u_fig.plane.pos) : &(obj->u_fig.cyl.dir));
	else if (obj->type == RT_SPHERE)
		return ((v == 'p') ? &(obj->u_fig.sphere.pos) : NULL);
	else if (obj->type == RT_LIGHT)
		return ((v == 'p') ? &(obj->u_fig.light.pos) : &(obj->u_fig.cyl.dir));
	else if (obj->type == RT_CAM)
		return ((v == 'p') ? &(obj->u_fig.cam.pos) : NULL);
	return (NULL);
}

int		deal_key(int key, t_fmlx *mlx)
{
	if (key == KEY_ESC)
		rtv_exit(mlx);
	else if ((key >= KEY_LEFT && key <= KEY_UP) || key == KEY_PLUS || key == KEY_LESS)
		object_translate(get_vec(mlx->current, 'p'), key);
	else if (key == KEY_PGUP || key == KEY_PGDWN)
	{
		if (key == KEY_PGUP)
			mlx->current = (mlx->current->prev) ? mlx->current->prev : get_lastlink(mlx->obj);
		if (key == KEY_PGDWN)
			mlx->current = (mlx->current->next) ? mlx->current->next : mlx->obj;
		disp_ui(mlx);
		return (0);
	}
	else if (key == KEY_PLUS)
		mlx->vp.dist *= 1.3;
	else if (key == KEY_LESS)
		mlx->vp.dist *= 0.7;
	else
		return (key);
	get_viewplane(&(mlx->vp), mlx->cam);
	rt_render(mlx);
	return (key);
}

int		mouse_press(int button, int x, int y, t_fmlx *mlx)
{
	(void)x;
	(void)y;
	(void)mlx;
	return (button);
}

int		mouse_move(int x, int y, t_fmlx *mlx)
{
	(void)x;
	(void)y;
	(void)mlx;
	return (0);
}
