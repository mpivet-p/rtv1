#ifndef RTDATA_H
# define RTDATA_H
# define SWIN_X 1600
# define SWIN_Y 900
# define SIMG_X 1600
# define SIMG_Y 900

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

typedef struct	s_camera
{
	t_vector	pos;
	t_vector	vecdir;
	t_vector	upvec;
	t_vector	rightvec;
}				t_camera;

#endif
