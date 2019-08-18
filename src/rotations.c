/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 05:09:13 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/18 05:49:32 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"

void	rot_x(t_vector *vec, double theta)
{
	double	save;

	save = vec->y;
	theta = theta * 3.141592653 / 180.0;
	vec->y = vec->y * cos(theta) - vec->z * sin(theta);
	vec->z = save * sin(theta) + vec->z * cos(theta);
	*vec = normalize(*vec);
}

void	rot_y(t_vector *vec, double theta)
{
	double	save;

	save = vec->x;
	theta = theta * 3.141592653 / 180.0;
	vec->x = vec->x * cos(theta) + vec->z * sin(theta);
	vec->z = vec->z * cos(theta) - vec->x * sin(theta);
	*vec = normalize(*vec);
}

void	rot_z(t_vector *vec, double theta)
{
	double	save;

	save = vec->x;
	theta = theta * 3.141592653 / 180.0;
	vec->x = vec->x * cos(theta) - vec->y * sin(theta);
	vec->y = save * sin(theta) + vec->y * cos(theta);
	*vec = normalize(*vec);
}
