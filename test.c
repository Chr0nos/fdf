/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 18:10:21 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/13 21:43:09 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "draw.h"
#include <unistd.h>

static void	display_mist(t_mlx *x)
{
	t_rect	r;

	r = draw_make_rect(400, 300, 600, 400);
	draw_rect_fill(x, &r, 0x001010);
	draw_rect_mist(x, &r, 42, COLOR_GREEN);
	draw_rect_mist(x, &r, 1, COLOR_WHITE);
	draw_rect(x, &r, COLOR_RED);
	r = draw_make_rect(800, 300, 900, 400);
	draw_rect_invert(x, &r);
}

static void	display_circle(t_mlx *x)
{
	t_circle		c;

	c = draw_make_circle(512, 384, 310);
	draw_circle(x, &c, COLOR_PURPLE);
	display_mist(x);
}

static int	display(t_mlx *x)
{
	static float	time = 30.0f;
	static float	sens = 0.012f * 0.5f;
	t_point			tab[4];
	t_matrix		m;
	t_vector		scale;
	int				p;
	const int		px[4] = { -15, 15, 15, -15 };
	const int		py[4] = { 15, 15, -15, -15 };

	draw_reset_image(x, 0x102010);
	if ((time > 40.0f) || (time <= 29.0f))
		sens = -sens;
	time += sens;
	scale = draw_make_vector(1.0f * time / 2.0f, 1.0f * time / 2.0f, 5.0f);
	m = draw_make_matrix(draw_make_vector(512.0f, 384.0f, 0.0f), 1.0f + time, scale);
	p = 4;
	while (p--)
		tab[p] = draw_make_px(px[p], py[p]);
	draw_matrix_topxtab(tab, 4, &m);
	draw_perimeter(x, tab, 4, COLOR_GREEN);
	//draw_pxtab(x, tab, 4, COLOR_GREEN);
	time += sens;
	display_circle(x);
	draw_flush_image(x, x->img);
	usleep(6000);
	return (0);
}

int		keys(int keycode, void *u)
{
	t_mlx	*x;

	x = (t_mlx*)u;
	if ((keycode == ' ') || (keycode == 53))
		display(x);
	return (0);
}

int		main(void)
{
	t_mlx		*x;

	x = draw_init("test", 1024, 768);
	draw_sethook(x, &keys, x);
	mlx_loop_hook(x->mlxptr, &display, x);
	draw_loop(x);
	return (0);
}
