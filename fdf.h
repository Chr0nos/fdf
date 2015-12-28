/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:38:37 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/28 18:19:14 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define COLOR_WHITE 0xffffff
# define COLOR_BLUE 0x0000ff
# define COLOR_RED 0xff0000
# define COLOR_GREEN 0x00ff00

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_aera
{
	t_point		start;
	t_point		end;
}				t_aera;

typedef struct	s_mlx
{
	void		*mlxptr;
	void		*winptr;
}				t_mlx;

int		main(int ac, char **av);

#endif
