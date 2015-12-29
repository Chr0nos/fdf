/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:27:50 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/29 16:21:19 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include <string.h>
# define COLOR_WHITE 0xffffff
# define COLOR_BLUE 0x0000ff
# define COLOR_RED 0xff0000
# define COLOR_GREEN 0x00ff00

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

typedef struct	s_aera
{
	t_point		start;
	t_point		end;
}				t_aera;

typedef struct	s_mlx_image
{
	char		*data;
	void		*img;
	int			width;
	int			bpp;
	int			endian;
	int			padding;
}				t_mlx_img;

typedef struct	s_mlx
{
	t_mlx_img	*img;
	void		*mlxptr;
	void		*winptr;
	int			width;
	int			height;
}				t_mlx;

t_aera			*set_aera(t_aera *aera, t_point start, t_point end);
t_aera			*make_aera(int x, int y, int ex, int ey);
void			draw_px(t_mlx *x, t_point *point, int color);
void			draw_rect(t_mlx *x, t_aera *aera, int color);
void			draw_line(t_mlx *x, t_aera *aera, int color);
void			draw_grid(t_mlx *x, t_tab *tab);
void			draw_box(t_mlx *x, t_aera *aera, int color);
void			draw_new_image(t_mlx *x);
t_mlx			*draw_init(char *name, int width, int height);

#endif
