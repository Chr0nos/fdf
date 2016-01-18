/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 12:23:45 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/18 15:44:35 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include <stdio.h>

int	main(void)
{
	int		scale;
	int		x;

	scale = 20;
	x = ft_double_to_fixed(42.318, scale);
	x = 44358192;
	printf("x: %d\n", x);
	printf("directe: %d\n", ft_int_to_fixed(42, 318, 20));
	printf("reel: %d\n", ft_fixed_to_real(x, scale));
	printf("virgule: %d\n", ft_fixed_decimal(x, scale));
	printf("masque: %d\n", INTMAX << (32 - scale));
	return (0);
}
