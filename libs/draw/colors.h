/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 15:30:21 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/16 15:33:47 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

typedef struct		s_hsv
{
	int				h;
	float			s;
	float			v;
}					t_hsv;

typedef struct		s_rgb
{
	unsigned int	r:1;
	unsigned int	g:1;
	unsigned int	b:1;
}					t_rgb;

#endif
