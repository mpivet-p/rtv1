/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 04:58:55 by mpivet-p          #+#    #+#             */
/*   Updated: 2021/03/24 14:32:30 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <strings.h>
#include <stdlib.h>
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
		next = obj->next;
		ft_bzero(obj, sizeof(obj));
		free(obj);
		obj = next;
	}
	bzero(mlx, sizeof(t_fmlx));
	while (1)
		;
}

void		ft_list_add_last(t_object **save, t_object *elem)
{
	t_object	*list;

	list = *save;
	while (list->next)
		list = list->next;
	list->next = elem;
	elem->prev = list;
}

t_object	*ft_create_list(void)
{
	t_object *list;

	if (!(list = ft_memalloc(sizeof(t_object))))
		return (NULL);
	return (list);
}

t_object	*ft_get_head_ref(t_object *obj)
{
	t_object	*head_ref;

	head_ref = (t_object *)obj;
	while (head_ref->prev)
		head_ref = head_ref->prev;
	return (head_ref);
}
