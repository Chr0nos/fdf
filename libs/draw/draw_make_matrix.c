/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:02:31 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/13 14:31:15 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

t_matrix	draw_make_matrix(t_vector pos, float rad, t_vector scale)
{
	t_matrix	m;

	m.x = draw_make_vector(cosf(rad) * scale.x, -sinf(rad) * scale.x, 0.0f);
	m.y = draw_make_vector(sinf(rad) * scale.y, cosf(rad) * scale.y, 0.0f);
	m.z = pos;
	return (m);
}
