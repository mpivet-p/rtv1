/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:50:17 by wahasni           #+#    #+#             */
/*   Updated: 2021/02/21 17:05:27 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "rtdata.h"
#include "libft.h"

#include <stdio.h>

int	ft_parse_light(t_object *obj, int fd)
{
	char	*line;
	int		ret;

	ret = 1;
	if (get_next_line(fd, &line) < 0)
		return (1);
	if (ft_strnequ(line, "\tpos(", 5))
	{
		ft_assign_pos(obj, &line[5]);
		ret = 0;
	}
	ft_strdel(&line);
	//Test lecture 1 ligne en plus ( "}" en theorie)
//	get_next_line(fd, &line);
//	printf("line = %s\n", line);
//	ft_strdel(&line);

	return (ret);
}
