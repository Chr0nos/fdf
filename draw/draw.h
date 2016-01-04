/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:27:50 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/04 20:25:42 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include <string.h>
# define COLOR_WHITE 0xffffff
# define COLOR_BLUE 0x0000ff
# define COLOR_RED 0xff0000
# define COLOR_GREEN 0x00ff00
# define COLOR_BLACK 0

typedef struct	s_tab
{
	size_t		size;
	size_t		line_len;
	int			*tab;
}				t_tab;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_area
{
	t_point		start;
	t_point		end;
}				t_area;

typedef struct	s_line
{
	t_point		start;
	t_point		end;
	int			dx;
	int			dy;
}				t_line;

typedef t_area	t_rect;
typedef struct	s_circle
{
	t_point		center;
	int			radius;
}				t_circle;

typedef struct	s_mlx_image
{
	char		*data;
	void		*img;
	int			width;
	int			bpp;
	int			endian;
	int			max_size;
}				t_mlx_img;

typedef struct	s_mlx
{
	t_mlx_img	*img;
	void		*mlxptr;
	void		*winptr;
	int			width;
	int			height;
}				t_mlx;

t_line			draw_make_line(int x1, int y1, int x2, int y2);
t_rect			draw_make_rect(int x1, int y1, int x2, int y2);
t_circle		draw_make_circle(int x1, int y1, int radius);
void			draw_putpoint(t_point *point);
void			draw_px(t_mlx *x, t_point *point, int color);
void			draw_rect(t_mlx *x, t_rect *rect, int color);
void			draw_rect_fill(t_mlx *x, t_rect *rect, int color);
void			draw_line(t_mlx *x, t_line *line, int color);
void			draw_grid(t_mlx *x, t_tab *tab);
void			draw_box(t_mlx *x, t_rect *rect, int color);
void			draw_circle(t_mlx *x, const t_circle *circle, int color);
void			draw_new_image(t_mlx *x);
void			draw_flush_image(t_mlx *x, t_mlx_img *img);
void			draw_reset_image(t_mlx *x, int color);
void			draw_loop(t_mlx *x);
void			draw_clear(t_mlx *x);
t_mlx			*draw_init(char *name, int width, int height);

#endif
