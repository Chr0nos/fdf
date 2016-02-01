/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:38:37 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/01 16:44:35 by snicolet         ###   ########.fr       */
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

int				parser(t_list **lst, int fd);
int				main(int ac, char **av);

#endif
