/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:50:05 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/09/08 00:03:04 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "rtv1.h"
#include "libft.h"

void	get_intersection(t_ray *ray, t_object *obj)
{
	static double	(*figures[4])(t_ray ray, t_object *obj)= {
		intersect_cylinder, intersect_cone, intersect_plane, intersect_sphere};
	t_ray			newray;
	t_vector		*tmp;
	double 			ret;

	ret = 0;
	newray = *ray;
	while (obj != NULL)
	{
		if (obj->type != RT_LIGHT)
		{
			tmp = get_vec(obj, 'p');
			newray.origin = sub_vectors(ray->origin, *tmp);
			tmp = get_vec(obj, 'd');
			newray.dir = do_rot(ray->dir, tmp);
		}
		if (obj->type != RT_LIGHT
				&& ((ret = figures[obj->type](newray, obj)) < ray->t
					|| ray->t == 0) && ret > 0)
		{
			ray->t = ret;
			ray->hit_by = obj;
		}
		obj = obj->next;
	}
}

int		rt_render(t_fmlx *mlx)
{
	t_vector	color;
	t_ray		ray;
	int			i;

	i = 0;
	ray.origin = init_vector(0, -1, 0);
	while (i < SIMG_X * SIMG_Y)
	{
		ft_bzero(&color, sizeof(color));
		reset_ray(&ray, mlx, i / SIMG_Y, i % SIMG_Y);
		ray.dir = normalize(ray.dir);
		get_intersection(&ray, mlx->obj);
		if (ray.t > 0.0)
			color = get_color(&ray, mlx->obj, mlx->obj);
		fill_img(mlx->screen, i / SIMG_Y, i % SIMG_Y, color);
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

void	rt(t_fmlx *mlx)
{
	mlx->obj = list_test();
	mlx->current = mlx->obj;
	rt_init(&(mlx->cam), &(mlx->vp));
	get_viewplane(&(mlx->vp), mlx->cam);
	rt_render(mlx);
}
