/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:47:35 by mpivet-p          #+#    #+#             */
/*   Updated: 2021/05/31 17:00:19 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "rtdata.h"

int	camera_event(int key)
{
	if (key == KEY_I || key == KEY_J || key == KEY_K || key == KEY_L
			|| key == KEY_U || key == KEY_O || key == KEY_Y || key == KEY_H)
		return (1);
	return(0);
}

void	camera_move(int key, t_fmlx *mlx)
{
	if (key == KEY_I)
		object_translate(&(mlx->cam.pos), KEY_UP, mlx->intensity);
	else if (key == KEY_J)
		object_translate(&(mlx->cam.pos), KEY_LEFT, mlx->intensity);
	else if (key == KEY_K)
		object_translate(&(mlx->cam.pos), KEY_DOWN, mlx->intensity);
	else if (key == KEY_L)
		object_translate(&(mlx->cam.pos), KEY_RIGHT, mlx->intensity);
	else if (key == KEY_Y)
		object_translate(&(mlx->cam.pos), KEY_PLUS, mlx->intensity);
	else if (key == KEY_H)
		object_translate(&(mlx->cam.pos), KEY_LESS, mlx->intensity);
	else if (key == KEY_U)
		object_rotate(&(mlx->cam.vecdir), KEY_Q, mlx->intensity);
	else if (key == KEY_O)
		object_rotate(&(mlx->cam.vecdir), KEY_E, mlx->intensity);
}
