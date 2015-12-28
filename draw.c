/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 19:12:29 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/28 19:15:26 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

void		draw_rect(t_mlx *x, t_aera *aera, int color)
{
	const int		end = aera->end.x * aera->end.y + 1;
	int				px;

	px = aera->start.x * aera->start.y;
	while (px < end)
	{
		mlx_pixel_put(x->mlxptr,
				x->winptr,
				aera->start.x + (px / (aera->end.x - aera->start.x)),
				aera->start.y + (px % (aera->end.x - aera->start.y)),
				color);
		++px;
	}
}

int			draw(int *tab)
{
	t_mlx	x;
	t_aera	a;

	(void)tab;
	x.mlxptr = mlx_init();
	if (!x.mlxptr)
		return (1);
	if (!(x.winptr = mlx_new_window(x.mlxptr, 800, 600, "Coucou")))
		return (2);
	a.start.x = 42;
	a.start.y = 42;
	a.end.x = 442;
	a.end.y = 100;
	draw_rect(&x, &a, COLOR_GREEN);
	mlx_loop(x.mlxptr);
	return (0);
}
