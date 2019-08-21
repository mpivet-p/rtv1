/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 00:47:57 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/21 04:06:09 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <mlx.h>
#include <stdio.h>

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
	char	*shapes[5] = {"cylinder", "cone", "plane", "sphere", "light"};
	char	name[27];

	ft_bzero(name, 27);
	ft_strcat(name, shapes[mlx->current->type]);
	ft_strcat(name, ": ");
	ft_strcat(name, mlx->current->name);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->ui, 0, SIMG_Y);
	mlx_string_put(mlx->mlx, mlx->win, 45, SIMG_Y + 9, 0, name);
}
