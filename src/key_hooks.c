/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 12:51:41 by smaddox           #+#    #+#             */
/*   Updated: 2019/08/07 12:52:02 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_pressed(int keycode, t_mlx *n_mlx)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 34 || keycode == 35)
		n_mlx->image.p_type = (keycode == 34) ? 0 : 1;
	if (keycode == 126 || keycode == 125)
		n_mlx->image.controls.zoom += (keycode == 126) ? 1 : -1;
	if (keycode == 13 || keycode == 1)
		n_mlx->image.controls.up_down += (keycode == 13) ? -10 : 10;
	if (keycode == 2 || keycode == 0)
		n_mlx->image.controls.left_right += (keycode == 2) ? 10 : -10;
	redraw(n_mlx);
	return (0);
}
