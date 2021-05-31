/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 04:21:18 by mpivet-p          #+#    #+#             */
/*   Updated: 2021/05/31 18:39:50 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "rtv1.h"

double	norm_vector(t_vector vector)
{
	double	ret;

	ret = pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2);
	return (sqrt(ret));
}

t_vector	normalize(t_vector vector)
{
	double		norm;
	t_vector	ret;

	norm = norm_vector(vector);
	if (norm == 0)
		norm = 0.0001;
	ret.x = vector.x / norm;
	ret.y = vector.y / norm;
	ret.z = vector.z / norm;
	return (ret);
}

t_vector	get_normal(t_ray *ray, t_vector position)
{
	static	t_vector	(*normals[4])(t_ray *ray, t_vector position) = {
		normal_cylinder, normal_cone, normal_plane, normal_sphere};

	return (normalize(normals[ray->hit_by->type](ray, position)));
}
