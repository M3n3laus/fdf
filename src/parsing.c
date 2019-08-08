/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 12:54:54 by smaddox           #+#    #+#             */
/*   Updated: 2019/08/07 12:56:20 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		parse(int fd, t_img *img)
{
	char	*line;
	int		y;
	t_line	*current;

	line = "garbage";
	y = 0;
	img->line_data = (t_line*)malloc(sizeof(t_line));
	ft_bzero(img->line_data, sizeof(t_line));
	current = img->line_data;
	if ((get_next_line(fd, &line)) > 0)
	{
		parse_helper(line, current, y, img);
		++y;
	}
	while ((get_next_line(fd, &line)) > 0)
	{
		current->next = (t_line*)malloc(sizeof(t_line));
		ft_bzero(current->next, sizeof(t_line));
		current->next->prev = current;
		current = current->next;
		parse_helper(line, current, y, img);
		y++;
	}
}

void		parse_helper(char *line, t_line *line_data, int y, t_img *img)
{
	int		index;
	int		num_index;
	char	**line_split;

	num_index = 0;
	index = -1;
	line_split = ft_strsplit(line, 32);
	if (line)
		free(line);
	while (line_split[num_index])
		++num_index;
	line_data->units = (t_unit*)malloc(num_index * sizeof(t_unit));
	line_data->size = num_index;
	while (++index < num_index)
	{
		line_data->units[index].x = index;
		line_data->units[index].y = y;
		line_data->units[index].z = ft_atoi(line_split[index]);
		set_dimension(img, y, index, line_data->units[index].z);
	}
	clean_line_split(line_split);
}

void		set_dimension(t_img *img, int y, int x, int z)
{
	if (img->width < x)
		img->width = x;
	if (img->height < y)
		img->height = y;
	if (img->depth < z)
		img->depth = z;
}
