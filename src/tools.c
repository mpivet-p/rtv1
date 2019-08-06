/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 04:49:56 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/06 12:52:11 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include "rtv1.h"

void	fill_pxl(char *image, int x, int y, int color)
{
	int i;

	i = (((SIMG_X * y) + x) * 4);
	if (x >= 0 && y >= 0 && x < SIMG_X && y < SIMG_Y)
	{
		image[i + 2] = (color >> 16) & 0xFF;
		image[i + 1] = (color >> 8) & 0xFF;
		image[i + 0] = color & 0xFF;
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

int		mult_color(int color, double mult)
{
	int r;
	int g;
	int b;

	r = ((color & 0xFF0000) >> 16);
	g = ((color & 0xFF00) >> 8);
	b = (color & 0xFF);
	color = init_color(((r * mult) > 0xFF) ? 0xFF : (r * mult)
		, ((g * mult) > 0xFF) ? 0xFF : g * mult
		, ((b * mult) > 0xFF) ? 0xFF : b * mult);
	return (color);
}
