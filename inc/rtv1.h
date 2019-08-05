/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:55:16 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/05 05:21:49 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
#include "rtdata.h"

typedef struct	s_fmlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*screen;
	t_viewplane	vp;
	t_camera	cam;
	t_object	*obj;
}				t_fmlx;

/*
** ============================================================================
**	EVENTS.....................................................................
** ============================================================================
*/

int				mouse_roll(int button, int x, int y, t_fmlx *mlx);
int				mouse_move(int x, int y, t_fmlx *mlx);
int				deal_key(int key, t_fmlx *mlx);

/*
** ============================================================================
**	TOOLS......................................................................
** ============================================================================
*/

void			fill_pxl(char *image, int x, int y, int color);
void			rtv_exit(t_fmlx *mlx);

/*
** ============================================================================
**	INTERSECTIONS..............................................................
** ============================================================================
*/

double			intersect_sphere(t_ray ray, t_object *obj);
double			intersect_plane(t_ray ray, t_object *obj);
double			intersect_cylinder(t_ray ray, t_object *obj);
double			intersect_cone(t_ray ray, t_object *obj);

/*
** ============================================================================
**	SHAPES NORMALS.............................................................
** ============================================================================
*/

t_vector normal_sphere(t_ray *ray, t_vector position);
t_vector normal_plane(t_ray *ray, t_vector position);
t_vector normal_cylinder(t_ray *ray, t_vector position);
t_vector normal_cone(t_ray *ray, t_vector position);

/*
** ============================================================================
**	VECTOR OPERATIONS..........................................................
** ============================================================================
*/

t_vector		init_vector(double x, double y, double z);
t_vector		vector_mult(t_vector a, double nbr);
t_vector		add_vectors(t_vector a, t_vector b);
t_vector		sub_vectors(t_vector a, t_vector b);
t_vector		vector_sub(t_vector a, double nbr);
double			dot_product(t_vector a, t_vector b);

/*
** ============================================================================
**	MISC / TOOLS................................................................
** ============================================================================
*/

t_vector		get_dir(t_viewplane vp, t_camera cam, t_ray ray, t_vector coords);
t_vector		get_indent(t_viewplane vp, t_vector coords);
t_vector		init_vector(double x, double y, double z);
double			ft_solve(double a, double b, double c);
void			get_viewplane(t_viewplane *vp, t_camera cam);
void			rt_init(t_camera *cam, t_viewplane *vp);
void			rt(t_fmlx *mlx);
int				rt_render(t_fmlx *mlx);

//TESTS
t_object	*list_test(void);

#endif
