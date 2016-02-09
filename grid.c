/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 13:57:45 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/08 18:47:51 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "draw.h"

#include "libft.h"

inline static void	grid_intern(t_mlx *x, t_vector *p1, t_vector *p2)
{
	t_line		l;

	l = draw_raster_line(*p1, *p2, &x->gtransform);
	if ((l.start.x > x->width) || (l.start.y > x->height))
		return ;
	if ((l.end.x > x->width) || (l.end.x < 0) | (l.end.y > x->height) ||
			(l.end.y <= 0))
		return ;
	//ft_printf("sx: %d sy: %d ex: %d ey: %d\n", l.start.x, l.start.x, l.end.x, l.end.y);
	draw_line(x, &l, COLOR_CYAN);
}

void				grid_init(t_mlx *x, t_plist **plist)
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
			if (++col < plist[line]->size)
			{
				p2 = &plist[line]->points[col];
				grid_intern(x, p1, p2);
			}
		}
		line++;
	}
}
