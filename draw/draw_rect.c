/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 12:31:32 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/30 13:55:18 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"

void		draw_rect(t_mlx *x, t_rect *rect, int color)
{
	int				line;
	int				col;
	const int		rx = rect->start.x;
	const int		ry = rect->start.y;

	line = rect->end.x - rect->start.x;
	while ((line--) && ((col = rect->end.y - rect->start.y)))
		while (col--)
			mlx_pixel_put(x->mlxptr, x->winptr, rx + line, ry + col, color);
}
