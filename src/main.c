/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 13:41:37 by smaddox           #+#    #+#             */
/*   Updated: 2019/08/07 16:32:39 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_mlx	n_mlx;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (argc == 2 && fd > 0)
	{
		ft_bzero(&(n_mlx), sizeof(t_mlx));
		parse(fd, &(n_mlx.image));
		n_mlx.mlx = mlx_init();
		n_mlx.win = mlx_new_window(n_mlx.mlx,
				WIN_SIZE_X, WIN_SIZE_Y, WIN_TITLE);
		n_mlx.image.img_ptr = mlx_new_image(n_mlx.mlx, WIN_SIZE_X, WIN_SIZE_Y);
		n_mlx.image.img_data = mlx_get_data_addr(n_mlx.image.img_ptr,
				&(n_mlx.image.bpp),
				&(n_mlx.image.size_line), &(n_mlx.image.endian));
		create_img(&(n_mlx.image));
		mlx_put_image_to_window(n_mlx.mlx, n_mlx.win,
				n_mlx.image.img_ptr, 0, 0);
		mlx_key_hook(n_mlx.win, key_pressed, &(n_mlx));
		mlx_loop(n_mlx.mlx);
	}
	else
		write(1, "error\n", 6);
	return (0);
}

void	redraw(t_mlx *n_mlx)
{
	mlx_clear_window(n_mlx->mlx, n_mlx->win);
	mlx_destroy_image(n_mlx->mlx, n_mlx->image.img_ptr);
	n_mlx->image.img_ptr = mlx_new_image(n_mlx->mlx, WIN_SIZE_X, WIN_SIZE_Y);
	n_mlx->image.img_data = mlx_get_data_addr(n_mlx->image.img_ptr,
			&(n_mlx->image.bpp),
			&(n_mlx->image.size_line), &(n_mlx->image.endian));
	create_img(&(n_mlx->image));
	mlx_put_image_to_window(n_mlx->mlx, n_mlx->win, n_mlx->image.img_ptr, 0, 0);
}
