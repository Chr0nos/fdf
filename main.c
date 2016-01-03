/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 16:27:43 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/03 23:31:11 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "draw.h"
#include "mlx.h"
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

static void		load_tab(t_tab *tab, t_list *lst)
{
	unsigned int	p;
	unsigned int	p2;
	char			**split;

	p = 0;
	split = NULL;
	while ((lst) && (!(p2 = 0)))
	{
		split = ft_strsplit((char *)(lst->content), ' ');
		while (split[p2])
		{
			tab->tab[p++] = ft_atoi(split[p2]);
			free(split[p2++]);
		}
		lst = lst->next;
	}
	tab->size = p;
}

static size_t	gettab_size(t_list *lst)
{
	size_t	size;

	size = 0;
	while (lst)
	{
		size += ft_strcount((char*)lst->content, ' ') + 1;
		lst = lst->next;
	}
	ft_printf("shit size: %d\n", (int)size);
	return (size);
}

static t_tab	*gettab(char *filepath)
{
	int		fd;
	int		ret;
	char	*line;
	t_list	*lst;
	t_tab	*tab;

	if (!(fd = open(filepath, O_RDONLY)))
		return (NULL);
	lst = NULL;
	while ((ret = ft_get_next_line(fd, &line)))
	{
		ft_lstpush_back(&lst, ft_lstnewstr(line));
		free(line);
	}
	if (!(tab = malloc(sizeof(*tab))))
		return (NULL);
	tab->tab = malloc(sizeof(int) * (gettab_size(lst)));
	if (!tab->tab)
	{
		free(tab);
		return (NULL);
	}
	load_tab(tab, lst);
	ft_lstdel(&lst, ft_lstpulverisator);
	return (tab);
}

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
	mlx_loop(x->mlxptr);
}

int				main(int ac, char **av)
{
	t_tab	*tab;
	int		ret;

	ret = 0;
	if (ac > 1)
	{
		tab = gettab(av[1]);
		if (tab)
		{
			display();
			free(tab);
		}
	}
	return (ret);
}
