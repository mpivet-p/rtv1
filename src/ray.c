/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 05:11:17 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/22 05:25:25 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <strings.h>

void	reset_ray(t_ray *ray, t_fmlx *mlx, int x, int y)
{
	ray->hit_by = NULL;
	ray->t = 0;
	ray->color = 0;
	ray->dir = get_dir(mlx->vp, mlx->cam, *ray
			, get_indent(mlx->vp, init_vector(x, y, 0)));
}

t_vector	ray_to_point(t_ray *ray)
{
	t_vector	ret;

	ret = add_vectors(ray->origin, vector_mult(ray->dir, ray->t));
	return (ret);
}
