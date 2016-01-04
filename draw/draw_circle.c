/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:18:11 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/04 13:40:55 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	draw_circle_px(t_mlx *x, const t_point *p, const t_circle *c,
		int color)
{
	const int	tabx[8] = { p->x, p->y, -p->y, p->x, p->y, -p->x, -p->y };
	const int	taby[8] = { p->y, p->x, p->y, p->y, -p->y, -p->y, -p->x };
	t_point		px;
	int			idx;

	idx = 8;
	while (idx--)
	{
		px.x = c->start.x + tabx[idx];
		px.y = c->start.y +  taby[idx];
		draw_px(x, &px, color);
	}
}

void	draw_circle(t_mlx *x, const t_circle *circle, int color)
{
	t_point	p;
	int		d;
	int		r;

	r = circle->end.x - circle->start.x;
	p.x = 0;
	p.y = r;
	d = p.y - 1;
	while (p.y >= p.x)
	{
		draw_circle_px(x, &p, circle, color);
		if (d >= (p.x * 2))
		{
			d = d * (2 * p.x) - 1;
			p.x += 1;
		}
		else if (d < (2 * (r - p.y)))
		{
			d += (2 * p.y) - 1;
			p.y -= 1;
		}
		else
		{
			d += 2 * (p.y - p.x - 1);
			p.y -= 1;
			p.y += 1;
		}
	}
}
