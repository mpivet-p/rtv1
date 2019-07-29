/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 01:19:43 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/07/29 02:42:40 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		get_a(t_vector dir)
{
	return (pow(dir.x, 2) + pow(dir.y, 2) + pow(dir.z, 2));
}

double		get_b(t_vector dir, t_vector origin, t_vector circle)
{
	return (2 * (dir.x * (origin.x - circle.x)
				+ dir.y * (origin.y - circle.y)
				+ dir.z * (origin.z - circle.z)));
}

c = ((O.x - Xc)^2 + (O.y - Yc)^2 + (O.z - Zc)^2) - r^2

double		get_c(t_vector dir, t_vector origin, t_vector circle, double radius)
{
	return (pow(origin.x - circle.x, 2)
			+ pow(origin.y - circle.y, 2)
			+ pow(origin.z - circle.z, 2)
			- pow(radius, 2));
}
