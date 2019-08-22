/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 04:49:56 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/22 05:19:45 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include "rtv1.h"
#include "libft.h"

void	fill_img(char *image, int x, int y, t_vector color)
{
	int i;

	i = (((SIMG_X * y) + x) * 4);
	if (x >= 0 && y >= 0 && x < SIMG_X && y < SIMG_Y)
	{
		image[i + 2] = color.x;
		image[i + 1] = color.y;
		image[i] = color.z;
	}
}

void	rtv_exit(t_fmlx *mlx)
{
	rt_delist(mlx);
	if (mlx->mlx && mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->mlx && mlx->ui)
		mlx_destroy_image(mlx->mlx, mlx->ui);
	if (mlx->mlx && mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

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

t_vector	mult_color(int color, t_vector mult)
{
	t_vector	ret;
	t_vector	col;

	col.x = (color & 0xFF0000) >> 16;
	col.y = (color & 0xFF00) >> 8;
	col.z = color & 0xFF;
	ret.x = ft_max(col.x, col.x * mult.x);
	ret.y = ft_max(col.y, col.y * mult.y);
	ret.z = ft_max(col.z, col.z * mult.z);
	return (ret);
}
