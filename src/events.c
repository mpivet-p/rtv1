/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 06:54:43 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/22 05:23:46 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <mlx.h>
#include <string.h>

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
		object_translate(get_vec(mlx->current, 'p'), key, mlx->intensity);
	else if ((key >= KEY_Q && key <= KEY_E) || (key >= KEY_A && key <= KEY_D))
		object_rotate(get_vec(mlx->current, 'd'), key, mlx->intensity);
	else if (key == KEY_PGUP || key == KEY_PGDWN)
	{
		if (key == KEY_PGUP)
			mlx->current = get_prevlink(mlx);
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
