/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect_invert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 20:38:11 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/13 21:27:55 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_rect_invert(t_mlx *x, const t_rect *r)
{
	int		color;
	t_point	p;

	p.y = r->start.y;
	while (p.y <= r->end.y)
	{
		p.x = r->start.x;
		while  (p.x <= r->end.x)
		{
			color = 0xffffff - draw_get_px(x, &p);
			draw_px(x, &p, color);
			p.x++;
		}
		p.y++;
	}
}
