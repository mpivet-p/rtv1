/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:11:48 by mpivet-p          #+#    #+#             */
/*   Updated: 2021/05/29 20:08:08 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, char c)
{
	int	nb;

	nb = 0;
	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			nb++;
			while (*str != c && *str != '\0')
				str++;
		}
	}
	return (nb);
}

static int	ft_count_c(char const *str, char c)
{
	int	nb;

	nb = 0;
	while (*str != c && *str != '\0')
	{
		nb++;
		str++;
	}
	return (nb);
}

static void	*hack_norm(void **ptr, void *assign)
{
	*ptr = assign;
	return (*ptr);
}

char	**ft_strsplit(char const *s, char c)
{
	int		j;
	int		k;
	int		nb;
	char	**tab;

	j = 0;
	if (!s || !c)
		return (NULL);
	nb = ft_count_words(s, c);
	if (!hack_norm((void **)&tab, malloc(sizeof(char *) * (nb + 1))))
		return (NULL);
	while (j < nb)
	{
		k = 0;
		while (*s == c && *s != '\0')
			s++;
		if (!hack_norm((void **)&(tab[j]), malloc(sizeof(char)
					* (ft_count_c(s, c) + 1))))
			return (NULL);
		while (*s != '\0' && *s != c)
			tab[j][k++] = *(s++);
		tab[j++][k] = '\0';
	}
	tab[j] = 0;
	return (tab);
}
