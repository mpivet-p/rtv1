/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 01:01:34 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/02 05:14:44 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	ft_solve(double a, double b, double c)
{
	double	ret;
	double	det;
	double	t1;
	double	t2;

	t1 = 0;
	t2 = 0;
	ret = 0;
	det = pow(b, 2) - (4 * a * c);
	if (det < 0)
		return (-1);
	if (det == 0)
	{
		ret = -(b / (2 * a));
		return ((ret > 0.0) ? ret : -1);
	}
	t1 = (-b + sqrt(det)) / (2 * a);
	t2 = (-b - sqrt(det)) / (2 * a);
	if (t2 > 0.0 && t1 > 0.0)
		return ((t1 < t2) ? t1 : t2);
	if (t1 > 0.0 || t2 > 0.0)
		return ((t1 > t2) ? t1 : t2);
	return (-1);
}
