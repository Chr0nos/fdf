/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:13:28 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/30 13:39:51 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"

void	draw_px(t_mlx *x, t_point *point, int color)
{
	int			octet;
	int			position;

	octet = x->img->bpp / 8;
	position = (x->width * point->y) + (point->x * octet);
	if (ft_memcmp(x->img->data + position, &color, (unsigned)octet) != 0)
		ft_memcpy(x->img->data + position, &color, (unsigned)octet);
}
