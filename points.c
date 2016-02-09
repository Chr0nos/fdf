/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:29:22 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/09 20:06:45 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "draw.h"
#include <stdlib.h>

void				clean_points(t_plist **plist)
{
	size_t	p;

	p = 0;
	while (plist[p])
		free(plist[p++]->points);
	free(plist);
}

inline static int	create_points(t_plist **plist, const size_t size)
{
	if (!(*plist = malloc(sizeof(t_plist))))
		return (0);
	if (!((*plist)->points = malloc(sizeof(t_vector) * (size + 1))))
	{
		free(*plist);
		return (0);
	}
	return (1);
}

t_plist				**getpoints(t_list *lst)
{
	t_plist		**plist;
	t_itab		*itab;
	size_t		lines;
	size_t		l;
	size_t		c;

	lines = ft_lstsize(lst);
	plist = malloc(sizeof(t_plist*) * (lines + 1));
	l = 0;
	while ((lst) && ((itab = lst->content)) &&
			(create_points(&plist[l], itab->size)))
	{
		c = 0;
		while (c < itab->size)
		{
			plist[l]->points[c] = draw_make_vector((float)c, (float)l,
					(float)itab->values[c]);
			c++;
		}
		plist[l++]->size = c;
		lst = lst->next;
	}
	plist[l] = NULL;
	return (plist);
}
