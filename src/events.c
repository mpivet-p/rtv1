/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 06:54:43 by mpivet-p          #+#    #+#             */
/*   Updated: 2021/01/31 14:39:21 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <mlx.h>
#include <string.h>

static t_vector	*hack_norm(int cond, t_vector *a, t_vector *b)
{
	if (cond)
		return (a);
	return (b);
}

static t_vector	*get_vec(t_object *obj, int v)
{
	t_fig	*ptr;

	ptr = &(obj->u_fig);
	if (obj->type == RT_CYL)
		return (hack_norm(v, &(ptr->cyl.pos), &(ptr->cyl.dir)));
	else if (obj->type == RT_CONE)
		return (hack_norm(v, &(ptr->cone.pos), &(ptr->cone.dir)));
	else if (obj->type == RT_PLANE)
		return (hack_norm(v, &(ptr->plane.pos), &(ptr->cyl.dir)));
	else if (obj->type == RT_SPHERE)
		return (hack_norm(v, &(ptr->sphere.pos), NULL));
	else if (obj->type == RT_LIGHT)
		return (hack_norm(v, &(ptr->light.pos), &(ptr->cyl.dir)));
	else if (obj->type == RT_CAM)
		return (hack_norm(v, &(ptr->cam.pos), NULL));
	return (NULL);
}

int	deal_key(int key, t_fmlx *mlx)
{
	if (key == KEY_ESC)
		rtv_exit(mlx);
	else if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_DOWN
		|| key == KEY_UP || key == KEY_PLUS || key == KEY_LESS)
		object_translate(get_vec(mlx->current, 1), key, mlx->intensity);
	else if ((key >= KEY_Q && key <= KEY_E) || (key >= KEY_A && key <= KEY_D))
		object_rotate(get_vec(mlx->current, 0), key, mlx->intensity);
	else if (key == KEY_PGUP || key == KEY_PGDWN)
	{
		if (key == KEY_PGUP)
			mlx->current = get_prevlink(mlx);
		else if (key == KEY_PGDWN && mlx->current->next)
			mlx->current = mlx->current->next;
		else
			mlx->current = mlx->obj;
		disp_ui(mlx);
		return (0);
	}
	else if (key == KEY_PLUS)
		mlx->vp.dist *= 1.3;
	else
		return (key);
	get_viewplane(&(mlx->vp), mlx->cam);
	rt_render(mlx);
	return (key);
}

int	mouse_press(int button, int x, int y, t_fmlx *mlx)
{
	(void)x;
	(void)y;
	(void)mlx;
	return (button);
}

int	mouse_move(int x, int y, t_fmlx *mlx)
{
	(void)x;
	(void)y;
	(void)mlx;
	return (0);
}
