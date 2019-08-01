/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:55:16 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/01 03:00:43 by mpivet-p         ###   ########.fr       */
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
	double		size;
	t_vector sphere;
}				t_fmlx;


/*
**	======================== /(  )\ =========================
**	                         EVENTS
**	======================== \(  )/ =========================
*/

int				deal_key(int key, t_fmlx *mlx);
int				mouse_roll(int button, int x, int y, t_fmlx *mlx);
int				mouse_move(int x, int y, t_fmlx *mlx);

/*
**	========================== /( )\ ========================
**	                           TOOLS
**	========================== \( )/ ========================
*/

void			rtv_exit(t_fmlx *mlx);
void			fill_pxl(char *image, int x, int y, int color);

/*
**	========================== /( )\ ========================
**	                    VECTOR OPERATIONS
**	========================== \( )/ ========================
*/

t_vector	vector_sub(t_vector a, int nbr);
t_vector	vector_mult(t_vector a, int nbr);
t_vector	add_vectors(t_vector a, t_vector b);
t_vector	sub_vectors(t_vector a, t_vector b);
t_vector	init_vector(double x, double y, double z);
t_vector	dot_product(t_vector a, t_vector b);
void		get_viewplane(t_viewplane *vp, t_camera cam);
void		rt(t_fmlx *mlx);
double	ft_solve(double a, double b, double c);
double	solve_sphere(t_ray ray, t_vector sphere, double radius);
t_vector	get_dir(t_viewplane vp, t_camera cam, t_ray ray, t_point coords);
t_point		get_indent(t_viewplane vp, t_point coords);
t_point		init_point(double x, double y, double z);
void	rt_init(t_camera *cam, t_viewplane *vp);
int		rt_render(t_fmlx *mlx);

#endif
