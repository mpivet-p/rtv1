/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtdata.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 01:19:54 by mpivet-p          #+#    #+#             */
/*   Updated: 2019/08/22 01:42:52 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTDATA_H
# define RTDATA_H
# define SWIN_X		1600
# define SWIN_Y		940
# define SIMG_X		1600
# define SIMG_Y		900
# define SUI_X		1600
# define SUI_Y		40
# define AMBIENT_STRENGTH 0.075
# define RT_WHITE	0xFFFFFF
# define RT_RED		0xF54611
# define RT_GREEN	0x2CA338
# define RT_BLUE	0x0589F5
# define RT_YELLO	0xF5A511
# define RT_PURPLE	0xC017E6
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_RIGHT	124
# define KEY_LEFT	123
# define KEY_W		13
# define KEY_S		1
# define KEY_A		0
# define KEY_D		2
# define KEY_Q		12
# define KEY_E		14
# define KEY_ESC	53
# define KEY_SPA	49
# define KEY_SPA	49
# define KEY_PGUP	116
# define KEY_PGDWN	121
# define KEY_LESS	69
# define KEY_PLUS	78

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

/*
** ============================================================================
** FIGURES.....................................................................
** ============================================================================
*/

typedef struct	s_sphere
{
	t_vector	pos;
	double		radius;
}				t_sphere;

typedef struct	s_plane
{
	t_vector	pos;
	t_vector	dir;
}				t_plane;

typedef struct	s_cylinder
{
	t_vector	pos;
	t_vector	dir;
	double		radius;
}				t_cylinder;

typedef struct	s_cone
{
	t_vector	pos;
	t_vector	dir;
	double		radius;
	double		height;
}				t_cone;

typedef struct	s_light
{
	t_vector	pos;
	t_vector	dir;
}				t_light;

typedef struct	s_camera
{
	t_vector	pos;
	t_vector	vecdir;
	t_vector	upvec;
	t_vector	rightvec;
}				t_camera;

/*
** ============================================================================
** OBJECT LINKED LIST..........................................................
** ============================================================================
*/

typedef union	u_fig
{
	t_plane		plane;
	t_sphere	sphere;
	t_cylinder	cyl;
	t_cone		cone;
	t_light		light;
	t_camera	cam;
}				t_fig;

typedef struct	s_object
{
	double			color;
	char			name[17];
	int				type;
	t_fig			u_fig;
	struct s_object	*next;
	struct s_object	*prev;
}				t_object;

/*
** ============================================================================
** MISC........................................................................
** ============================================================================
*/


enum	e_objs
{
	RT_CYL, RT_CONE, RT_PLANE, RT_SPHERE, RT_LIGHT, RT_CAM, RT_NUM
};

typedef struct	s_point
{
	double	x;
	double	y;
	double	z;
}				t_point;

typedef struct	s_viewplane
{
	t_vector	upleft;
	double		dist;
	double		height;
	double		width;
}				t_viewplane;

typedef struct	s_ray
{
	t_object	*hit_by;
	t_vector	origin;
	t_vector	dir;
	double		t;
	int			color;
}				t_ray;
#endif
