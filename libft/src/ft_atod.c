/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:11:54 by wahasni           #+#    #+#             */
/*   Updated: 2021/02/14 15:36:27 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_atod(const char *str)
{
	int i;
	int sign;
	double result;
	double power;

	i = 0;
	power = 1;
	result = 0;
	sign = 1;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
				|| str[i] == '\v' || str[i] == ' ' || str[i] == '\f'))
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (sign == -1 || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		result = 10.0 * result + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = 10.0 * result + (str[i++] - '0');
		power *= 10.0;
	}
	return ((result / power) * sign);
}
