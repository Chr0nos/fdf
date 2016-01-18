/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_fixed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:33:12 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/18 15:45:40 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int		ft_int_to_fixed(int real, int decimal, int scale)
{
	const int	mask = 1 << (scale - 1);
	int			shift;

	if (!decimal)
		return ((real << scale));
	shift = 0;
	while ((shift < scale) && (!((decimal << shift) & mask)))
		shift++;
	return ((real << scale) | (decimal << shift));
}
