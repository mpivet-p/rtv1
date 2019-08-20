/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 00:47:57 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/20 02:00:07 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "rtv1.h"

void	init_ui(t_fmlx *mlx)
{
	int i;

	i = 0;
	while (i < SUI_Y * SUI_X)
	{
		mlx->ui_img[i * 4] = 0xD5;
		mlx->ui_img[i * 4 + 1] = 0xD3;
		mlx->ui_img[i * 4 + 2] = 0xD5;
		i++;
	}
}

void	disp_ui(t_fmlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->ui, 0, SIMG_Y);
	mlx_string_put(mlx->mlx, mlx->win, 45, SIMG_Y + 9, 0, "cylinder: 0123456789ABCDEF");
	mlx_string_put(mlx->mlx, mlx->win, 312, SIMG_Y + 9, 0x303030, "{ pos(0, -2, 1)");
	mlx_string_put(mlx->mlx, mlx->win, 475, SIMG_Y + 9, 0x303030, "dir(0, 0, 1) }");
}
