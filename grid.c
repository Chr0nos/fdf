/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 13:57:45 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/04 18:28:09 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "draw.h"

static void	grid_intern(t_mlx *x, t_vector *p1, t_vector *p2)
{
	t_line		l;

	l = draw_make_line((int)p1->x, (int)p1->y, (int)p2->x, (int)p2->y);
	draw_line(x, &l, COLOR_CYAN);
}

void	grid_init(t_mlx *x, t_plist **plist)
{
	size_t		line;
	size_t		col;
	t_vector	*p1;
	t_vector	*p2;

	line = 0;
	while (plist[line])
	{
		col = 0;
		while (col < plist[line]->size)
		{
			p1 = &plist[line]->points[col];
			if (plist[line + 1])
			{
				p2 = &plist[line + 1]->points[col];
				grid_intern(x, p1, p2);
			}
			col++;
			if (col < plist[line]->size)
			{
				p2 = &plist[line]->points[col];
				grid_intern(x, p1, p2);
			}
		}
		line++;
	}
}
