/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 12:28:53 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/29 12:29:15 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void		draw_line(t_mlx *x, t_aera *aera, int color)
{
	const int	end = aera->end.x - aera->start.x;
	const int	ex = aera->end.y - aera->start.y;
	int			px;

	px = 0;
	while (px != end)
	{
		mlx_pixel_put(x->mlxptr,
				x->winptr,
				px + aera->start.x,
				(int)((float)px / (float)end * ex) + aera->start.y,
				color);
		px += ((end < 0) ? -1 : 1);
	}
}
