/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpivet-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 00:26:11 by mpivet-p          #+#    #+#             */
/*   Updated: 2021/05/31 17:32:54 by mpivet-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "rtv1.h"
#include "rtdata.h"
#include "libft.h"

void	init_mlx_ptr(t_fmlx *ptr)
{
	int	tools[3];

	ptr->mlx = mlx_init();
	if (!(ptr->mlx))
		rtv_exit(ptr);
	ptr->win = mlx_new_window(ptr->mlx, SWIN_X, SWIN_Y, "RTv1");
	if (!(ptr->win))
		rtv_exit(ptr);
	ptr->img = mlx_new_image(ptr->mlx, SIMG_X, SIMG_Y);
	if (!(ptr->img))
		rtv_exit(ptr);
	ptr->screen = mlx_get_data_addr(ptr->img, &(tools[0]),
			&(tools[1]), &(tools[2]));
	if (!(ptr->screen))
		rtv_exit(ptr);
	ptr->ui = mlx_new_image(ptr->mlx, SUI_X, SUI_Y);
	if (!(ptr->ui))
		rtv_exit(ptr);
	ptr->ui_img = mlx_get_data_addr(ptr->ui, &(tools[0]),
			&(tools[1]), &(tools[2]));
	if (!(ptr->ui_img))
		rtv_exit(ptr);
}

void	rtv(t_fmlx *ptr)
{
	init_mlx_ptr(ptr);
	mlx_hook(ptr->win, 17, 1L << 1, &rtv_exit, ptr);
	mlx_hook(ptr->win, 2, 1L << 0, deal_key, ptr);
	mlx_hook(ptr->win, 4, 1L << 1, mouse_press, ptr);
	ptr->intensity = 1;
	init_ui(ptr);
	rt(ptr);
	disp_ui(ptr);
	mlx_loop(ptr->mlx);
}

int	main(int argc, char **argv)
{
	t_fmlx	ptr;

	ft_bzero(&ptr, sizeof(t_fmlx));
	if (argc != 2)
	{
		ft_putstr_fd("usage: rtv1 <file>\n", 2);
		return (1);
	}
	if (parser(&ptr, argv[1]))
	{
		ft_putstr_fd("Exit from parser..\n", 2);
		ft_delete_list(&(ptr.obj));
//		ft_bzero(&ptr, sizeof(t_fmlx));
//		while (1) ;
		return (1);
	}
	rtv(&ptr);
	rt_delist(&ptr);
	return (0);
}
