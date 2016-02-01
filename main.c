/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 16:27:43 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/01 18:52:18 by snicolet         ###   ########.fr       */
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

static void			display_grid(t_context *c)
{
	t_list			*lst;
	t_line			traced_line;
	size_t			line;
	size_t			column;
	t_itab			*itab;

	lst = c->lines;
	line = 1;
	while (lst)
	{
		itab = lst->content;
		column = 0;
		while (column < itab->size)
		{
			traced_line = draw_make_line((int)column * 20,
					(int)line * 20,
					(int)(column + 1) * 20,
					(int)(line + 1) * 20);
			draw_line(c->x, &traced_line, COLOR_RED);
			column++;
		}
		lst = lst->next;
	}
	draw_flush_image(c->x, c->x->img);
}

static void			display(t_context *c)
{
	display_grid(c);
}

static t_mlx		*display_init(void)
{
	t_mlx	*x;

	x = draw_init("fdf", 800, 600);
	draw_flush_image(x, x->img);
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
