/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_matrix_multiply_matrix.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:33:40 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/08 16:54:04 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_matrix	draw_matrix_multiply_matrix(t_matrix m1, const t_matrix *m2)
{
	m1.x = draw_matrix_multiply(m1.x, m2);
	m1.y = draw_matrix_multiply(m1.y, m2);
	m1.z = draw_matrix_multiply(m1.z, m2);
	m1.offset = draw_matrix_multiply(m1.offset, m2);
	return (m1);
}
