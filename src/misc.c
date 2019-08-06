/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 04:13:20 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/06 12:45:23 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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

	ret = vector_mult(vector_mult(normal, dot_product(normal, incident)), 2.0);
	ret = sub_vectors(incident, ret);
	return (ret);
}
