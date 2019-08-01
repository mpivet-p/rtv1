#ifndef RTDATA_H
# define RTDATA_H
# define SWIN_X		1600
# define SWIN_Y		900
# define SIMG_X		1600
# define SIMG_Y		900
# define RT_WHITE	0xFFFFFF
# define RT_RED		0xFF0000
# define RT_GREEN	0x00FF00
# define RT_BLUE	0x0000FF
# define RT_YELLO	0xFFFF00
# define RT_CYAN	0x00FFFF
# define RT_PURPLE	0xFF00FF

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

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
	t_vector	origin;
	t_vector	dir;
	double		t;
}				t_ray;

typedef struct	s_camera
{
	t_vector	pos;
	t_vector	vecdir;
	t_vector	upvec;
	t_vector	rightvec;
}				t_camera;

#endif
