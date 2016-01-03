/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 12:31:32 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/03 19:46:53 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"
#include "libft.h"

void		draw_rect(t_mlx *x, t_rect *rect, int color)
{
	t_line	line;

	ft_memcpy(&line.start, &rect->start, sizeof(t_point));
	line.end.x = rect->end.x;
	line.end.y = rect->start.y;
	draw_line(x, &line, color);
	line.start.x = rect->end.y;
	line.start.y = rect->start.y;
	ft_memcpy(&line.end, &rect->end, sizeof(t_point));
	draw_line(x, &line, color);
}
