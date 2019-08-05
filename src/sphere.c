/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 01:19:43 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/05 07:35:14 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"

double	intersect_sphere(t_ray ray, t_object *obj)
{
	t_sphere *sphere;
	t_vector	base;
	double		a;
	double		b;
	double		c;

	sphere = &(obj->u_fig.sphere);
	base = sub_vectors(ray.origin, sphere->pos);
	a = dot_product(ray.dir, ray.dir);
	b = 2.0 * dot_product(ray.dir, base);
	c = dot_product(base, base) - pow(sphere->radius, 2);
	return (ft_solve(a, b, c));
}

t_vector normal_sphere(t_ray *ray, t_vector position)
{
	t_sphere	*sphere;
	t_vector	ret;

	sphere = &(ray->hit_by->u_fig.sphere);
	ret = normalize(sub_vectors(position, sphere->pos));
	return (ret);
}
