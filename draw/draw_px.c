/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:13:28 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/03 20:16:24 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"

void	draw_px(t_mlx *x, t_point *point, int color)
{
	int			octet;
	int			position;

	//ft_printf("putting pixel: x: %d --- y: %d\n", point->x, point->y);
	octet = x->img->bpp / 8;
	position = (x->img->width * point->y) + (point->x * octet);
	if (ft_memcmp(x->img->data + position, &color, (unsigned)octet) != 0)
		ft_memcpy(x->img->data + position, &color, (unsigned)octet);
}
