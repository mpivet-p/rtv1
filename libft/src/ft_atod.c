/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:11:54 by wahasni           #+#    #+#             */
/*   Updated: 2021/05/29 18:30:15 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	tern_hack(int cond, int a, int b)
{
	if (cond)
		return (a);
	return (b);
}

double	ft_atod(const char *str)
{
	double	result;
	double	power;
	int		sign;
	int		i;

	i = 0;
	power = 1;
	result = 0;
	sign = 1;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == ' ' || str[i] == '\f'))
		i++;
	sign = tern_hack((str[i] == '-'), -1, 1);
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
