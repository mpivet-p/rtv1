/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:55:16 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/22 05:26:05 by mpivet-p         ###   ########.fr       */
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
	void		*ui;
	char		*ui_img;
	int			intensity;
	t_viewplane	vp;
	t_camera	cam;
	t_object	*obj;
	t_object	*current;
}				t_fmlx;

/*
** ============================================================================
**	EVENTS.....................................................................
** ============================================================================
*/

int				mouse_press(int button, int x, int y, t_fmlx *mlx);
int				mouse_move(int x, int y, t_fmlx *mlx);
int				deal_key(int key, t_fmlx *mlx);

/*
** ============================================================================
**	TOOLS......................................................................
** ============================================================================
*/

t_vector		reflect(t_vector incident, t_vector normal);
void			fill_img(char *image, int x, int y, t_vector color);
void			rtv_exit(t_fmlx *mlx);
double			get_dist(t_vector *a, t_vector *b);
t_vector		ray_to_point(t_ray *ray);

/*
** ============================================================================
**	INTERSECTIONS..............................................................
** ============================================================================
*/

void			get_intersection(t_ray *ray, t_object *obj);
double			intersect_sphere(t_ray ray, t_object *obj);
double			intersect_plane(t_ray ray, t_object *obj);
double			intersect_cylinder(t_ray ray, t_object *obj);
double			intersect_cone(t_ray ray, t_object *obj);

/*
** ============================================================================
**	SHAPES NORMALS.............................................................
** ============================================================================
*/

t_vector 		normal_sphere(t_ray *ray, t_vector position);
t_vector 		normal_plane(t_ray *ray, t_vector position);
t_vector 		normal_cylinder(t_ray *ray, t_vector position);
t_vector 		normal_cone(t_ray *ray, t_vector position);

/*
** ============================================================================
**	COLOR TOOLS................................................................
** ============================================================================
*/

t_vector		get_color(t_ray *ray, t_object *obj, t_object *obj_lights);

/*
** ============================================================================
**	VECTOR OPERATIONS..........................................................
** ============================================================================
*/

t_vector		init_vector(double x, double y, double z);
t_vector		vector_mult(t_vector a, double nbr);
t_vector		vector_add(t_vector a, double nbr);
t_vector		add_vectors(t_vector a, t_vector b);
t_vector		sub_vectors(t_vector a, t_vector b);
t_vector		vector_sub(t_vector a, double nbr);
t_vector		bisector(t_vector a, t_vector b);
t_vector		vector_div(t_vector a, double nbr);
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
double			norm_vector(t_vector vector);
t_vector		normalize(t_vector vector);
t_vector		get_normal(t_ray *ray, t_vector position);
void			rt_init(t_camera *cam, t_viewplane *vp);
void			reset_ray(t_ray *ray, t_fmlx *mlx, int x, int y);
t_vector		mult_color(int color, t_vector mult);
void			init_ui(t_fmlx *mlx);
void			disp_ui(t_fmlx *mlx);
void			object_translate(t_vector *pos, int key, int modif);
void			object_rotate(t_vector *pos, int key, int modif);
t_object		*get_prevlink(t_fmlx *mlx);
void			rt_delist(t_fmlx *mlx);
//TMP
void			disp_vec(t_vector *vec);

//TESTS
t_object	*list_test(void);

#endif
