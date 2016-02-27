/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocl_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 15:57:23 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/27 16:00:44 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ocl.h"
#include <string.h>
#include <stdlib.h>

void	ocl_clean(t_ocl **ocl)
{
	unsigned int	p;
	t_ocl			*o;

	o = *ocl;
	p = 0;
	while (p < o->num_platforms)
	{
		free(o->platforms[p].devices);
		p++;
	}
	free(o->platforms);
	*ocl = NULL;
}
