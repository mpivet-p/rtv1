/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 23:32:33 by wahasni           #+#    #+#             */
/*   Updated: 2021/03/31 13:32:01 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include "rtdata.h"
#include <stdio.h>

int	ft_count_word(char *str, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i])
	{
		if (str[i] == c)
			w++;
		i++;
	}
	return (w);
}

void	ft_print_data(t_object *obj)
{
	int	i;

	i = 1;
	printf("BEFORE\n");
	while (obj)
	{
		printf("Maillon %d :", i);
		printf("color : %lf ", obj->color);
		printf("x : %lf ", obj->u_fig.plane.pos.x);
		printf("y : %lf ", obj->u_fig.plane.pos.y);
		printf("z : %lf ", obj->u_fig.plane.pos.z);
		printf("type : %d\n", obj->type);
		i++;
		obj = obj->next;
	}
}

char	ft_last_word(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1])
		i++;
	return (str[i]);
}

int	ft_error(char *error)
{
	ft_putendl(error);
	return (1);
}
