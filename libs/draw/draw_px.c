/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:13:28 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/12 12:57:27 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"

void	draw_px(t_mlx *x, const t_point *point, int color)
{
	const int	octet = x->img->bpp / 8;
	int			position;

	position = (x->img->width * point->y) + (point->x * octet);
	if (ft_memcmp(x->img->data + position, &color, (unsigned)octet) != 0)
		ft_memcpy(x->img->data + position, &color, (unsigned)octet);
}
