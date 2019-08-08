/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 12:57:07 by smaddox           #+#    #+#             */
/*   Updated: 2019/08/07 13:44:43 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_line_deux(t_unit p1, t_unit p2, t_img *img, t_dlvar line)
{
	while (1)
	{
		if ((p1.x >= WIN_SIZE_X ||
					p1.y >= WIN_SIZE_Y) || (p1.x < 0 || p1.y < 0))
			break ;
		set_img_pixel(p1.x, p1.y, img);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		line.temp = line.error;
		if (line.temp > -(line.delta_x))
		{
			line.error -= line.delta_y;
			p1.x += line.x_dir;
		}
		if (line.temp < line.delta_y)
		{
			line.error += line.delta_x;
			p1.y += line.y_dir;
		}
	}
}

void		create_img_deux(t_img *img, t_line *current)
{
	t_unit	temp1;
	t_unit	temp2;
	size_t	i;

	i = -1;
	while (++i < current->size)
	{
		if (current->prev && (current->prev->size > i))
		{
			temp1 = translate(current->units[i], img);
			temp2 = translate(current->prev->units[i], img);
			draw_line(temp1, temp2, img);
		}
		if (i + 1 < current->size)
		{
			temp1 = translate(current->units[i], img);
			temp2 = translate(current->units[i + 1], img);
			draw_line(temp1, temp2, img);
		}
	}
}
