/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:06:32 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/30 19:10:39 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"

void		draw_box(t_mlx *x, t_rect *rect, int color)
{
	t_line	line;

	line = draw_make_line(rect->start.x,
			rect->start.y,
			rect->end.x,
			rect->end.y);
	draw_line(x, &line, color);
}
