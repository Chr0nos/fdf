/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:38:37 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/04 18:05:10 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <string.h>
# include "libft.h"
# include "draw.h"

typedef	struct	s_itab
{
	int			*values;
	size_t		size;
}				t_itab;

typedef struct	s_context
{
	t_mlx		*x;
	t_list		*lines;
}				t_context;

typedef struct	s_plist
{
	t_vector	*points;
	size_t		size;
}				t_plist;

int				parser(t_list **lst, int fd);
int				main(int ac, char **av);
t_plist			**getpoints(t_list *lst);
void			grid_init(t_mlx *x, t_plist **plist);

#endif
