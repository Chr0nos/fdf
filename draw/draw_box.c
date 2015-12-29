/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:06:32 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/29 13:39:08 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"

void		draw_box(t_mlx *x, t_aera *aera, int color)
{
	t_aera	na;

	ft_memcpy(&na.start, &aera->start, sizeof(t_point));
	na.end.x = aera->end.x - aera->start.x;
	na.end.y = aera->end.y;
	draw_line(x, &na, color);
}
