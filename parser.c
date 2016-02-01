/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:54:37 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/01 16:37:56 by snicolet         ###   ########.fr       */
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

static void		init_itab(t_itab **itab, char **tab)
{
	size_t		size;

	size = tabsize(tab);
	*itab = malloc(sizeof(t_itab));
	(*itab)->values = malloc(sizeof(int) * size);
	(*itab)->size = size;
}

int				parser(t_list **lst, int fd)
{
	char		*line;
	char		**split;
	int			p;
	t_itab		*itab;

	while (ft_get_next_line(fd, &line))
	{
		ft_printf("line: %s\n", line);
		if (!(split = ft_strsplit(line, ' ')))
			return (-1);
		init_itab(&itab, split);
		p = 0;
		while (split[p])
		{
			itab->values[p] = ft_atoi(split[p]);
			free(split[p]);
			p++;
		}
		free(split);
		free(line);
		ft_lstpush_back(lst, ft_lstnewlink(itab, 0));
	}
	return (0);
}
