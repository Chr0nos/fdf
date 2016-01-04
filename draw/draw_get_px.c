/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_get_px.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 22:12:16 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/04 22:16:31 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int	draw_get_px(t_mlx *x, const t_point *point)
{
	int	color;
	int	octet;
	int	position;

	octet = x->img->bpp / 8;
	position = (x->img->width * point->y) + (point->x * octet);
	ft_memcpy(&color, x->img->data + position, octet);
	return (color);
}
