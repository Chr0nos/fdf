/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameoflife.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 14:16:24 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/24 17:03:13 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"
#include <stdlib.h>
#define COLUMNS 64
#define COLOR_BACKGROUND 0x00402050

static void		make_grid(t_mlx *x, int columns)
{
	int		p;
	int		e;
	int		step;
	t_line	line;

	step = x->width / columns;
	for (p = 0 ; p < x->width ; p += step)
	{
		line = draw_make_line(p, 0, p, x->height);
		draw_line(x, &line, COLOR_WHITE);
	}
	step = x->height / columns;
	for (p = 0 ; p < x->height ; p += step)
	{
		line = draw_make_line(0, p, x->width, p);
		draw_line(x, &line, COLOR_WHITE);
	}
}

static void		color_box(t_mlx *x, int cx, int cy, int color)
{
	t_point		steps;
	t_rect		r;

	steps.x = x->width / COLUMNS;
	steps.y = x->height / COLUMNS;
	r.start.x = cx * steps.x + 1;
	r.start.y = cy * steps.y + 1;
	r.end.x = (cx + 1) * steps.x;
	r.end.y = (cy + 1) * steps.y - 1;
	draw_rect_fill(x, &r, color);
}

static void		display_gol(t_mlx *x)
{
	draw_reset_image(x, COLOR_BACKGROUND);
	make_grid(x, COLUMNS);
	draw_flush_image(x, x->img);

}

static t_point	getcase(t_mlx *x, int px, int py)
{
	t_point		steps;
	t_point		p;

	steps.x = x->width / COLUMNS;
	steps.y = x->height / COLUMNS;
	p.x = px / steps.x;
	p.y = py / steps.y;
	return (p);
}

static int		mouse(int button, int mx, int my, void *userdata)
{
	t_mlx	*x;
	t_point	c;

	//printf("%d %d %d\n", button, mx, my);
	x = (t_mlx*)userdata;
	c = getcase(x, mx, my);
	if (button == 1)
	{
		color_box(x, c.x, c.y, COLOR_RED);
		draw_flush_image(x, x->img);
	}
	else if (button == 2)
	{
		color_box(x, c.x, c.y, COLOR_BACKGROUND);
		draw_flush_image(x, x->img);
	}
	//display_gol(x);
	return (0);
}

static int	keys(int keycode, void *userdata)
{
	t_mlx	*x;

	x = userdata;
	if (keycode == 53)
		display_gol(x);
	else if (keycode == 'q')
		exit(0);
	return (0);
}

int				main(void)
{
	t_mlx	*x;

	x = draw_init("Game Of Life", 1920, 1080);
	display_gol(x);
	draw_sethook(x, &keys, x);
	mlx_mouse_hook(x->winptr, &mouse, x);
	draw_loop(x);
	return (0);
}
