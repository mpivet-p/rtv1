/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_assign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:14:20 by wahasni           #+#    #+#             */
/*   Updated: 2019/09/05 04:20:37 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "rtdata.h"
#include "libft.h"

void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	ft_assign_dir(t_object *obj, char *str)
{
	char	**tab;

	tab = ft_strsplit(str, ',');
	if (obj->type == RT_PLANE)
	{
		obj->u_fig.plane.dir.x = ft_atod(tab[0]);
		obj->u_fig.plane.dir.y = ft_atod(tab[1]);
		obj->u_fig.plane.dir.z = ft_atod(tab[2]);
	}
	else if (obj->type == RT_LIGHT)
	{
		obj->u_fig.light.dir.x = ft_atod(tab[0]);
		obj->u_fig.light.dir.y = ft_atod(tab[1]);
		obj->u_fig.light.dir.z = ft_atod(tab[2]);
	}
	free_split(tab);
}

void	ft_assign_dir2(t_object *obj, char *str)
{
	char	**tab;

	tab = ft_strsplit(str, ',');
	if (obj->type == RT_CONE)
	{
		obj->u_fig.cone.dir.x = ft_atod(tab[0]);
		obj->u_fig.cone.dir.y = ft_atod(tab[1]);
		obj->u_fig.cone.dir.z = ft_atod(tab[2]);
	}
	else if (obj->type == RT_CYL)
	{
		obj->u_fig.cyl.dir.x = ft_atod(tab[0]);
		obj->u_fig.cyl.dir.y = ft_atod(tab[1]);
		obj->u_fig.cyl.dir.z = ft_atod(tab[2]);
	}
	free_split(tab);
}

void	ft_assign_pos(t_object *obj, char *str)
{
	char	**tab;

	tab = ft_strsplit(str, ',');
	if (obj->type == RT_PLANE)
	{
		obj->u_fig.plane.pos.x = ft_atod(tab[0]);
		obj->u_fig.plane.pos.y = ft_atod(tab[1]);
		obj->u_fig.plane.pos.z = ft_atod(tab[2]);
	}
	else if (obj->type == RT_LIGHT)
	{
		obj->u_fig.light.pos.x = ft_atod(tab[0]);
		obj->u_fig.light.pos.y = ft_atod(tab[1]);
		obj->u_fig.light.pos.z = ft_atod(tab[2]);
	}
	else if (obj->type == RT_SPHERE)
	{
		obj->u_fig.sphere.pos.x = ft_atod(tab[0]);
		obj->u_fig.sphere.pos.y = ft_atod(tab[1]);
		obj->u_fig.sphere.pos.z = ft_atod(tab[2]);
	}
	free_split(tab);
}

void	ft_assign_pos2(t_object *obj, char *str)
{
	char	**tab;

	tab = ft_strsplit(str, ',');
	if (obj->type == RT_CONE)
	{
		obj->u_fig.cone.pos.x = ft_atod(tab[0]);
		obj->u_fig.cone.pos.y = ft_atod(tab[1]);
		obj->u_fig.cone.pos.z = ft_atod(tab[2]);
	}
	else if (obj->type == RT_CYL)
	{
		obj->u_fig.cyl.pos.x = ft_atod(tab[0]);
		obj->u_fig.cyl.pos.y = ft_atod(tab[1]);
		obj->u_fig.cyl.pos.z = ft_atod(tab[2]);
	}
	free_split(tab);
}
