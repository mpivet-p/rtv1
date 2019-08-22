/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 01:53:29 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/22 05:24:01 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "rtv1.h"
#include "libft.h"

/*
** REMOVE THIS FILE BEFORE FINAL PUSH
** Generating tests for the development phase
*/

void	disp_vec(t_vector *vec)
{
	printf("(%f, %f, %f)\n", vec->x, vec->y, vec->z);
}

t_object	*list_test(void)
{
	t_object	*ptr[8];
	int			i;

	i = 0;
	while (i < 8)
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
	ptr[3]->next = ptr[4];
	ptr[4]->next = ptr[5];
	ptr[5]->next = NULL;
	ptr[0]->prev = NULL;
	ptr[1]->prev = ptr[0];
	ptr[2]->prev = ptr[1];
	ptr[3]->prev = ptr[2];
	ptr[4]->prev = ptr[3];
	ptr[5]->prev = ptr[4];
//	ptr[5]->next = ptr[6];
//	ptr[6]->next = ptr[7];
//	ptr[7]->next = NULL;

  // Sphere 1
	ft_bzero(ptr[0]->name, 17);
	ft_strcat(ptr[0]->name, "premiere sphere");
	ptr[0]->type = RT_SPHERE;
	ptr[0]->u_fig.sphere.pos = init_vector(-0.2, 1, 0);
	ptr[0]->u_fig.sphere.radius = 0.1;
	ptr[0]->color = RT_RED;

  // Sphere 2
	ft_bzero(ptr[1]->name, 17);
	ft_strcat(ptr[1]->name, "la deuxieme");
	ptr[1]->type = RT_SPHERE;
	ptr[1]->u_fig.sphere.pos = init_vector(-0.2, 1.1, 0.2);
	ptr[1]->u_fig.sphere.radius = 0.1;
	ptr[1]->color = RT_YELLO;

  // Plane 1
	ft_bzero(ptr[2]->name, 17);
	ft_strcat(ptr[2]->name, "le plan");
	ptr[2]->type = RT_PLANE;
	ptr[2]->u_fig.plane.pos = init_vector(0, 0, -0.2);
	ptr[2]->u_fig.plane.dir = normalize(init_vector(0, 0, 1));
	ptr[2]->color = RT_BLUE;

  // Cone 1
	ft_bzero(ptr[3]->name, 17);
	ft_strcat(ptr[3]->name, "cone1");
	ptr[3]->type = RT_CONE;
	ptr[3]->u_fig.cone.pos = init_vector(0, 1, 0.2);
	ptr[3]->u_fig.cone.dir = normalize(init_vector(0, 0, 1));
	ptr[3]->u_fig.cone.height = 3;
	ptr[3]->u_fig.cone.radius = 1;
	ptr[3]->color = RT_GREEN;

	// Cylinder 1
	ft_bzero(ptr[4]->name, 17);
	ft_strcat(ptr[4]->name, "tube");
	ptr[4]->type = RT_CYL;
	ptr[4]->u_fig.cyl.pos = init_vector(0.5, 1, 0);
	ptr[4]->u_fig.cyl.dir = normalize(init_vector(0, 0, 1));
	ptr[4]->u_fig.cyl.radius = 0.1;
	ptr[4]->color = RT_PURPLE;

  // Light 1
	ft_bzero(ptr[5]->name, 17);
	ft_strcat(ptr[5]->name, "luuuummiiieeerrre");
	ptr[5]->type = RT_LIGHT;
	ptr[5]->u_fig.light.pos = init_vector(-0.5, 0.8, 0.2);

//  // Light 2
//	ptr[6]->type = RT_LIGHT;
//	ptr[6]->u_fig.light.pos = init_vector(0.3, 0.4, 2);
//
//  // Light 3
//	ptr[7]->type = RT_LIGHT;
//	ptr[7]->u_fig.light.pos = init_vector(-0.2, 1.1, 0.6);
	return (ptr[0]);
}
