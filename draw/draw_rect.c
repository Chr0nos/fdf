/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 12:31:32 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/30 18:20:49 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"
#include "libft.h"

void		draw_rect(t_mlx *x, t_rect *rect, int color)
{
	t_line	line;

	line.start.x = rect->start.x;
	line.start.y = rect->start.y;
	line.end.x = rect->end.x;
	line.end.y = rect->start.y;
	draw_line(x, &line, color);
	line.start.x = rect->end.y;
	line.start.y = rect->start.y;
	line.end.y = rect->end.y;
	line.end.x = rect->end.x;
	draw_line(x, &line, color);
}
