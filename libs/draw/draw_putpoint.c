/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_putpoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 13:35:16 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/31 13:36:18 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "draw.h"

void	draw_putpoint(t_point *point)
{
	ft_printf("x: %d y: %d\n", point->x, point->y);
}
