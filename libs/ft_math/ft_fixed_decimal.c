/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fixed_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 12:07:50 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/18 14:49:54 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int		ft_fixed_decimal(int x, int scale)
{
	int		mask;

	mask = INTMAX >> (31 - scale);
	return (x & mask);
}
