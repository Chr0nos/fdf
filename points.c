/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:29:22 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/02 14:17:08 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "draw.h"
#include <stdlib.h>

static size_t	get_points_count(t_list *lst)
{
	size_t		p;

	p = 0;
	while (lst)
	{
		p += ((t_itab*)(lst->content))->size;
		lst = lst->next;
	}
	return (p);
}

t_plist		*getpoints(t_list *lst)
{
	t_plist		*plist;
	t_itab		*itab;
	size_t		line;
	size_t		col;
	size_t		idx;

	if (!(plist = malloc(sizeof(t_plist))))
		return (NULL);
	plist->size = get_points_count(lst);
	if (!(plist->points = malloc(sizeof(t_point) * plist->size)))
		return (NULL);
	line = 0;
	idx = 0;
	while (lst)
	{
		col = 0;
		itab = lst->content;
		while (col < itab->size)
		{
			plist->points[idx++] = draw_make_px(20 + (int)(col * 40),
					20 + (int)(line * 40));
			col++;
		}
		line++;
		lst = lst->next;
	}
	return (plist);
}
