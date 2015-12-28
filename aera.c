/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aera.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 21:29:40 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/28 21:34:18 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <string.h>

t_aera	*make_aera(int x, int y, int ex, int ey)
{
	t_aera	*aera;

	if (!(aera = malloc(sizeof(t_aera))))
		return (NULL);
	aera->start.x = x;
	aera->start.y = y;
	aera->end.x = ex;
	aera->end.y = ey;
	return (aera);
}
