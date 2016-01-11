/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sethook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:58:22 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/11 17:04:28 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"

void	draw_sethook(t_mlx *x, int (*f)(int, void*), void *userdata)
{
	mlx_key_hook(x->winptr, f, userdata);
}
