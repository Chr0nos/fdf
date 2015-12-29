/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aera.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 21:29:40 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/29 10:23:28 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <string.h>

t_aera	*set_aera(t_aera *aera, t_point start, t_point end)
{
	aera->start.x = start.x;
	aera->start.y = start.y;
	aera->end.x = end.x;
	aera->end.y = end.y;
	return (aera);
}

t_aera	*make_aera(int x, int y, int ex, int ey)
{
	t_aera	*aera;
	t_point	start;
	t_point	end;

	if (!(aera = malloc(sizeof(t_aera))))
		return (NULL);
	start.x = x;
	start.y = y;
	end.x = ex;
	end.y = ey;
	return (set_aera(aera, start, end));
}
