/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 18:10:21 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/09 19:23:41 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "draw.h"
#include "libft.h"
#include <unistd.h>

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
	scale = draw_make_vector(19.0f, 5.0f, 0.0f);
	m = draw_make_matrix_z(draw_make_vector(512.0f, 384.0f, 0.0f), 1.0f + time, scale);
	p = 4;
	while (p--)
		tab[p] = draw_make_px(px[p], py[p]);
	draw_matrix_topxtab(tab, 4, &m);
	draw_perimeter(x, tab, 4, COLOR_GREEN);
	time += sens;
	draw_flush_image(x, x->img);
	usleep(6000);
	return (0);
}

int		main(void)
{
	t_mlx		*x;

	x = draw_init("test", 1024, 768);
	mlx_loop_hook(x->mlxptr, &display, x);
	draw_loop(x);
	return (0);
}
