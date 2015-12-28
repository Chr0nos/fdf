/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 16:27:43 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/28 19:14:04 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

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
