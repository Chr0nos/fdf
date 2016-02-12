/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:54:37 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/09 18:56:02 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

static size_t		tabsize(char **tab)
{
	size_t		p;

	p = 0;
	while (tab[p])
		p++;
	return (p);
}

inline static void	init_itab(t_itab **itab, char **tab)
{
	size_t		size;

	size = tabsize(tab);
	*itab = malloc(sizeof(t_itab));
	(*itab)->values = malloc(sizeof(int) * size);
	(*itab)->size = size;
}

inline static void	clean(void *split, void *line)
{
	free(split);
	free(line);
}

inline static void	append(t_itab *itab, int p, char **split)
{
	itab->values[p] = ft_atoi(split[p]);
	free(split[p]);
}

int					parser(t_list **lst, int fd)
{
	char		*line;
	char		**split;
	int			p;
	int			maxp;
	t_itab		*itab;

	maxp = 0;
	while (ft_get_next_line(fd, &line))
	{
		//ft_putendl(line);
		if (!(split = ft_strsplit(line, ' ')))
			return (-1);
		init_itab(&itab, split);
		p = 0;
		while (split[p])
			append(itab, p++, split);
		if (p > maxp)
			p = maxp;
		clean(split, line);
		ft_lstpush_back(lst, ft_lstnewlink(itab, 0));
	}
	return (maxp);
}
