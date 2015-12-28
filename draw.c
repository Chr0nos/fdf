/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 19:12:29 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/28 21:22:38 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

void		draw_rect(t_mlx *x, t_aera *aera, int color)
{
	int				line;
	int				col;
	const int		rx = aera->start.x;
	const int		ry = aera->start.y;

	line = aera->end.x - aera->start.x;
	while ((line--) && ((col = aera->end.y - aera->start.y)))
		while (col--)
			mlx_pixel_put(x->mlxptr, x->winptr, rx + line, ry + col, color);
}

void		draw_line(t_mlx *x, t_aera *aera, int color)
{
	const int	end = aera->end.x - aera->start.x;
	const int	ex = aera->end.y - aera->start.y;
	int			px;

	px = 0;
	while (px <= end)
	{
		mlx_pixel_put(x->mlxptr,
				x->winptr,
				px + aera->start.x,
				(int)((float)px / (float)end * ex) + aera->start.y,
				color);
		++px;
	}
}

void		draw_grid(t_mlx *x, t_tab *tab)
{
	size_t	p;

	p = 0;
	while (p < tab->size)
	{
		++p;
	}
	(void)tab;
	(void)x;
}

int			draw(t_tab *tab)
{
	t_mlx	x;
	t_aera	a;

	(void)tab;
	(void)draw_rect;
	(void)draw_line;
	x.mlxptr = mlx_init();
	if (!x.mlxptr)
		return (1);
	if (!(x.winptr = mlx_new_window(x.mlxptr, 800, 600, "Coucou")))
		return (2);
	a.start.x = 42;
	a.start.y = 42;
	a.end.x = 442;
	a.end.y = 100;
	draw_line(&x, &a, COLOR_WHITE);
	mlx_loop(x.mlxptr);
	return (0);
}
