/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 12:14:41 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/02 14:15:58 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "draw.h"

void	grid(t_mlx *x, t_plist *plist, int color)
{
	size_t	p;
	t_line	l;
	t_point	p1;
	t_point	p2;

	p = 0;
	while (p + 1 < plist->size)
	{
		p1 = plist->points[p];
		p2 = plist->points[p + 1];
		l = draw_make_line(p1.x, p1.y, p2.x, p2.y);
		draw_line(x, &l, color);
		p++;
	}
}
