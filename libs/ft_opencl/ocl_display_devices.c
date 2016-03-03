/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocl_display_devices.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 15:44:39 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/03 17:18:38 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ocl.h"
#include "libft.h"

void	ocl_display_devices(t_ocl *ocl)
{
	char		buffer[128];
	cl_uint		p;
	cl_uint		d;
	int			cores;

	ft_memset(buffer, 0, 128);
	p = 0;
	while (p < ocl->num_platforms)
	{
		d = 0;
		while (d < ocl->platforms[p].num_devices)
		{
			clGetDeviceInfo(ocl->platforms[p].devices[d], CL_DEVICE_NAME,
				128, buffer, NULL);
			ft_stralign_right(buffer, 40);
			ft_printf("device[%d]: %s", (int)d, buffer);
			clGetDeviceInfo(ocl->platforms[p].devices[d],
				CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(cores), &cores, NULL);
			ft_printf(" -> units cores: %d\n", cores);
			d++;
		}
		p++;
	}
}
