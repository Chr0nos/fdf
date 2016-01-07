/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 16:27:43 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/07 17:18:46 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "draw.h"
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void		display(void)
{
	t_mlx	*x;
	t_line	a;
	t_rect	r;
	char	name[20];

	ft_strcpy(name, "Coucou");
	x = draw_init(name, 800, 600);
	draw_reset_image(x, 0x003030);
	r = draw_make_rect(50, 50, 200, 200);
	draw_rect_fill(x, &r, 0x000f10);
	//en bas a droite
	a = draw_make_line(100, 100, 800, 600);
	draw_line(x, &a, COLOR_WHITE);
	//en bas a gauche
	a = draw_make_line(100, 100, 0, 600);
	draw_line(x, &a, COLOR_BLUE);
	//en haut a droite
	a = draw_make_line(100, 100, 800, 0);
	draw_line(x, &a, COLOR_GREEN);
	//en haut a gauche
	a = draw_make_line(100, 100, 0, 0);
	draw_line(x, &a, COLOR_RED);

	r = draw_make_rect(50, 50, 200, 200);
	draw_rect(x, &r, 0xa0f0c0);
	draw_flush_image(x, x->img);
	//draw_clear(x);
	draw_loop(x);
}

int				main(int ac, char **av)
{
	t_map	*map;
	int		fd;

	map = NULL;
	(void)display;
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd >= 0)
		{
			map = reader(fd);
			if (map)
			{
				ft_printf("tab size: %d", (int)map->size);
				cleaner(&map);
			}
			else
				ft_putendl("error bordel !");
			close(fd);
		}
		(void)av;
	}
	return (0);
}
