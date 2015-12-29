/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 19:12:29 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/29 13:07:07 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"
#include <stdlib.h>

void		draw_grid(t_mlx *x, t_tab *tab)
{
	size_t	p;

	p = 0;
	while (p < tab->size)
	{
		
		p++;
	}
	(void)tab;
	(void)x;
}

int			draw(t_tab *tab)
{
	t_mlx	x;
	t_aera	*a;

	(void)tab;
	(void)draw_rect;
	(void)draw_line;
	x.height = 600;
	x.width = 800;
	x.mlxptr = mlx_init();
	if (!x.mlxptr)
		return (1);
	if (!(x.winptr = mlx_new_window(x.mlxptr, x.width, x.height, "Coucou")))
		return (2);
	a = make_aera(442, 100, 42, 42);
	draw_box(&x, a, COLOR_WHITE);
	draw_line(&x, a, COLOR_RED);
	free(a);
	mlx_loop(x.mlxptr);
	return (0);
}
