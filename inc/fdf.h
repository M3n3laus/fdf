/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddox <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 21:47:25 by smaddox           #+#    #+#             */
/*   Updated: 2019/08/07 13:54:27 by smaddox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "get_next_line.h"
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define WIN_SIZE_X 1600
# define WIN_SIZE_Y 1600
# define WIN_TITLE "FDF"

typedef struct		s_dlvar
{
	int				delta_x;
	int				delta_y;
	int				x_dir;
	int				y_dir;
	int				error;
	int				temp;
}					t_dlvar;

typedef struct		s_unit
{
	int				x;
	int				y;
	int				z;
}					t_unit;

typedef struct		s_line
{
	struct s_line	*prev;
	struct s_line	*next;
	size_t			size;
	t_unit			*units;
}					t_line;

typedef struct		s_dumb
{
	int				zoom;
	int				up_down;
	int				left_right;
}					t_c;

typedef struct		s_img
{
	t_c				controls;
	int				bpp;
	int				size_line;
	int				endian;
	void			*img_ptr;
	char			*img_data;
	t_line			*line_data;
	int				width;
	int				height;
	int				depth;
	int				p_type;

}					t_img;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_img			image;
}					t_mlx;

void				parse(int fd, t_img *img);
void				parse_helper(char *line, t_line *line_data,
		int y, t_img *img);
void				set_dimension(t_img *img, int y, int x, int z);
void				clean_line_split(char **line_split);
void				clean_lines(t_line *line_data);
int					key_pressed(int keycode, t_mlx *n_mlx);
void				draw_line(t_unit p1, t_unit p2, t_img *img);
void				set_img_pixel(int x, int y, t_img *img);
t_unit				translate(t_unit point, t_img *img);
t_unit				iso(t_unit point);
void				create_img(t_img *img);
void				redraw(t_mlx *n_mlx);
void				draw_line_deux(t_unit p1, t_unit p2,
		t_img *img, t_dlvar line);
void				create_img_deux(t_img *img, t_line *current);
#endif
