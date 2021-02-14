/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_objs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:23:34 by wahasni           #+#    #+#             */
/*   Updated: 2019/09/12 02:12:10 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "rtdata.h"
#include "libft.h"

int		ft_parse_name(t_object *obj, char *line)
{
	if (ft_strlen(line) > 23)
		return (1);
	if (obj->type == RT_CYL)
		ft_strcat(obj->name, &line[10]);
	else if (obj->type == RT_CONE)
		ft_strcat(obj->name, &line[6]);
	else if (obj->type == RT_PLANE)
		ft_strcat(obj->name, &line[7]);
	else if (obj->type == RT_SPHERE)
		ft_strcat(obj->name, &line[8]);
	else if (obj->type == RT_LIGHT)
		ft_strcat(obj->name, &line[7]);
	return (0);
}

int		ft_parse_data(t_object *obj, int fd)
{
	if (obj->type == RT_CYL)
		return (ft_parse_cyl(obj, fd));
	else if (obj->type == RT_CONE)
		return (ft_parse_cone(obj, fd));
	else if (obj->type == RT_PLANE)
		return (ft_parse_plane(obj, fd));
	else if (obj->type == RT_SPHERE)
		return (ft_parse_sphere(obj, fd));
	else if (obj->type == RT_LIGHT)
		return (ft_parse_light(obj, fd));
	else
		return (1);
}

int		ft_parse_color(t_object *obj, int fd)
{
	char *line;

	if (get_next_line(fd, &line) <= 0)
		return (1);
	if (ft_strequ(line, "\tcolor : WHITE"))
		obj->color = RT_WHITE;
	else if (ft_strequ(line, "\tcolor : RED"))
		obj->color = RT_RED;
	else if (ft_strequ(line, "\tcolor : GREEN"))
		obj->color = RT_GREEN;
	else if (ft_strequ(line, "\tcolor : YELLOW"))
		obj->color = RT_YELLO;
	else if (ft_strequ(line, "\tcolor : PURPLE"))
		obj->color = RT_PURPLE;
	else if (ft_strequ(line, "\tcolor : BLUE"))
		obj->color = RT_BLUE;
	else
		return (free_line(line, 1));
	return (free_line(line, 0));
}

int		ft_parse_bracket(int fd, int i)
{
	char *line;

	if (get_next_line(fd, &line) <= 0)
		return (1);
	if (i == 0)
	{
		if (!ft_strequ(line, "{"))
			return (free_line(line, 1));
	}
	else
	{
		if (!ft_strequ(line, "}"))
			return (free_line(line, 1));
	}
	return (free_line(line, 0));
}

int		ft_parse_objs(t_object *obj, int fd, int type, char *name)
{
	int	i;

	i = 0;
	obj->type = type;
	if (ft_parse_name(obj, name))
		return (ft_error("False name"));
	if (ft_parse_bracket(fd, 0))
		return (ft_error("Not a bracket"));
	if (ft_parse_color(obj, fd))
		return (ft_error("Bad color"));
	if (ft_parse_data(obj, fd))
		return (ft_error("Bad data"));
	if (ft_parse_bracket(fd, 1))
		return (ft_error("Not a last bracket"));
	return (0);
}
