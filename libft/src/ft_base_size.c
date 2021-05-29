/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:53:37 by mpivet-p          #+#    #+#             */
/*   Updated: 2021/05/29 18:34:26 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_base_size(long long int nb, int base)
{
	int	size;

	size = 0;
	if (nb == 0)
		return (1);
	if (nb < 0 && base == 10)
		size++;
	while (nb != 0)
	{
		nb = nb / base;
		size++;
	}
	return (size);
}
