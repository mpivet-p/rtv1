/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 06:54:43 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/12 23:49:30 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include "rtv1.h"

int		deal_key(int key, t_fmlx *mlx)
{
	if (key == 53)
		rtv_exit(mlx);
	if (key == 125)
		mlx->cam.pos.z += 0.1;
	if (key == 126)
		mlx->cam.pos.z -= 0.1;
	if (key == 123)
		mlx->cam.pos.x += 0.05;
	if (key == 124)
		mlx->cam.pos.x -= 0.05;
	if (key == 116)
		mlx->cam.pos.y += 0.05;
	if (key == 121)
		mlx->cam.pos.y -= 0.05;
	if (key == 69)
		mlx->vp.dist *= 1.3;
	if (key == 78)
		mlx->vp.dist *= 0.7;
	get_viewplane(&(mlx->vp), mlx->cam);
	rt_render(mlx);
	return (key);
}

int		mouse_press(int button, int x, int y, t_fmlx *mlx)
{
	(void)mlx;
	printf("x = %i }{ y = %i\n", x, y);
	fill_pxl(mlx->screen, x, y, 0xFFFFFF);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (button);
}

int		mouse_move(int x, int y, t_fmlx *mlx)
{
	(void)x;
	(void)y;
	(void)mlx;
	return (0);
}
