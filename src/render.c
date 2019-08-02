/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:50:05 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/02 05:37:54 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "rtdata.h"
#include "rtv1.h"
#include "libft.h"

void	rt_init(t_camera *cam, t_viewplane *vp)
{
	vp->width = 0.5;
	vp->height = 0.28125;
	vp->dist = 1;
	cam->pos = init_vector(0, 0, 0);
	cam->vecdir = init_vector(0, 1, 0);
	cam->rightvec = init_vector(1, 0, 0);
	cam->upvec = init_vector(0, 0, 1);
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
	printf("dist = %f size = %f cap.pos.x = %f cap.pos.y = %f cap.pos.z = %f\n", mlx->vp.dist, mlx->size, mlx->cam.pos.x, mlx->cam.pos.y, mlx->cam.pos.z);
	printf("sphere x: %f   y: %f    z: %f\n", mlx->sphere.x, mlx->sphere.y, mlx->sphere.z);
	while (x < SIMG_X)
	{
		while (y < SIMG_Y)
		{
			ray.dir = get_dir(mlx->vp, mlx->cam, ray, get_indent(mlx->vp, init_point(x, y, 0)));
			if (solve_sphere(ray, sub_vectors(mlx->sphere, init_vector(0.1, 0, 0)), mlx->size * 2) > 0.0)
				fill_pxl(mlx->screen, x, y, RT_BLUE);
			if (solve_sphere(ray, mlx->sphere, mlx->size) > 0.0)
				fill_pxl(mlx->screen, x, y, RT_RED);
			if (solve_sphere(ray, sub_vectors(mlx->sphere, init_vector(0.2, 0, 0)), mlx->size) > 0.0)
				fill_pxl(mlx->screen, x, y, RT_GREEN);
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
	mlx->sphere = init_vector(0.1, 1, 0);
	mlx->size = 0.05;
	rt_init(&(mlx->cam), &(mlx->vp));
	get_viewplane(&(mlx->vp), mlx->cam);
	rt_render(mlx);
}
