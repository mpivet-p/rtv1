/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 01:53:29 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/04 06:28:57 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rtv1.h"

/*
** REMOVE THIS FILE BEFORE FINAL PUSH
** Generating tests for the development phase
*/

t_object	*list_test(void)
{
	t_object	*ptr[5];
	int			i;

	i = 0;
	while (i < 5)
	{
		if (!(ptr[i] = (t_object*)malloc(sizeof(t_object) * 1)))
		{
			exit(1);
		}
		i++;
	}
	//Next pointers
	ptr[0]->next = ptr[1];
	ptr[1]->next = ptr[2];
	ptr[2]->next = ptr[3];
	ptr[3]->next = NULL;
//	ptr[3]->next = ptr[4];
//	ptr[4]->next = NULL;

	// Sphere 1
	ptr[0]->type = RT_SPHERE;
	ptr[0]->u_fig.sphere.pos = init_vector(-0.2, 1, 0);
	ptr[0]->u_fig.sphere.radius = 0.1;
	ptr[0]->color = RT_YELLO;
//	ptr[0]->color = 0xf54611;

	// Sphere 2
	ptr[1]->type = RT_SPHERE;
	ptr[1]->u_fig.sphere.pos = init_vector(-0.2, 1.1, 0);
	ptr[1]->u_fig.sphere.radius = 0.1;
	ptr[1]->color = 0xf5a511;

	// Plane 1
	ptr[2]->type = RT_PLANE;
	ptr[2]->u_fig.plane.pos = init_vector(0, 0, 0);
	ptr[2]->u_fig.plane.dir = init_vector(0, 0, 1);
	ptr[2]->color = 0x0589f5;

	// Cone 1
	ptr[3]->type = RT_CONE;
	ptr[3]->u_fig.cone.pos = init_vector(0, 1, 0.2);
	ptr[3]->u_fig.cone.dir = init_vector(0, 0, 1);
	ptr[3]->u_fig.cone.height = 3;
	ptr[3]->u_fig.cone.radius = 1;
	ptr[3]->color = RT_GREEN;

	// Cylinder 1
//	ptr[4]->type = RT_CYL;
//	ptr[4]->u_fig->cyl.pos = init_vector(-0.5, 1, 0);
//	ptr[4]->u_fig->cyl.dir = init_vector(0, 1, 1);
//	ptr[4]->u_fig->cyl.radius = 0.08;
//	ptr[4]->u_fig->cyl.color = RT_PURPLE;
	return (ptr[0]);
}
