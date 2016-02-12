/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sethook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:58:22 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/12 19:27:37 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"

void	draw_sethook(t_mlx *x, int (*f)(int, void*), void *userdata)
{
	mlx_key_hook(x->winptr, f, userdata);
}

void	draw_sethook_keydown(t_mlx *x, int (*f)(void*), void *userdata)
{
	mlx_hook(x->winptr, 2, -1, f, userdata);
}

void	draw_sethook_keyrlz(t_mlx *x, int (*f)(void*), void *userdata)
{
	mlx_hook(x->winptr, 3, -1, f, userdata);
}
