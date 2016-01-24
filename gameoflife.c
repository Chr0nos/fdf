/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameoflife.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 14:16:24 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/24 18:20:49 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#define COLUMNS 64
#define COLOR_BACKGROUND 0x00402050

static t_point	get_steps(t_mlx *x)
{
	t_point		steps;

	steps.x = x->width / COLUMNS;
	steps.y = x->height / COLUMNS;
	return (steps);
}

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
	for (p = 0 ; p <= x->height ; p += step)
	{
		line = draw_make_line(0, p, x->width, p);
		draw_line(x, &line, COLOR_WHITE);
	}
}

static void		color_box(t_mlx *x, int cx, int cy, int color)
{
	t_point		steps;
	t_rect		r;

	steps = get_steps(x);
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

	steps = get_steps(x);
	p.x = px / steps.x;
	p.y = py / steps.y;
	return (p);
}
/*
static int		getcase_color(t_mlx *x, int cx, int cy)
{

}
*/
static int		mouse(int button, int mx, int my, void *userdata)
{
	t_mlx	*x;
	t_point	c;

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
	return (0);
}

static void next_turn(t_mlx *x)
{
	t_point			p;

	for (p.y = 0 ; p.y <= COLUMNS ; p.y++)
	{
		for (p.x = 0 ; p.x < COLUMNS ; p.x++)
		{
			color_box(x, p.x, p.y, COLOR_CYAN);
		}
	}
	draw_flush_image(x, x->img);
}

static int	keys(int keycode, void *userdata)
{
	t_mlx	*x;

	x = userdata;
	if (keycode == 53)
		display_gol(x);
	else if ((keycode == 'q') || (keycode == 12))
		exit(0);
	else if ((keycode == 49) || (keycode == ' '))
		next_turn(x);
	else
		printf("key: %d\n", keycode);
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
