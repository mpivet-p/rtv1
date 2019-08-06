/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:50:05 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/06 07:26:35 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "rtv1.h"
#include "libft.h"

void	intersect(t_ray *ray, t_object *obj)
{
	static double	(*figures[4])(t_ray ray, t_object *obj)= {
		intersect_cylinder, intersect_cone, intersect_plane, intersect_sphere};
	t_object		*ptr;
	double 			ret;

	ret = 0.0;
	ptr = obj;
	while (ptr != NULL)
	{
		if (((ret = figures[ptr->type](*ray, ptr)) < ray->t || ray->t == 0) && ret > 0)
		{
			ray->t = ret;
			ray->hit_by = ptr;
		}
		ptr = ptr->next;
	}
}

double	get_diffuse_color(t_ray *ray, t_vector *light_pos)
{
	t_vector	lightvector;
	t_vector	position;
	double		angle;

 	position = add_vectors(ray->origin, vector_mult(ray->dir, ray->t));
 	lightvector = normalize(sub_vectors(position, *light_pos));
 	angle = dot_product(get_normal(ray, position), vector_mult(lightvector, -1));
	if (angle > 0)
		return (angle);
	return (0);
}

double	get_ambient_color(void)
{
	return (0.1);
}

void	get_color(t_ray *ray, t_vector *light_pos)
{
	double	coeff;

	coeff = get_ambient_color() + get_diffuse_color(ray, light_pos);
	ray->color = mult_color(ray->hit_by->color, coeff);
}

int		rt_render(t_fmlx *mlx)
{
	t_vector	light_pos;
	t_ray		ray;
	int			i;

	i = 0;
	light_pos = init_vector(-1.2, 0.8, 1);
	ray.origin = vector_mult(mlx->cam.pos, 1);
	while (i < SIMG_X * SIMG_Y)
	{
		reset_ray(&ray, mlx, i / SIMG_Y, i % SIMG_Y);
		intersect(&ray, mlx->obj);
		if (ray.t > 0.0)
			get_color(&ray, &light_pos);
		fill_pxl(mlx->screen, i / SIMG_Y, i % SIMG_Y, ray.color);
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

void	rt(t_fmlx *mlx)
{
	mlx->obj = list_test();
	rt_init(&(mlx->cam), &(mlx->vp));
	get_viewplane(&(mlx->vp), mlx->cam);
	rt_render(mlx);
}
