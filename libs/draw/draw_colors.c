/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 23:34:49 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/16 15:35:49 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int		draw_color_hsv(t_hsv *hsv)
{
	int		color;

	color = 0;
	if (hsv->h > 360)
		hsv->h %= 360;
	color = hsv->v * hsv->s * (hsv->h * hsv->s * hsv->v);
	return (color);
}
