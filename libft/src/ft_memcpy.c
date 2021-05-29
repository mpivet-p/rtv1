/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:17:25 by mpivet-p          #+#    #+#             */
/*   Updated: 2021/05/29 18:57:03 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*str;
	char	*dest;
	int		i;

	i = 0;
	str = (char *)src;
	dest = (char *)dst;
	while (n)
	{
		dest[i] = str[i];
		n--;
		i++;
	}
	return (dst);
}
