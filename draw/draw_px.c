/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:13:28 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/29 17:06:34 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"

void	draw_px(t_mlx *x, t_point *point, int color)
{
	t_mlx_img		*buffer;
	size_t			octect;
	size_t			position;
	size_t			bw;

	buffer = x->img;
	bw = (size_t)buffer->width;
	octect = bw / (size_t)x->width;
	if (point->y > 0)
		point->y -= 1;
	position = (bw * (size_t)point->y) + ((size_t)point->x * octect);
	ft_printf("buffer: %p data: %p position: %d\n", buffer, buffer->data, (int)position);
	if (ft_memcmp(buffer->data + position, &color, octect) != 0)
		ft_memcpy(buffer->data + position, &color, octect);
}
