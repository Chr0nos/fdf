/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 16:27:43 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/28 20:30:39 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

static void		load_tab(int *tab, t_list *lst)
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
			tab[p++] = ft_atoi(split[p2]);
			free(split[p2]);
			++p2;
		}
		lst = lst->next;
	}
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
	load_tab(tab, lst);
	ft_lstdel(&lst, ft_lstpulverisator);
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
