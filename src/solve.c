/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 01:01:34 by mpivet-p          #+#    #+#             */
/*   Updated: 2021/05/31 18:38:11 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

double	hack_norm(int cond, double a, double b)
{
	if (cond)
		return (a);
	return (b);
}

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
		ret = -(b / anti_zero(2 * a));
		return (hack_norm((ret > 0.0), ret, -1));
	}
	if (a == 0.0)
		a = 0.000001;
	t1 = (-b + sqrt(det)) / (2 * a);
	t2 = (-b - sqrt(det)) / (2 * a);
	if (t2 > 0.0 && t1 > 0.0)
		return (hack_norm((t1 < t2), t1, t2));
	if (t1 > 0.0 || t2 > 0.0)
		return (hack_norm((t1 > t2), t1, t2));
	return (-1);
}
