/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 16:27:43 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/08 17:47:33 by snicolet         ###   ########.fr       */
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
	t_mlx	*x;

	x = (t_mlx*)userdata;
	if ((keycode == 53) || (keycode == 65307))
		exit(0);
	else
	{
		ft_putnbr(keycode);
		ft_putchar('\n');
	}
	return (0);
}

static void		display_grid(t_context *c)
{
	t_plist		**plist;

	if (!c->lines)
		return ;
	ft_putendl("getting points");
	if (!(plist = getpoints(c->lines)))
		return ;
	ft_putendl("tracing periemter");
	grid_init(c->x, plist);
	ft_putendl("freeing");
	draw_flush_image(c->x, c->x->img);
}

static void		display(t_context *c)
{
	t_matrix	m;
	t_matrix	iso;
	float		zoom;

	zoom = 0.04f;
	m = draw_make_matrix_z(draw_make_vector(0.2f, 0.2f, 0.5f), 0.2f,
			draw_make_vector(zoom, zoom, 1.5f));
	iso = draw_make_matrix_iso(0, 0, 800, 600);
	m = draw_matrix_multiply_matrix(m, &iso);
	ft_lstadd(&c->x->mstack, ft_lstnew(&m, sizeof(t_matrix)));
	display_grid(c);
	ft_lstdel(&c->x->mstack, &ft_lstpulverisator);
}

static t_mlx	*display_init(void)
{
	t_mlx	*x;

	x = draw_init("fdf", 800, 600);
	draw_flush_image(x, x->img);
	draw_sethook(x, &key_hook, x);
	return (x);
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
			c.x = display_init();
			display(&c);
			draw_loop(c.x);
		}
		else
			ft_putendl("error while opening file.");
	}
	return (0);
}
