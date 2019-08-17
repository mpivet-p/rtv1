/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 04:13:20 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/17 05:18:53 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"

//TMP
#include <stdio.h>

void	rt_init(t_camera *cam, t_viewplane *vp)
{
	vp->width = SIMG_X;
	vp->height = SIMG_Y;
	vp->dist = 1000;
	cam->pos = init_vector(0, 0, 0);
	cam->vecdir = init_vector(0, 1, 0);
	cam->rightvec = init_vector(1, 0, 0);
	cam->upvec = init_vector(0, 0, 1);
}

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

t_vector	ray_to_point(t_ray *ray)
{
	t_vector	ret;

	ret = add_vectors(ray->origin, vector_mult(ray->dir, ray->t));
	return (ret);
}

void	disp_vec(t_vector *vec)
{
	printf("(%f, %f, %f)\n", vec->x, vec->y, vec->z);
}

t_vector	bisector(t_vector a, t_vector b)
{
	t_vector ret;
	double norm;

	norm = sqrt(dot_product(a, a) + dot_product(b, b));
	ret = vector_div(add_vectors(a, b), norm);
	return (ret);
}
