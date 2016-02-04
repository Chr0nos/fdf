/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 13:57:45 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/04 14:01:15 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	grid_init(t_mlx *x, t_plist **plist)
{
	size_t		line;
	size_t		col;
	t_line		l;
	t_vector	*p1;
	t_vector	*p2;

	line = 0;
	while ((plist[line]) && (!(col = 0)))
	{
		while (col < plist[line]->size)
		{
			p1 = plist[line]->points[col];
			if (plist[line + 1])
			{
				p2 = plist[line + 1]->points[col];
			}
			col++;
		}
	}
}
