/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 23:35:01 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/09 01:54:39 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
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

void	get_color(t_ray *ray, t_vector *light_pos)
{
	t_vector	position;
	t_vector	light_vec;
	double		coeff;

 	position = add_vectors(ray->origin, vector_mult(ray->dir, ray->t));			//position de contact du rayon
 	light_vec = normalize(sub_vectors(position, *light_pos));					//Vecteur directeur (unitaire) du rayon qui va vers la lumiere nrm(position - pos_light)
	coeff = get_ambient_color()													//Addition des multiplicateurs de lumieres
		+ get_diffuse_color(ray, &light_vec, &position)
		;//+ get_specular_color(ray, &light_vec, &position);
	ray->color = mult_color(ray->hit_by->color, coeff);							//multiplication de la lumiere
}

double	is_lighted(t_vector light_vec, t_object *obj)
{
	t_ray	ray;

	ray.t = 0;
	ray.hit_by = NULL;
	ray.color = 0;
	ray.dir = vector_mult(light_vec, -1);
	intersect(&ray, obj);
	if (ray.t > 0)
	{
		//IF DIST > LIGHT   ==> disp color   ELSE DISP SHADOW
	}
	return (0);
}
