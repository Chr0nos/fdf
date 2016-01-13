/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rotate_pxmap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:34:51 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/13 02:29:10 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "math.h"

t_point	*draw_rotate_pxmap(t_point *map, size_t size, int angle, t_point center)
{
	size_t		p;

	(void)center;
	if ((!size) || (angle == 360) || (angle == -360))
		return (map);
	if ((angle > 360) || (angle < 360))
		angle %= 360;
	p = 0;
	while (p < size)
	{
		map[p].x = (int)((float)map[p].x * cos(0) - (float)map[p].y * sin(0));
		map[p].y = (int)((float)map[p].x * sin(0) + (float)map[p].y * cos(0));
		p++;
	}
	return (map);
}
