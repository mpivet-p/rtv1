/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 04:59:07 by mpivet-p          #+#    #+#             */
/*   Updated: 2021/05/29 18:11:54 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"

double	intersect_cylinder(t_ray ray, t_object *obj)
{
	t_cylinder	*cyl;
	t_vector	base;
	double		a;
	double		b;
	double		c;

	cyl = &(obj->u_fig.cyl);
	base = sub_vectors(ray.origin, cyl->pos);
	a = dot_product(ray.dir, ray.dir)
		- pow(dot_product(ray.dir, cyl->dir), 2);
	b = 2.0 * (dot_product(ray.dir, base)
			- (dot_product(ray.dir, cyl->dir)
				* dot_product(base, cyl->dir)));
	c = dot_product(base, base)
		- pow(dot_product(base, cyl->dir), 2)
		- pow(cyl->radius, 2);
	return (ft_solve(a, b, c));
}

t_vector	normal_cylinder(t_ray *ray, t_vector position)
{
	t_cylinder	*cyl;
	t_vector	ret;
	double		m;

	cyl = &(ray->hit_by->u_fig.cyl);
	m = dot_product(ray->dir, cyl->dir) * ray->t
		+ dot_product(sub_vectors(ray->origin, cyl->pos), cyl->dir);
	ret = normalize(sub_vectors(sub_vectors(position, cyl->pos),
				vector_mult(cyl->dir, m)));
	if (dot_product(ray->dir, ret) > 0.0001)
		ret = vector_mult(ret, -1);
	return (ret);
}
