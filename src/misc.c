/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 04:13:20 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/22 05:20:28 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"

//TMP
#include <stdio.h>

t_vector	reflect(t_vector incident, t_vector normal)
{
	t_vector ret;

	ret = vector_mult(normal, dot_product(normal, incident) * 2.0);
	ret = sub_vectors(incident, ret);
	return (ret);
}

double	get_dist(t_vector *a, t_vector *b)
{
	double	ret;

	ret = pow(b->x - a->x, 2) + pow(b->y - a->y, 2) + pow(b->z - a->z, 2);
	return (sqrt(ret));
}

t_vector	bisector(t_vector a, t_vector b)
{
	t_vector ret;
	double norm;

	norm = sqrt(dot_product(a, a) + dot_product(b, b));
	ret = vector_div(add_vectors(a, b), norm);
	return (ret);
}
