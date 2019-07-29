/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 04:19:01 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/07/29 07:49:08 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtdata.h"

t_vector	vector_add(t_vector a, int nbr)
{
	t_vector	ret;

	ret.x = a.x + nbr;
	ret.y = a.y + nbr;
	ret.z = a.z + nbr;
	return (ret);
}

t_vector	vector_sub(t_vector a, int nbr)
{
	t_vector	ret;

	ret.x = a.x - nbr;
	ret.y = a.y - nbr;
	ret.z = a.z - nbr;
	return (ret);
}

t_vector	vector_mult(t_vector a, int nbr)
{
	t_vector	ret;

	ret.x = a.x * nbr;
	ret.y = a.y * nbr;
	ret.z = a.z * nbr;
	return (ret);
}

t_vector	add_vectors(t_vector a, t_vector b)
{
	t_vector	ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;
	return (ret);
}

t_vector	sub_vectors(t_vector a, t_vector b)
{
	t_vector	ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;
	return (ret);
}

t_vector	init_vector(double x, double y, double z)
{
	t_vector	vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;
	return (vect);
}
