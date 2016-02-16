/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:27:50 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/16 19:36:50 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include <string.h>
# include "colors.h"

enum			e_color
{
	COLOR_WHITE = 0x00ffffff,
	COLOR_BLUE = 0x000000ff,
	COLOR_RED = 0x00ff0000,
	COLOR_GREEN = 0x0000ff00,
	COLOR_PURPLE = 0x009900cc,
	COLOR_CYAN = 0x0000ccff,
	COLOR_YELLOW = 0x00ffff00,
	COLOR_BROWN = 0x00220000,
	COLOR_BLACK = 0
};

enum			e_keycode
{
	M_ESC = 53,
	L_ESC = 65307,
	L_NEXT = 65363,
	L_PREV = 65361,
	L_DOWN = 65364,
	L_UP = 65362,
	L_ENTER = 65293,
	L_DEL = 65288,
	L_MORE = 65451,
	L_LESS = 65453,
	L_SHIFT = 65505
};

enum			e_hook
{
	KEYDOWN = 2,
	KEYUP = 3,
	MOUSEDOWN = 4,
	MOUSEUP = 5,
	MOUSEMOVE = 6,
	EXPOSE = 12,
	CLOSE = 17
};

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

typedef struct	s_draw_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

typedef struct	s_matrix
{
	t_vector	x;
	t_vector	y;
	t_vector	z;
	t_vector	offset;
}				t_matrix;

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
	t_matrix	gtransform;
}				t_mlx;

t_matrix		draw_make_matrix_x(t_vector pos, float rad, t_vector scale);
t_matrix		draw_make_matrix_y(t_vector pos, float rad, t_vector scale);
t_matrix		draw_make_matrix_z(t_vector pos, float rad, t_vector scale);
t_matrix		draw_make_matrix_iso(int x, int y, int w, int h);
t_matrix		draw_make_matrix_ortho(t_vector s, t_vector c);
t_matrix		draw_matrix_multiply_matrix(t_matrix m1, const t_matrix *m2);
t_vector		draw_make_vector(float x, float y, float z);
t_vector		draw_vector_transform(t_vector v, const t_matrix *m);
t_line			draw_make_line(int x1, int y1, int x2, int y2);
t_rect			draw_make_rect(int x1, int y1, int x2, int y2);
t_circle		draw_make_circle(int x1, int y1, int radius);
t_point			draw_make_px(int x, int y);
void			draw_putpoint(t_point *point);
void			draw_px(t_mlx *x, const t_point *point, int color);
void			draw_rect(t_mlx *x, t_rect *rect, int color);
void			draw_rect_fill(t_mlx *x, t_rect *rect, int color);
void			draw_rect_mist(t_mlx *x, const t_rect *rect, size_t pixels,
		int color);
void			draw_rect_invert(t_mlx *x, const t_rect *r);
void			draw_line(t_mlx *x, t_line *line, int color);
void			draw_grid(t_mlx *x, t_tab *tab);
void			draw_box(t_mlx *x, t_rect *rect, int color);
void			draw_circle(t_mlx *x, const t_circle *circle, int color);
void			draw_new_image(t_mlx *x);
void			draw_flush_image(t_mlx *x, t_mlx_img *img);
void			draw_reset_image(t_mlx *x, int color);
void			draw_loop(t_mlx *x);
void			draw_loop_hook(t_mlx *x, int (*display)(void *user),
		void *userdata);
void			draw_clear(t_mlx *x);
void			draw_perimeter(t_mlx *x, const t_point *tab, size_t size,
		int color);
void			draw_pxtab(t_mlx *x, t_point *tab, size_t size, int color);
int				draw_get_px(t_mlx *x, const t_point *point);
t_mlx			*draw_init(char *name, int width, int height);
void			draw_sethook(t_mlx *x, int (*f)(int, void*), void *userdata);
void			draw_sethook_ng(t_mlx *x, int (*f)(), void *userdata,
		const enum e_hook hook);
t_point			*draw_move_pxlist(t_point *tab, size_t size, int x, int y);
t_point			*draw_matrix_topxtab(t_point *tab, size_t size, t_matrix *t);
t_point			draw_raster_px(t_vector v, t_matrix *transform);
t_vector		draw_matrix_multiply(t_vector point, const t_matrix *t);
t_line			draw_raster_line(t_vector v1, t_vector v2, t_matrix *transform);
t_rgb			draw_color_hsv(int t, float s, float v);
int				draw_color_rgb2int(t_rgb *rgb);

#endif
