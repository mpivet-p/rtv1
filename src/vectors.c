/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 07:48:06 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/01 04:37:36 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtdata.h"

t_vector	vector_add(t_vector a, double nbr)
{
	t_vector	ret;

	ret.x = a.x + nbr;
	ret.y = a.y + nbr;
	ret.z = a.z + nbr;
	return (ret);
}

t_vector	vector_sub(t_vector a, double nbr)
{
	t_vector	ret;

	ret.x = a.x - nbr;
	ret.y = a.y - nbr;
	ret.z = a.z - nbr;
	return (ret);
}

t_vector	vector_mult(t_vector a, double nbr)
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
