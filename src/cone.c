/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 03:50:53 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/03 08:34:24 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

double	solve_cone(t_ray ray, t_cone cone)
{
	t_vector	base;
	double		a;
	double		b;
	double		c;
	double		k;

	k = atan(cone.radius / cone.height);
	base = sub_vectors(ray.origin, cone.pos);
	a = dot_product(ray.dir, cone.dir)
		- (1 + k * k) * pow(dot_product(ray.dir, cone.dir), 2);
	b = dot_product(ray.dir, cone.dir)
		- (1 + k * k)
			* (dot_product(ray.dir, cone.dir)
			* dot_product(base, cone.dir));
	c = dot_product(base, base) - (1 + k * k)
		* pow(dot_product(base, cone.dir), 2);
	return (ft_solve(a, b, c));
}
