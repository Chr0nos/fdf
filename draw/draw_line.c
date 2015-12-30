/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 12:28:53 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/30 17:04:16 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"
#include "libft.h"

static void	draw_flat_line(t_mlx *x, t_line *line, const int direct, int color)
{
	int			px;
	const int	mod = (direct < 0) ? - 1 : 1;
	t_point		point;

	px = line->start.x;
	point.y = line->start.y;
	while (px != line->end.x)
	{
		point.x = px;
		draw_px(x, &point, color);
		px += mod;
	}
}

static void	draw_vertical_line(t_mlx *x, t_line *line, const int dir, int color)
{
	const int	mod = (dir < 0) ? -1 : 1;
	t_point		point;

	ft_memcpy(&point, &line->start, sizeof(t_point));
	while (point.y != line->end.y)
	{
		draw_px(x, &point, color);
		point.y += mod;
	}
}

static void	draw_line_bresemham(t_mlx *x, t_line *line, int color, t_point *dis)
{
	float			e[2];
	t_point			point;

	point.y = line->start.y;
	point.x = line->start.x;
	e[0] = 0.5f;
	e[1] = (float)(dis->y) / (float)(dis->x - 1);
	while (point.x < line->end.x && point.y < line->end.y)
	{
		draw_px(x, &point, color);
		e[0] += e[1];
		if (e[0] >= 1.0f)
		{
			point.y += 1;
			e[0] -= 1.0f;
		}
		point.x += 1;
	}
}

void		draw_line(t_mlx *x, t_line *line, int color)
{
	const int		dx = line->end.x - line->start.x;
	const int		dy = line->end.y - line->start.y;
	t_point			dists;

	if ((dx == 0) && (dy == 0))
		draw_px(x, &line->start, color);
	else if (dy == 0)
		draw_flat_line(x, line, dx, color);
	else if (dx == 0)
		draw_vertical_line(x, line, dy, color);	
	else
	{
		dists.x = dx;
		dists.y = dy;
		draw_line_bresemham(x, line, color, &dists);
	}
}
