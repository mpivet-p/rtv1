/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 04:59:07 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/03 07:34:00 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"

double	solve_cylinder(t_ray ray, t_cylinder cyl)
{
	t_vector	base;
	double		a;
	double		b;
	double		c;

	cyl.pos = init_vector(0.6, 1, 0);
	cyl.dir = init_vector(1, 0, 1);
	base = sub_vectors(ray.origin, cyl.pos);
	a = dot_product(ray.dir, ray.dir) - pow(dot_product(ray.dir, cyl.dir), 2);
	b = 2.0 * ((dot_product(ray.dir, base))
				- (dot_product(ray.dir, cyl.dir)
				* dot_product(base, cyl.dir)));
	c = dot_product(base, base) - pow(dot_product(base, cyl.dir), 2) - pow(cyl.radius, 2);
	return (ft_solve(a, b, c));
}
