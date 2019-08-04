/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 00:49:06 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/04 03:37:54 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtdata.h"

double	intersect_plane(t_ray ray, t_object *obj)
{
	t_plane		*plane;
	t_vector	base;

	plane = &(obj->plane);
	base = sub_vectors(ray.origin, plane->pos);
	return (-1.0 * (dot_product(plane->dir, base)
					/ dot_product(plane->dir, ray.dir)));
}
