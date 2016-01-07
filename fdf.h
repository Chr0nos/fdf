/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:38:37 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/07 16:23:26 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <string.h>
# include "draw.h"

typedef struct	s_line_read
{
	int			*values;
	size_t		size;
}				t_line_read;

typedef struct	s_map
{
	t_line_read	*lines;
	size_t		size;
}				t_map;


t_map			*reader(int fd);
int				main(int ac, char **av);

#endif
