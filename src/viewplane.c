/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewplane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 05:07:38 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/05 02:45:06 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtdata.h"
#include "rtv1.h"

void		get_viewplane(t_viewplane *vp, t_camera cam)
{
	t_vector	x;
	t_vector	y;
	t_vector	z;

	x = vector_mult(cam.vecdir, vp->dist);
	y = vector_mult(cam.upvec, vp->height / 2.0);
	z = vector_mult(cam.rightvec, vp->width / 2.0);
	vp->upleft = add_vectors(cam.pos, add_vectors(x, sub_vectors(y, z)));
}

t_vector	get_dir(t_viewplane vp, t_camera cam, t_ray ray, t_vector coords)
{
	t_vector	ret;
	t_vector	x;
	t_vector	y;

	x = vector_mult(cam.rightvec, coords.x);
	y = vector_mult(cam.upvec, coords.y);
	ret = add_vectors(vp.upleft, sub_vectors(x, y));
	ret = sub_vectors(ret, ray.origin);
	return (ret);
}

t_vector	get_indent(t_viewplane vp, t_vector coords)
{
	coords.x *= vp.width / (double)SIMG_X;
	coords.y *= vp.height / (double)SIMG_Y;
	return (coords);
}
