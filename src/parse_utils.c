/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 23:32:33 by wahasni           #+#    #+#             */
/*   Updated: 2021/02/14 15:35:09 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include "rtdata.h"
#include <stdio.h>

int		ft_count_word(char *str, char c)
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

/*
**	printf("BEFORE : %d\n", obj->type);
**	printf("Maillon %d : color : %lf pos[x] : %lf type : %d\n", i, obj->color,
**	obj->u_fig.plane.pos.x, obj->type);
*/

void	ft_print_data(t_object *bip)
{
	t_object	*obj;
	int			i;

	i = 1;
	obj = bip;
	while (obj)
	{
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

int		ft_error(char *error)
{
	ft_putendl(error);
	return (1);
}
