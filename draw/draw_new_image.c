/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_new_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:41:47 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/30 11:53:48 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"
#include "libft.h"
#include <stdlib.h>

void	draw_new_image(t_mlx *x)
{
	t_mlx_img	*img;

	img = (t_mlx_img*)malloc(sizeof(t_mlx_img));
	if (img)
	{
		img->endian = 0;
		img->width = x->width;
		img->img = mlx_new_image(x->mlxptr, x->width, x->height);
		if (img->img)
		{
			img->data = mlx_get_data_addr(img->img, &img->bpp, &x->width,
					&img->endian);
			x->img = img;
			ft_printf("new image: %p - data %p - bpp: %d\n", img->img, img->data, img->bpp);
		}
	}
}
