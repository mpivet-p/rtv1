/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 00:49:06 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/03 03:02:11 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtdata.h"

double	solve_plane(t_ray ray, t_vector vecdir, t_point plane)
{
	return (-1.0 * (((vecdir.x * (ray.origin.x - plane.x))
				+ (vecdir.y * (ray.origin.y - plane.y))
				+ (vecdir.z * (ray.origin.z - plane.z)))
			/ ((vecdir.x * ray.dir.x)
				+ (vecdir.y * ray.dir.y)
				+ (vecdir.z * ray.dir.z))));
}
