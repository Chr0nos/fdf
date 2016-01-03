/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_reset_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 19:53:02 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/03 20:21:51 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"

void	draw_reset_image(t_mlx *x, int color)
{
	const size_t	block = (size_t)x->img->bpp / 8;
	const size_t	size = (size_t)x->width * (size_t)x->height * block;
	size_t			p;

	p = 0;
	while (p < size)
	{
		ft_memcpy(x->img->data + p, &color, block);
		p += block;
	}
}
