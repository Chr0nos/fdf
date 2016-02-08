/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:02:31 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/08 17:33:33 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

t_matrix	draw_make_matrix_x(t_vector pos, float rad, t_vector scale)
{
	t_matrix		m;
	const float 	s = sinf(rad);
	const float		c = cosf(rad);

	m.x = draw_make_vector(scale.x, scale.y, scale.z);
	m.y = draw_make_vector(scale.x, c * scale.y, s * scale.z);
	m.z = draw_make_vector(scale.x, -s * scale.y, c * scale.z);
	m.offset = pos;
	return (m);
}

t_matrix	draw_make_matrix_y(t_vector pos, float rad, t_vector scale)
{
	t_matrix		m;
	const float 	s = sinf(rad);
	const float		c = cosf(rad);

	m.x = draw_make_vector(c * scale.x, scale.y, -s * scale.z);
	m.y = draw_make_vector(scale.x, scale.y, scale.z);
	m.z = draw_make_vector(s * scale.x, scale.y, c * scale.z);
	m.offset = pos;
	return (m);
}

t_matrix	draw_make_matrix_z(t_vector pos, float rad, t_vector scale)
{
	t_matrix		m;
	const float 	s = sinf(rad);
	const float		c = cosf(rad);

	m.x = draw_make_vector(c * scale.x, -s * scale.y, scale.z);
	m.y = draw_make_vector(s * scale.x, c * scale.y, scale.z);
	m.z = draw_make_vector(scale.x, scale.y, scale.z);
	m.offset = pos;
	return (m);
}
