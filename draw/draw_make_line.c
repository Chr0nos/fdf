/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 19:00:28 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/03 16:38:01 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_line	draw_make_line(int x1, int y1, int x2, int y2)
{
	t_line	line;

	line.dx = x2 - x1;
	line.start.x = x1;
	line.start.y = y1;
	line.end.x = x2;
	line.end.y = y2;
	line.dy = line.end.y - line.start.y;
	return (line);
}
