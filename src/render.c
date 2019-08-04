/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:50:05 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/04 07:56:58 by mpivet-p         ###   ########.fr       */
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
	static double	(*figures[4])(t_ray ray, t_object *obj) = {intersect_cylinder
		, intersect_cone, intersect_plane, intersect_sphere};
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

void	init_ray(t_ray *ray, t_fmlx *mlx, int x, int y)
{
	ray->hit_by = NULL;
	ray->t = 0;
	ray->color = 0;
	ray->dir = get_dir(mlx->vp, mlx->cam, *ray
			, get_indent(mlx->vp, init_point(x, y, 0)));
}

int		rt_render(t_fmlx *mlx)
{
	t_ray	ray;
	int		x;
	int		y;

	ray.origin.x = mlx->cam.pos.x;
	ray.origin.y = mlx->cam.pos.y;
	ray.origin.z = mlx->cam.pos.z;
	x = 0;
	y = 0;
	ft_bzero(mlx->screen, SIMG_X * SIMG_Y * 4);
	while (x < SIMG_X)
	{
		while (y < SIMG_Y)
		{
			init_ray(&ray, mlx, x, y);
			intersect(&ray, mlx->obj);
			if (ray.t > 0.0)
				fill_pxl(mlx->screen, x, y, ray.color);
			y++;
		}
		y = 0;
		x++;
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
