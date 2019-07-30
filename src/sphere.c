/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 01:19:43 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/07/30 06:57:38 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

double	solve_sphere(t_ray ray, t_vector sphere, double radius)
{
	double	a;
	double	b;
	double	c;

	a = pow(ray.dir.x, 2) + pow(ray.dir.y, 2) + pow(ray.dir.z, 2);
	b = 2 * (ray.dir.x * (ray.origin.x - sphere.x)
			+ ray.dir.y * (ray.origin.y - sphere.y)
			+ ray.dir.z * (ray.origin.z - sphere.z));
	c = pow(ray.origin.x - sphere.x, 2)
			+ pow(ray.origin.y - sphere.y, 2)
			+ pow(ray.origin.z - sphere.z, 2)
			- pow(radius, 2);
	return (ft_solve(a, b, c));
}
