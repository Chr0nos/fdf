/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:38:37 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/28 21:34:04 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <string.h>
# define COLOR_WHITE 0xffffff
# define COLOR_BLUE 0x0000ff
# define COLOR_RED 0xff0000
# define COLOR_GREEN 0x00ff00

typedef struct	s_tab
{
	size_t		size;
	int			*tab;
}				t_tab;

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

t_aera	*make_aera(int x, int y, int ex, int ey);
int		draw(t_tab *tab);
void	draw_rect(t_mlx *x, t_aera *aera, int color);
void	draw_line(t_mlx *x, t_aera *aera, int color);
void	draw_grid(t_mlx *x, t_tab *tab);
int		main(int ac, char **av);

#endif
