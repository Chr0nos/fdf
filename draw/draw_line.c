/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 12:28:53 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/29 16:35:58 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"

void		draw_line(t_mlx *x, t_aera *aera, int color)
{
	int			px;
	const int	end = aera->end.x - aera->start.x;
	const int	ex = aera->end.y - aera->start.y;
	const int	mod = (end < 0) ? -1 : 1;
	t_point		point;

	px = 0;
	while (px != end)
	{
		point.x = px + aera->start.x;
		point.y = (int)((float)px / (float)end * ex) + aera->start.y;
		draw_px(x, &point, color);
		px += mod;
	}
}
