/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:50:05 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/03 10:45:34 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "rtdata.h"
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

int		rt_render(t_fmlx *mlx)
{
	t_cylinder cyl;
	t_cone	cone;
	t_ray	ray;
	int		x;
	int		y;

	ray.origin.x = mlx->cam.pos.x;
	ray.origin.y = mlx->cam.pos.y;
	ray.origin.z = mlx->cam.pos.z;
	//CONE
	cone.radius = 1;
	cone.height = 3;
	cone.pos = init_vector(0, 1, 0);
	cone.dir = init_vector(0, 0, 1);
	//CYLINDER
	cyl.radius = 0.08;
	cyl.pos = init_vector(-0.5, 1, 0);
	cyl.dir = init_vector(0, 1, 1);
	x = 0;
	y = 0;
	ft_bzero(mlx->screen, SIMG_X * SIMG_Y * 4);
	while (x < SIMG_X)
	{
		while (y < SIMG_Y)
		{
			ray.dir = get_dir(mlx->vp, mlx->cam, ray, get_indent(mlx->vp, init_point(x, y, 0)));
			if (solve_plane(ray, init_vector(0, 0, 1), init_point(0, 0, -0.5)) > 0.0)
				fill_pxl(mlx->screen, x, y, 0x0589f5);
			if (solve_cone(ray, cone) > 0.0)
				fill_pxl(mlx->screen, x, y, RT_GREEN);
//NOT WORKING
//			if (solve_cylinder(ray, cyl) > 0.0)
//				fill_pxl(mlx->screen, x, y, RT_PURPLE);
			if (solve_sphere(ray, sub_vectors(mlx->sphere, init_vector(0.5, 0, 0)), mlx->size * 2) > 0.0)
				fill_pxl(mlx->screen, x, y, 0xf54611);
			if (solve_sphere(ray, mlx->sphere, mlx->size) > 0.0)
				fill_pxl(mlx->screen, x, y, RT_YELLO);
			if (solve_sphere(ray, sub_vectors(mlx->sphere, init_vector(0.2, 0, 0)), mlx->size) > 0.0)
				fill_pxl(mlx->screen, x, y, 0xf5a511);
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
	mlx->sphere = init_vector(0, 1, 0);
	mlx->size = 0.1;
	rt_init(&(mlx->cam), &(mlx->vp));
	get_viewplane(&(mlx->vp), mlx->cam);
	rt_render(mlx);
}
//	printf("dist = %f size = %f cap.pos.x = %f cap.pos.y = %f cap.pos.z = %f\n", mlx->vp.dist, mlx->size, mlx->cam.pos.x, mlx->cam.pos.y, mlx->cam.pos.z);
//	printf("sphere x: %f   y: %f    z: %f\n", mlx->sphere.x, mlx->sphere.y, mlx->sphere.z);
