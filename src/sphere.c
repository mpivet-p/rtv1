/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 01:19:43 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/02 05:12:01 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

double	solve_sphere(t_ray ray, t_vector sphere, double radius)
{
	double	a;
	double	b;
	double	c;

	a = (ray.dir.x * ray.dir.x) + (ray.dir.y * ray.dir.y) + (ray.dir.z * ray.dir.z);
	b = 2.0 * (ray.dir.x * (ray.origin.x - sphere.x)
			+ ray.dir.y * (ray.origin.y - sphere.y)
			+ ray.dir.z * (ray.origin.z - sphere.z));
	c = pow(ray.origin.x - sphere.x, 2)
			+ pow(ray.origin.y - sphere.y, 2)
			+ pow(ray.origin.z - sphere.z, 2)
			- (radius * radius);
	return (ft_solve(a, b, c));
}
