/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:45:22 by mpivet-p          #+#    #+#             */
/*   Updated: 2021/05/29 18:18:08 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define BUFF_SIZE 2000

typedef struct s_gnl
{
	char	buf[BUFF_SIZE + 1];
	int		fd;
	int		ret;
}				t_gnl;

int				get_next_line(const int fd, char **line);
#endif
