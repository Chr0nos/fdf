/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:32:12 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/07 17:17:13 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <string.h>

static size_t	tabsize(char **tab)
{
	size_t	p;

	p = 0;
	while (tab[p] != NULL)
		p++;
	return (p);
}

static int		parser(t_list *lst, t_map *map)
{
	char	**split;
	size_t	line;
	size_t	col;
	size_t	columns_count;

	line = 0;
	while (lst)
	{
		col = 0;
		split = ft_strsplit((char*)lst->content, ' ');
		columns_count = tabsize(split);
		if (!(map->lines[line].values = malloc(sizeof(int) * columns_count)))
			return (0);
		map->lines[line].size = columns_count;
		while (split[col])
		{
			map->lines[line].values[col] = ft_atoi(split[col]);
			free(split[col]);
			col++;
		}
		free(split);
		line++;
		lst = lst->next;
	}
	return (1);
}

int				cleaner(t_map **map)
{
	while ((*map)->size--)
		free((*map)->lines[(*map)->size].values);
	free((*map)->lines);
	*map = NULL;
	return (1);
}

t_map			*reader(int fd)
{
	t_map	*map;
	char	*line;
	int		ret;
	t_list	*lst;

	if (!(map = malloc(sizeof(t_map))))
		return (NULL);
	lst = 0;
	while ((ret = ft_get_next_line(fd, &line)))
	{
		ft_lstpush_back(&lst, ft_lstnewstr(line));
		free(line);
	}
	map->size = ft_lstsize(lst);
	if (!(map->lines = malloc(sizeof(t_line_read) * map->size)))
	{
		free(map);
		return (NULL);
	}
	if ((!parser(lst, map)) && (cleaner(&map)))
		ft_putendl("parser has failed: gtfo");
	return (map);
}
