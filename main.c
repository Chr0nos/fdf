/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 16:27:43 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/08 20:44:48 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "draw.h"
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int		key_hook(int keycode, void *userdata)
{
	t_context		*c;
	static float	rx = 0.8f;
	static float	rz = -0.2f;
	static float	zoom = 0.04f;

	c = userdata;
	if ((keycode == 53) || (keycode == 65307))
		exit(0);
	else if ((keycode == 126) || (keycode == 125))
		rx += (keycode == 126) ? 0.1f : -0.1f;
	else if ((keycode == 124) || (keycode == 123))
		rz += (keycode == 124) ? 0.1f : -0.1f;
	else if ((keycode == 24) || (keycode == 27))
		zoom += (keycode == 24) ? 0.001f : -0.001f;
	else
	{
		ft_putnbr(keycode);
		ft_putchar('\n');
	}
	display(c, rx, rz, zoom);
	return (0);
}

static void		display_grid(t_context *c)
{
	t_plist		**plist;

	if (!c->lines)
		return ;
	if (!(plist = getpoints(c->lines)))
		return ;
	grid_init(c->x, plist);
	draw_flush_image(c->x, c->x->img);
}

void			display(t_context *c, const float rx, const float rz,
		const float zoom)
{
	t_matrix	m1;
	t_matrix	m2;

	m2 = draw_make_matrix_z(draw_make_vector(0.0f, 0.0f, 0.0f), rz,
			draw_make_vector(1.0f, 1.0f, -4.0f));
	m1 = draw_make_matrix_x(draw_make_vector(0.2f, 0.2f, 0.5f), rx,
			draw_make_vector(zoom, zoom, 1.0f));
	m1 = draw_matrix_multiply_matrix(m1, &m2);
	m2 = draw_make_matrix_iso(0, 0, 1024, 768);
	m1 = draw_matrix_multiply_matrix(m1, &m2);
	c->x->gtransform = m1;
	draw_reset_image(c->x, 0x0);
	display_grid(c);
}

static void		display_init(t_context *c)
{
	c->x = draw_init("fdf", 1024, 768);
	draw_flush_image(c->x, c->x->img);
	draw_sethook(c->x, &key_hook, c);
}

int				main(int ac, char **av)
{
	int			fd;
	t_context	c;

	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd >= 0)
		{
			c.lines = NULL;
			parser(&c.lines, fd);
			close(fd);
			display_init(&c);
			display(&c, 0.8f, -0.2f, 0.04f);
			draw_loop(c.x);
		}
		else
			ft_putendl("error while opening file.");
	}
	return (0);
}
