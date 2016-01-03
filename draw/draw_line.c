/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 12:28:53 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/03 20:22:31 by snicolet         ###   ########.fr       */
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

static void	draw_line_bresemham(t_mlx *x, t_line *line, int color, t_point *var)
{
	float			e[3];
	t_point			point;

	ft_memcpy(&point, &line->start, sizeof(t_point));
	e[0] = -0.5f;
	e[1] = (float)(line->dy) / (float)(line->dx);
	if (e[1] < 0.0f)
		e[1] *= -1.0f;
	e[2] = -1.0f;
	while (point.x != line->end.x)
	{
		draw_px(x, &point, color);
		e[0] += e[1];
		while (e[0] >= 0)
		{
			draw_px(x,&point, color);
			e[0] += e[2];
			point.y += var->y;
		}
		point.x += var->x;
	}
}

void		draw_line(t_mlx *x, t_line *line, int color)
{
	t_point		variance;

	if ((line->dx == 0) && (line->dy == 0))
		draw_px(x, &line->start, color);
	else if (line->dy == 0)
		draw_flat_line(x, line, color);
	else if (line->dx == 0)
		draw_vertical_line(x, line, color);	
	else
	{
		variance.x = (line->dx < 0) ? -1 : 1;
		variance.y = (line->dy < 0) ? -1 : 1;
		draw_putpoint(&line->start);
		draw_putpoint(&line->end);
		draw_line_bresemham(x, line, color, &variance);
	}
}
