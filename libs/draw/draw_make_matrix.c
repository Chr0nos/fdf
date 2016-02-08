/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:02:31 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/08 15:43:16 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

t_matrix	draw_make_matrix_x(t_vector pos, float rad, t_vector scale)
{
	t_matrix	m;

	m.x = draw_make_vector(1.0f, 1.0f, 1.0f);
	m.y = draw_make_vector(1.0f, cosf(rad) * scale.y, -sinf(rad) * scale.y);
	m.z = draw_make_vector(1.0f, -sinf(rad) * scale.z, cosf(rad) * scale.z);
	m.offset = pos;
	return (m);
}

t_matrix	draw_make_matrix_y(t_vector pos, float rad, t_vector scale)
{
	t_matrix	m;

	m.x = draw_make_vector(cosf(rad) * scale.x, 1.0f, -sinf(rad) * scale.x);
	m.y = draw_make_vector(1.0f, 1.0f, 1.0f);
	m.z = draw_make_vector(-sinf(rad) * scale.z, 1.0f, cosf(rad) * scale.z);
	m.offset = pos;
	return (m);
}

t_matrix	draw_make_matrix_z(t_vector pos, float rad, t_vector scale)
{
	t_matrix	m;

	m.x = draw_make_vector(cosf(rad) * scale.x, -sinf(rad) * scale.x, 1.0f);
	m.y = draw_make_vector(sinf(rad) * scale.y, cosf(rad) * scale.y, 1.0f);
	m.z = draw_make_vector(1.0f, 1.0f, 1.0f);
	m.offset = pos;
	return (m);
}
