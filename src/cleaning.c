/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 12:51:11 by smaddox           #+#    #+#             */
/*   Updated: 2019/08/07 12:51:31 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void		clean_lines(t_line *line_data)
{
	t_line *current;
	t_line *temp;

	current = line_data;
	while (current)
	{
		free(current->units);
		temp = current;
		current = current->next;
		free(temp);
	}
}

void		clean_line_split(char **line_split)
{
	int i;

	i = 0;
	while (line_split[i])
		free(line_split[i++]);
	free(line_split);
}
