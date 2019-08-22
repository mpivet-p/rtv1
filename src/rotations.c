/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 05:09:13 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/22 04:52:46 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <string.h>
#include "rtv1.h"

static void	rot_x(t_vector *vec, double theta)
{
	double	save;

	save = vec->y;
	theta = theta * 3.141592653 / 180.0;
	vec->y = vec->y * cos(theta) - vec->z * sin(theta);
	vec->z = save * sin(theta) + vec->z * cos(theta);
	*vec = normalize(*vec);
}

static void	rot_y(t_vector *vec, double theta)
{
	double	save;

	save = vec->x;
	theta = theta * 3.141592653 / 180.0;
	vec->x = vec->x * cos(theta) + vec->z * sin(theta);
	vec->z = vec->z * cos(theta) - vec->x * sin(theta);
	*vec = normalize(*vec);
}

static void	rot_z(t_vector *vec, double theta)
{
	double	save;

	save = vec->x;
	theta = theta * 3.141592653 / 180.0;
	vec->x = vec->x * cos(theta) - vec->y * sin(theta);
	vec->y = save * sin(theta) + vec->y * cos(theta);
	*vec = normalize(*vec);
}

void		object_translate(t_vector *pos, int key, int modif)
{
	if (pos != NULL)
	{
		if (key == KEY_UP)
			pos->z += 0.1 * modif;
		else if (key == KEY_DOWN)
			pos->z -= 0.1 * modif;
		else if (key == KEY_RIGHT)
			pos->x += 0.1 * modif;
		else if (key == KEY_LEFT)
			pos->x -= 0.1 * modif;
		else if (key == KEY_PLUS)
			pos->y += 0.1 * modif;
		else if (key == KEY_LESS)
			pos->y -= 0.1 * modif;
	}
}

void		object_rotate(t_vector *pos, int key, int modif)
{
	if (pos != NULL)
	{
		if (key == KEY_W)
			rot_x(pos, 5 * modif);
		else if (key == KEY_S)
			rot_x(pos, -5 * modif);
		else if (key == KEY_D)
			rot_y(pos, 5 * modif);
		else if (key == KEY_A)
			rot_y(pos, -5 * modif);
		else if (key == KEY_Q)
			rot_z(pos, 5 * modif);
		else if (key == KEY_E)
			rot_z(pos, -5 * modif);
	}
}
