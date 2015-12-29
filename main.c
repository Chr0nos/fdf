/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 16:27:43 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/29 13:37:07 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "draw.h"
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
			free(split[++p2]);
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
		ft_lstpush_back(&lst, ft_lstnewstr(line));
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
			ret = draw(tab);
			free(tab);
		}
	}
	return (ret);
}
