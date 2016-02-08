/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_matrix_multiply.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:21:04 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/08 15:44:28 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_vector	draw_matrix_multiply(t_vector point, t_matrix *t)
{
	t_vector	v;

	v = draw_make_vector(
			(t->x.x * point.x) + (t->x.y * point.y) + (t->x.z * point.z) +
			t->offset.x,
			(t->y.x * point.x) + (t->y.y * point.y) + (t->y.z * point.z) +
			t->offset.y,
			(t->z.x * point.x) + (t->z.y * point.y) + (t->z.z * point.z) +
			t->offset.z);
	return (v);
}
