/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 03:50:53 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/18 04:55:10 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"

/*
** To intersect the cone with the ray's director vector we need the vecdir of
** the cone and his angle: `k` (calculated with his height and his radius).
** then we get send a, b and c to the solving function to get `t` value
*/

double		intersect_cone(t_ray ray, t_object *obj)
{
	t_cone		*cone;
	t_vector	base;
	double		vars[2];
	double		c;
	double		k;

	cone = &(obj->u_fig.cone);
	k = atan(cone->radius / cone->height);
	base = sub_vectors(ray.origin, cone->pos);
	vars[0] = dot_product(ray.dir, ray.dir) - (1 + k * k)
		* pow(dot_product(ray.dir, cone->dir), 2);
	vars[1] = 2 * (dot_product(ray.dir, base) - (1 + k * k)
			* (dot_product(ray.dir, cone->dir)
			* dot_product(base, cone->dir)));
	c = dot_product(base, base) - (1 + k * k)
		* pow(dot_product(base, cone->dir), 2);
	return (ft_solve(vars[0], vars[1], c));
}

t_vector	normal_cone(t_ray *ray, t_vector position)
{
	t_vector	ret;
	t_cone		*cone;
	double		k;

	cone = &(ray->hit_by->u_fig.cone);
	k = atan(cone->radius / cone->height);
	ret = vector_mult(vector_mult(cone->dir, 1 + k * k), cone->height * -1);
	ret = normalize(sub_vectors(position, sub_vectors(cone->pos, ret)));
	if (dot_product(ray->dir, ret) > 0.0001)
		ret = vector_mult(ret, -1);
	return (ret);
}
