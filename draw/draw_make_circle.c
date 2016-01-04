/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_circle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:16:11 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/04 13:18:00 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_circle	draw_make_circle(int x1, int y1, int x2, int y2)
{
	t_circle	c;

	c.start.x = x1;
	c.start.y = y1;
	c.end.x = x2;
	c.end.y = y2;
	return (c);
}
