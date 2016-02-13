/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 13:57:45 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/13 18:58:06 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "draw.h"
#include "libft.h"

inline static int	valid_px(t_mlx *x, t_point *p)
{
	if ((p->x >= 0) && (p->x < x->width) && (p->y >= 0) && (p->y < x->height))
		return (1);
	return (0);
}

inline static void	fix_px(t_mlx *x, t_point *p)
{
	if (p->x < 0)
		p->x = 0;
	else if (p->x > x->width - 1)
		p->x = x->width - 1;
	if (p->y < 0)
		p->y = 0;
	else if (p->y >= x->height)
		p->y = x->height - 1;
}

inline static int	fix_line(t_mlx *x, t_line *l)
{
	const int	valid_end = valid_px(x, &l->end);
	const int	valid_start = valid_px(x, &l->start);

	if ((valid_start) && (valid_end))
		return (1);
	if (((!valid_start) && (valid_end)) || ((valid_start) && (!valid_end)))
	{
		fix_px(x, &l->start);
		fix_px(x, &l->end);
		l->dx = ft_abs(l->end.x - l->start.x);
		l->dy = ft_abs(l->end.y - l->start.y);
		return (1);
	}
	return (0);
}

inline static void	grid_intern(t_mlx *x, t_vector *p1, t_vector *p2)
{
	t_line		l;
	int			z;

	l = draw_raster_line(*p1, *p2, &x->gtransform);
	if (!fix_line(x, &l))
		return ;
	z = (int)((p1->z < p2->z) ? p2->z : p1->z);
	if (z > 36)
		draw_line(x, &l, COLOR_WHITE);
	else if (z > 0)
		draw_line(x, &l, COLOR_GREEN);
	else
		draw_line(x, &l, 0x000000b0);
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
			if ((plist[line + 1]) && (col < plist[line + 1]->size))
			{
				p2 = &plist[line + 1]->points[col];
				grid_intern(x, p1, p2);
			}
			if ((++col < plist[line]->size) && (p2 = &plist[line]->points[col]))
				grid_intern(x, p1, p2);
		}
		line++;
	}
}
