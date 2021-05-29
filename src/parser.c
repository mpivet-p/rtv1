/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:10:34 by wahasni           #+#    #+#             */
/*   Updated: 2021/03/31 14:14:48 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "rtdata.h"
#include <fcntl.h>
#include "libft.h"

static int	ft_check_node(t_object *chill)
{
	t_object	*obj;

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
	int	error;

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
		return (ft_error("missing object"));
	else
		return (free_last_node(ft_get_head_ref(obj)));
	return ((error == 0) ? 0 : 2);
}

int	parser(t_fmlx *rtv, char *file)
{
	int			fd;
	int			x;
	char		*line;
	t_object	*obj;
	int			i;

	i = 0;
	x = 0;
	if ((fd = open(file, 0)) < 0)
		return (ft_error("Opening file failed."));
	rtv->obj = ft_create_list();
	obj = rtv->obj;
	while (x == 0 && get_next_line(fd, &line) >= 0)
	{
		if (i++)
		{
			ft_list_add_last(rtv->obj, ft_create_list());
			if ((obj = obj->next) == NULL)
				return (1);
		}
		x = ft_handle_objs(obj, line, fd);
		ft_strdel(&line);
	}
	close(fd);
	return ((x == 2) ? 2 : 0);
}
