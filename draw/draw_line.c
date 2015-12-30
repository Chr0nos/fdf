/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 12:28:53 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/30 19:35:15 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"
#include "libft.h"

static void	draw_flat_line(t_mlx *x, t_line *line, int color)
{
	t_point		point;

	ft_memcpy(&point, &line->start, sizeof(t_point));
	while (point.x != line->end.x)
	{
		draw_px(x, &point, color);
		point.x += 1;
	}
}

static void	draw_vertical_line(t_mlx *x, t_line *line, int color)
{
	t_point		point;

	ft_memcpy(&point, &line->start, sizeof(t_point));
	while (point.y != line->end.y)
	{
		draw_px(x, &point, color);
		point.y += 1;
	}
}

static void	draw_line_bresemham(t_mlx *x, t_line *line, int color)
{
	float			e[2];
	t_point			point;

	ft_memcpy(&point, &line->start, sizeof(t_point));
	e[0] = 0.5f;
	e[1] = (float)(line->dy) / (float)(line->dx - 1);
	while (point.x <= line->end.x && point.y <= line->end.y)
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
	if ((line->dx == 0) && (line->dy == 0))
		draw_px(x, &line->start, color);
	else if (line->dy == 0)
		draw_flat_line(x, line, color);
	else if (line->dx == 0)
		draw_vertical_line(x, line, color);	
	else
		draw_line_bresemham(x, line, color);
}
