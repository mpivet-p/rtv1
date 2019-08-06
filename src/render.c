/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:50:05 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/06 02:29:34 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "rtv1.h"
#include "libft.h"

void	rt_init(t_camera *cam, t_viewplane *vp)
{
	vp->width = SIMG_X;
	vp->height = SIMG_Y;
	vp->dist = 1000;
	cam->pos = init_vector(0, 0, 0);
	cam->vecdir = init_vector(0, 1, 0);
	cam->rightvec = init_vector(1, 0, 0);
	cam->upvec = init_vector(0, 0, 1);
}

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
			ray->color = ptr->color;
		}
		ptr = ptr->next;
	}
}

void	reset_ray(t_ray *ray, t_fmlx *mlx, int x, int y)
{
	ray->hit_by = NULL;
	ray->t = 0;
	ray->color = 0;
	ray->dir = get_dir(mlx->vp, mlx->cam, *ray
			, get_indent(mlx->vp, init_vector(x, y, 0)));
}

int		mult_color(int color, double mult)
{
	int r;
	int g;
	int b;

	r = ((color & 0xFF0000) >> 16) * mult;
	g = ((color & 0xFF00) >> 8) * mult;
	b = (color & 0xFF) * mult;
	color = (r << 16) + (g << 8) + b;
	return (color);
}

int		rt_render(t_fmlx *mlx)
{
	t_vector	position_lumiere;
	t_vector	lightvector;
	t_vector	position;
	double		angle;
	t_ray		ray;
	int			i;

	i = 0;
	angle = 0.0;
	position_lumiere = init_vector(0, 0, 1);
	ray.origin = vector_mult(mlx->cam.pos, 1);
	lightvector = init_vector(0, 0, 0);
	while (i < SIMG_X * SIMG_Y)
	{
		reset_ray(&ray, mlx, i / SIMG_Y, i % SIMG_Y);
		intersect(&ray, mlx->obj);
		if (ray.t > 0.0)
		{
			position = add_vectors(ray.origin, vector_mult(ray.dir, ray.t));
			lightvector = normalize(sub_vectors(position, position_lumiere));
			angle = dot_product(get_normal(&ray, position), vector_mult(lightvector, -1));
			ray.color = 0;
			if (angle > 0)
				ray.color = RT_WHITE;
			fill_pxl(mlx->screen, i / SIMG_Y, i % SIMG_Y, ray.color);
		}
		else
			fill_pxl(mlx->screen, i / SIMG_Y, i % SIMG_Y, 0);
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
