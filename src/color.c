/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 23:35:01 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/13 03:43:17 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "rtv1.h"
#include "libft.h"

double	get_diffuse_color(t_ray *ray, t_vector *light_vec, t_vector *position)
{
	double		angle;

	angle = dot_product(get_normal(ray, *position)								//Produit scalaire de la normale de l'objet au rayon par l'inverse du rayon lumineux = angle
			, vector_mult(*light_vec, -1));
	if (angle > 0)
		return (angle);
	return (0);
}

double	get_ambient_color(void)
{
	return (0.1);																//Ambient light color coeff
}

double	get_specular_color(t_ray *ray, t_vector *light_vec, t_vector *position) //Ne fonctionne pas :/
{
	t_vector	reflect_dir;
	double	spec;

	reflect_dir = reflect(vector_mult(*light_vec, -1)
			, get_normal(ray, *position));
	spec = pow(ft_max(dot_product(ray->dir, reflect_dir), 0.0), 32);
	return (0.5 * spec * 1);
}

double	is_lighted(t_vector *pos, t_vector *light_vec, t_vector *light_pos, t_object *obj, t_object *ignore, int x, int y)
{
	t_vector	nearest;
	double		biais;
	t_ray		ray;

	ray.t = 0;
	ray.hit_by = NULL;
	ray.color = 0;
	ray.dir = normalize(vector_mult(*light_vec, -1));
	ray.origin = vector_add(*pos, 0.0000001);
	biais = 0;
	intersect(&ray, obj, ignore);
	if (ray.hit_by != NULL)
	{
		biais = 0.001;
	}
	(void)x;
	(void)y;
//	if (x == 721 && y > 650 && y < 660)
//		printf("x %i   y %i    %f   (%f, %f, %f) %i\n", x, y, ray.t, ray.dir.x, ray.dir.y, ray.dir.z, ray.hit_by->type);
	if (ray.t > biais)
	{
		nearest = ray_to_point(&ray);
		if (get_dist(pos, light_pos) > get_dist(pos, &nearest))
			return (0);
		return (1);
	}
	return (1);
}

void	get_color(t_ray *ray, t_vector *light_pos, t_object *obj, int x, int y)
{
	t_vector	position;
	t_vector	light_vec;
	double		coeff;

	position = add_vectors(ray->origin, vector_mult(ray->dir, ray->t));			//position de contact du rayon
	light_vec = normalize(sub_vectors(position, *light_pos));					//Vecteur directeur (unitaire) du rayon qui va vers la lumiere nrm(position - pos_light)
	coeff = get_ambient_color()													//Addition des multiplicateurs de lumieres
		+ (get_diffuse_color(ray, &light_vec, &position)
				* is_lighted(&position, &light_vec, light_pos, obj, ray->hit_by, x, y));
	//+ get_specular_color(ray, &light_vec, &position);
	ray->color = mult_color(ray->hit_by->color, coeff);							//multiplication de la lumiere
//	if (x == 721 && y > 650 && y < 660)
//	{
//		printf("x %i   y %i    %x %x %x\n", x, y, (ray->color >> 16) & 0xFF, (ray->color >> 8) & 0xFF, (ray->color) & 0xFF);
//		ray->color = RT_WHITE;
//	}
}
