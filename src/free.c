/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 04:05:32 by wahasni           #+#    #+#             */
/*   Updated: 2021/05/30 17:57:20 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>
#include <rtdata.h>
#include "libft.h"

void	ft_delete_list(t_object **head_ref)
{
	t_object	*current;
	t_object	*next;

	current = *head_ref;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head_ref = (t_object *)0;
}

int	free_last_node(t_object *head)
{
	t_object	*second_last;

	if (!head)
		return (1);
	if (!head->next)
	{
		free(head);
		return (1);
	}
	second_last = head;
	while (second_last->next->next)
		second_last = second_last->next;
	free(second_last->next);
	second_last->next = ((void *)0);
	return (1);
}

int	free_line(char *line, int i)
{
	if (line)
		ft_strdel(&line);
	return (i);
}
