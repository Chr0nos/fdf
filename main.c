/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 16:27:43 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/09 19:48:36 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "draw.h"
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>


inline static void	display_grid(t_context *c)
{
	t_plist		**plist;

	if (!c->lines)
		return ;
	if (!(plist = getpoints(c->lines)))
		return ;
	grid_init(c->x, plist);
	draw_flush_image(c->x, c->x->img);
	clean_points(plist);
}

void				display(t_context *c, const t_scales *scales)
{
	t_matrix	m1;
	t_matrix	m2;

	m2 = draw_make_matrix_z(draw_make_vector(0.0f, 0.0f, 0.0f), scales->rz,
			draw_make_vector(1.0f, 1.0f, 1.0f));
	m1 = draw_make_matrix_x(draw_make_vector(0.2f, 0.2f, 0.5f), scales->rx,
			draw_make_vector(1.0f, 1.0f, 1.0f));
	m1 = draw_matrix_multiply_matrix(m1, &m2);
	m2 = draw_make_matrix_ortho(
			draw_make_vector(scales->zoom, scales->zoom, scales->zoom_z),
			scales->offsets);
	m1 = draw_matrix_multiply_matrix(m1, &m2);
	m2 = draw_make_matrix_iso(0, 0, 1280, 1024);
	m1 = draw_matrix_multiply_matrix(m1, &m2);
	c->x->gtransform = m1;
	draw_reset_image(c->x, 0x0);
	display_grid(c);
}

static void			display_init(t_context *c)
{
	c->x = draw_init("fdf", 1280, 1024);
	draw_flush_image(c->x, c->x->img);
	draw_sethook(c->x, &key_hook, c);
}

int					main(int ac, char **av)
{
	int				fd;
	t_context		c;
	const t_scales	scale = { 0.04f, 0.8f, -0.2f, -4.0f, { 0.08f, 0.0f, 0.1f} };

	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd >= 0)
		{
			c.lines = NULL;
			parser(&c.lines, fd);
			close(fd);
			display_init(&c);
			display(&c, &scale);
			draw_loop(c.x);
		}
		else
			ft_putendl("error while opening file.");
	}
	return (0);
}
