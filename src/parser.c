/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:10:34 by wahasni           #+#    #+#             */
/*   Updated: 2019/09/12 02:09:53 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "rtdata.h"
#include <fcntl.h>
#include "libft.h"

static int	ft_check_node(t_object *chill)
{
	t_object *obj;

	obj = chill;
	while (obj->prev)
		obj = obj->prev;
	while (obj->next)
	{
		if (obj->type == RT_CYL || obj->type == RT_CONE
				|| obj->type == RT_PLANE || obj->type == RT_SPHERE)
			return (0);
		obj = obj->next;
	}
	return (1);
}

static int	ft_handle_objs(t_object *obj, char *line, int fd)
{
	int error;

	if (ft_strnequ(line, "plane: ", 7))
		error = ft_parse_objs(obj, fd, RT_PLANE, line);
	else if (ft_strnequ(line, "sphere: ", 8))
		error = ft_parse_objs(obj, fd, RT_SPHERE, line);
	else if (ft_strnequ(line, "cylinder: ", 10))
		error = ft_parse_objs(obj, fd, RT_CYL, line);
	else if (ft_strnequ(line, "cone: ", 6))
		error = ft_parse_objs(obj, fd, RT_CONE, line);
	else if (ft_strnequ(line, "light: ", 7))
		error = ft_parse_objs(obj, fd, RT_LIGHT, line);
	else if (ft_check_node(obj))
	{
		ft_strdel(&line);
		return (ft_error("missing object"));
	}
	else
		return (free_last_node(ft_get_head_ref(obj)));
	if (error)
		free_line(line, 1);
	ft_strdel(&line);
	return (2);
}

int			parser(t_fmlx *rtv, char *file)
{
	int			fd;
	int			x;
	char		*line;
	t_object	*obj;
	int			i;

	i = 0;
	if ((fd = open(file, 0)) < 0)
		return (ft_error("Opening file failed."));
	rtv->obj = ft_create_list();
	obj = rtv->obj;
	while (get_next_line(fd, &line) >= 0)
	{
		if (i++)
		{
			ft_list_add_last(&rtv->obj, ft_create_list());
			while (obj->next)
				obj = obj->next;
		}
		x = ft_handle_objs(obj, line, fd);
		if (x != 2)
			return (x == 0) ? 0 : 1;
	}
	close(fd);
	return (0);
}
