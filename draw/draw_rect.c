/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 12:31:32 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/29 12:31:53 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

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
