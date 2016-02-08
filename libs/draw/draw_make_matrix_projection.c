/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_matrix_projection.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:04:58 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/08 16:33:04 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_matrix	draw_make_matrix_iso(int x, int y, int w, int h)
{
	t_matrix		m;

	m.x = draw_make_vector((float)w, 0.0f, 0.0f);
	m.y = draw_make_vector(0.0f, (float)h, 0.0f);
	m.z = draw_make_vector(0.0f, 0.0f, 1.0f);
	m.offset = draw_make_vector(x, y, 0.0f);
	return (m);
}
