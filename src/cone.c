/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 03:50:53 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/04 05:13:53 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"

/*
** To intersect the cone with the ray's director vector we need the vecdir of
** the cone and his angle: `k` (calculated with his height and his radius).
** then we get send a, b and c to the solving function to get `t` value
*/

double	intersect_cone(t_ray ray, t_object *obj)
{
	t_cone		*cone;
	t_vector	base;
	double		a;
	double		b;
	double		c;
	double		k;

	cone = &(obj->u_fig.cone);
	k = atan(cone->radius / cone->height);
	base = sub_vectors(ray.origin, cone->pos);
	a = dot_product(ray.dir, ray.dir) - (1 + k * k)
		* pow(dot_product(ray.dir, cone->dir), 2);
	b = 2 * (dot_product(ray.dir, base) - (1 + k * k)
			* (dot_product(ray.dir, cone->dir)
			* dot_product(base, cone->dir)));
	c = dot_product(base, base) - (1 + k * k)
		* pow(dot_product(base, cone->dir), 2);
	return (ft_solve(a, b, c));
}
