/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:58:55 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/18 13:35:31 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H
# define INTMAX 2147483647
# define INTMIN -2147483648

int		ft_double_to_fixed(double x, int scale);
int		ft_fixed_to_real(int x, int scale);
int		ft_fixed_decimal(int x, int scale);

#endif
