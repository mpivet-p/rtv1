/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewplane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 05:07:38 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/07/29 07:51:33 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtdata.h"
#include "rtv1.h"

void	get_viewplane(t_viewplane *vp, t_camera cam)
{
	t_vector	x;
	t_vector	y;
	t_vector	z;

	x = vector_mult(cam.vecdir, vp->dist);
	y = vector_mult(cam.upvec, vp->height);
	z = vector_mult(cam.rightvec, vp->width);
	vp->upleft = add_vectors(cam.pos, add_vectors(x, sub_vectors(y, z)));
}

t_vector	get_dir(t_viewplane vp, t_camera cam, t_point indent, t_point coords)
{
	t_vector	ret;
	t_vector	x;
	t_vector	y;

	x = vector_mult(cam.rightvec, indent.x * coords.x);
	y = vector_mult(cam.upvec, indent.y * coords.y);
	ret = add_vectors(vp.upleft, sub_vectors(x, y));
	return (ret);
}

t_point	get_indent(t_viewplane vp)
{
	t_point		indent;

	indent.x = vp.width / (double)SIMG_X;
	indent.y = vp.height / (double)SIMG_Y;

	return (indent);
}
