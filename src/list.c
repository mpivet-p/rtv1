/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 04:58:55 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/22 05:29:05 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <strings.h>
#include <stdlib.h>
//DELETE
#include <stdio.h>

t_object	*get_prevlink(t_fmlx *mlx)
{
	t_object	*obj;

	obj = mlx->obj;
	if (mlx->current->prev != NULL)
		return (mlx->current->prev);
	while (obj && obj->next)
		obj = obj->next;
	return (obj);
}

void		rt_delist(t_fmlx *mlx)
{
	t_object	*obj;
	t_object	*next;

	obj = mlx->obj;
	mlx->obj = NULL;
	mlx->current = NULL;
	next = obj;
	while (next)
	{
		printf("%s %p\n", obj->name, obj);
		next = obj->next;
		ft_bzero(obj, sizeof(obj));
		free(obj);
		printf("%p\n", obj);
		obj = next;
	}
	while (1)
		;
}
