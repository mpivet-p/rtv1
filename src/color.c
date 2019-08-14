/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 23:35:01 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/14 03:33:38 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "rtv1.h"
#include "libft.h"

double	get_diffuse_color(t_ray *ray, t_vector *light_vec, t_vector *position)
{
	double		angle;

	angle = dot_product(
			get_normal(ray, *position), vector_mult(*light_vec, -1));
	if (angle > 0)
		return (angle);
	return (0);
}

double	get_ambient_color(void)
{
	return (0.1);
}

double	get_specular_color(t_ray *ray, t_vector *light_vec, t_vector *position)
{
	t_vector	reflect_dir;
	double	spec;

	reflect_dir = reflect(vector_mult(*light_vec, -1)
			, get_normal(ray, *position));
	spec = pow(ft_max(dot_product(ray->dir, reflect_dir), 0.0), 32);
	printf("%f\n", spec * 0.5);
	return (0.5 * spec);
}

double	is_lighted(t_vector *pos, t_vector *light_vec, t_vector *light_pos, t_object *obj)
{
	t_vector	nearest;
	t_ray		ray;

	ray.t = 0;
	ray.hit_by = NULL;
	ray.color = 0;
	ray.dir = normalize(vector_mult(*light_vec, -1));
	ray.origin = *pos;
	intersect(&ray, obj);
	if (ray.t > 0)
	{
		nearest = ray_to_point(&ray);
		if (get_dist(pos, light_pos) > get_dist(pos, &nearest))
			return (0);
		return (1);
	}
	return (1);
}

void	get_color(t_ray *ray, t_vector *light_pos, t_object *obj)
{
	t_vector	position;
	t_vector	light_vec;
	double		coeff;

	position = add_vectors(ray->origin, vector_mult(ray->dir, ray->t));
	position = add_vectors(position, vector_mult(get_normal(ray, position), 0.0000001));
	light_vec = normalize(sub_vectors(position, *light_pos));
 	coeff = get_ambient_color();
	if (is_lighted(&position, &light_vec, light_pos, obj) == 1)
		coeff += (get_diffuse_color(ray, &light_vec, &position) + get_specular_color(ray, &light_vec, &position));
	ray->color = mult_color(ray->hit_by->color, coeff);
}
