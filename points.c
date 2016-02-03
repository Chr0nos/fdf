/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:29:22 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/03 18:52:53 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "draw.h"
#include <stdlib.h>

t_plist		**getpoints(t_list *lst)
{
	t_plist		**plist;
	t_itab		*itab;
	size_t		lines;
	size_t		l;
	size_t		c;

	lines = ft_lstsize(lst);
	plist = malloc(sizeof(t_plist*) * (lines + 1));
	l = 0;
	while ((lst) && ((itab = lst->content)))
	{
		plist[l] = malloc(sizeof(t_plist));
		plist[l]->points = malloc(sizeof(t_point) * (itab->size + 1));
		c = 0;
		while (c < itab->size)
		{
			plist[l]->points[c].x = 20 + (int)(c * 40) + itab->values[c];
			plist[l]->points[c].y = 20 + (int)(l * 40) + itab->values[c];
			c++;
		}
		plist[l++]->size = c;
		lst = lst->next;
	}
	plist[l] = NULL;
	return (plist);
}
