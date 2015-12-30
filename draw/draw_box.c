/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:06:32 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/30 15:12:10 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"

void		draw_box(t_mlx *x, t_rect *rect, int color)
{
	t_rect	na;

	ft_memcpy(&na.start, &rect->start, sizeof(t_point));
	na.end.x = rect->end.x - rect->start.x;
	na.end.y = rect->end.y;
	draw_line(x, &na, color);
}
