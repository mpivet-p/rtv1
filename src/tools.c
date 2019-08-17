/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 04:49:56 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/17 07:32:15 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include "rtv1.h"
#include "libft.h"

//void	fill_img(char *image, int i, t_vector color)
//{
//	if (i < SIMG_X * SIMG_Y)
//	{
//		i *= 4;
//		image[i + 2] = color.x;
//		image[i + 1] = color.y;
//		image[i + 0] = color.z;
//	}
//}

void	fill_img(char *image, int x, int y, t_vector color)
{
	int i;

	i = (((SIMG_X * y) + x) * 4);
	if (x >= 0 && y >= 0 && x < SIMG_X && y < SIMG_Y)
	{
		image[i + 2] = color.x;
		image[i + 1] = color.y;
		image[i + 0] = color.z;
	}
}

void	rtv_exit(t_fmlx *mlx)
{
	if (mlx->mlx && mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->mlx && mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

t_vector	init_vector(double x, double y, double z)
{
	t_vector	vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;
	return (vect);
}

double		dot_product(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

void	reset_ray(t_ray *ray, t_fmlx *mlx, int x, int y)
{
	ray->hit_by = NULL;
	ray->t = 0;
	ray->color = 0;
	ray->dir = get_dir(mlx->vp, mlx->cam, *ray
			, get_indent(mlx->vp, init_vector(x, y, 0)));
}

int		init_color(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
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
