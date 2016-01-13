/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 16:27:43 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/13 13:35:00 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "draw.h"
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void		displayi(t_mlx *x, t_map *map)
{
	int		line;
	int		col;
	t_line	dline;
	t_point	start;
	int		value;

	line = 0;
	while (line < (int)map->size)
	{
		col = 0;
		start.y = 10 + line * 40;
		while (col < (int)map->lines[line].size)
		{
			value = map->lines[line].values[col];
			ft_printf("value: %d\n", value);
			start.x = 10 + col * 40;
			dline = draw_make_line(start.x,	start.y,
					start.x + 40, start.y + 40);
			draw_line(x, &dline, COLOR_GREEN);

			dline = draw_make_line(start.x, start.y + 40,
					start.x + 20, start.y + 40);
			draw_line(x, &dline, COLOR_WHITE);
			col++;
		}
		line++;
	}
}

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

static void		display(t_map *map)
{
	t_mlx	*x;

	x = draw_init("fdf", 800, 600);
	draw_flush_image(x, x->img);
	displayi(x, map);
	draw_flush_image(x, x->img);
	draw_sethook(x, &key_hook, x);
	draw_loop(x);
}

int				main(int ac, char **av)
{
	t_map	*map;
	int		fd;

	map = NULL;
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd >= 0)
		{
			map = reader(fd);
			close(fd);
			if (map)
			{
				ft_printf("tab size: %d", (int)map->size);
				display(map);
				cleaner(&map);
			}
			else
				ft_putendl("error bordel !");
		}
		else
			ft_putendl("error while opening file.");
	}
	return (0);
}
