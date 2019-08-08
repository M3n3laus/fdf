/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 12:57:07 by smaddox           #+#    #+#             */
/*   Updated: 2019/08/07 13:47:23 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_line(t_unit p1, t_unit p2, t_img *img)
{
	t_dlvar	line;

	line.delta_x = abs(p2.x - p1.x);
	line.delta_y = abs(p2.y - p1.y);
	line.x_dir = p1.x < p2.x ? 1 : -1;
	line.y_dir = p1.y < p2.y ? 1 : -1;
	line.error = (line.delta_x > line.delta_y ?
			line.delta_x : -(line.delta_y)) / 2;
	draw_line_deux(p1, p2, img, line);
}

void		set_img_pixel(int x, int y, t_img *img)
{
	int i;

	i = (x * 4) + (y * img->size_line);
	img->img_data[i++] = (char)255;
	img->img_data[i++] = (char)255;
	img->img_data[i++] = (char)255;
}

void		create_img(t_img *img)
{
	t_line	*current;

	current = img->line_data;
	while (current)
	{
		create_img_deux(img, current);
		current = current->next;
	}
}

t_unit		translate(t_unit point, t_img *img)
{
	point.x *= img->controls.zoom;
	point.y *= img->controls.zoom;
	point.z *= img->controls.zoom / 1;
	point.x -= (img->width * img->controls.zoom) / 2;
	point.y -= (img->height * img->controls.zoom) / 2;
	if (img->p_type == 0)
		point = iso(point);
	point.x += WIN_SIZE_X / 2;
	point.y += (WIN_SIZE_Y + img->height * img->controls.zoom) / 2;
	point.x += img->controls.left_right;
	point.y += img->controls.up_down;
	return (point);
}

t_unit		iso(t_unit point)
{
	int temp_x;
	int temp_y;

	temp_x = point.x;
	temp_y = point.y;
	point.x = (temp_x - temp_y) * cos(0.523599);
	point.y = -(point.z) + (temp_x + temp_y) * sin(0.523599);
	return (point);
}
