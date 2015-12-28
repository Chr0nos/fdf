/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 16:27:43 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/28 19:05:02 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"
#include <math.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

static void		draw_rect(t_mlx *x, t_aera *aera, int color)
{
	const int		end = aera->end.x * aera->end.y + 1;
	int				px;

	px = aera->start.x * aera->start.y;
	while (px < end)
	{
		mlx_pixel_put(x->mlxptr,
				x->winptr,
				aera->start.x + (px / (aera->end.x - aera->start.x)),
				aera->start.y + (px % (aera->end.x - aera->start.y)),
				color);
		++px;
	}
}

static int		draw(int *tab)
{
	t_mlx	x;
	t_aera	a;

	(void)tab;
	x.mlxptr = mlx_init();
	if (!x.mlxptr)
		return (1);
	if (!(x.winptr = mlx_new_window(x.mlxptr, 800, 600, "Coucou")))
		return (2);
	a.start.x = 42;
	a.start.y = 42;
	a.end.x = 442;
	a.end.y = 100;
	draw_rect(&x, &a, COLOR_GREEN);
	mlx_loop(x.mlxptr);
	return (0);
}

static int		*gettab(char *filepath)
{
	int		fd;
	int		ret;
	char	*line;
	t_list	*lst;
	int		*tab;

	if (!(fd = open(filepath, O_RDONLY)))
		return (NULL);
	lst = NULL;
	while ((ret = ft_get_next_line(fd, &line)))
		ft_lstpush_back(&lst, ft_lstnewstr(line));
	if (!(tab = malloc(sizeof(int) * ft_lstsize(lst))))
		return (NULL);
	while (lst)
	{
		lst = lst->next;
	}
	return (tab);
}

int				main(int ac, char **av)
{
	int		*tab;
	int		ret;

	draw(0);
	ret = 0;
	if (ac > 1)
	{
		tab = gettab(av[1]);
		if (tab)
		{
			ret = draw(tab);
			free(tab);
		}
	}
	return (ret);
}
