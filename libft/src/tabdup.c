/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 02:54:19 by mpivet-p          #+#    #+#             */
/*   Updated: 2021/05/29 19:40:27 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**tabdup(char **table, char ***new_tab, int addlines)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (table && table[len] != 0)
		len++;
	len += addlines;
	*new_tab = (char **)malloc(sizeof(char *) * (len + 1));
	if (!(*new_tab))
		return (NULL);
	while (i < len)
	{
		if (table && table[i] != 0)
			(*new_tab)[i] = ft_strdup(table[i]);
		else
			(*new_tab)[i] = 0;
		i++;
		(*new_tab)[i] = 0;
	}
	return (*new_tab);
}
