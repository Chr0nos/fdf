/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 16:27:43 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/04 14:01:32 by snicolet         ###   ########.fr       */
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
	size_t		line;
	size_t		col;
	t_line		l;
	t_vector	*p1;

	if (!c->lines)
		return ;
	ft_putendl("getting points");
	if (!(plist = getpoints(c->lines)))
		return ;
	ft_putendl("tracing periemter");
	line = 0;
	while (plist[line])
	{
		//draw_perimeter(c->x, plist[line]->points, plist[line]->size, COLOR_CYAN);
		col = 0;
		while (col < plist[line]->size)
		{
			p1 = &plist[line]->points[col];
			if ((plist[line + 1]) && (col < plist[line + 1]->size))
			{
				l = draw_make_line((int)p1->x, (int)p1->y,
						(int)plist[line + 1]->points[col].x,
						(int)plist[line + 1]->points[col].y);
				draw_line(c->x, &l, COLOR_CYAN);
			}
			col++;
		}
		//draw_pxtab(c->x, plist[line]->points, plist[line]->size, COLOR_RED);
		line++;
	}
	ft_putendl("freeing");
	draw_flush_image(c->x, c->x->img);
}

static void		display(t_context *c)
{
	display_grid(c);
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
