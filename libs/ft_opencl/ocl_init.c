/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:05:28 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/27 15:52:53 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ocl.h"
#include "libft.h"
#include <string.h>
#include <stdlib.h>

static int	ocl_setup_devices(t_ocl *ocl, unsigned int pid)
{
	ocl->platforms[pid].devices = NULL;
	clGetDeviceIDs(ocl->platforms[pid].platform_id,
		CL_DEVICE_TYPE_ALL,	0, NULL, &ocl->platforms[pid].num_devices);
	ocl->platforms[pid].devices = malloc(sizeof(cl_device_id) *
		(ocl->platforms[pid].num_devices));
	clGetDeviceIDs(ocl->platforms[pid].platform_id, CL_DEVICE_TYPE_ALL,
		ocl->platforms[pid].num_devices, ocl->platforms[pid].devices, NULL);
	return (0);
}

static int	ocl_setup_platforms(t_ocl *ocl)
{
	cl_uint		p;

	clGetPlatformIDs(0, NULL, &ocl->num_platforms);
	if (ocl->num_platforms < 1)
		return (0);
	ocl->platforms = malloc(sizeof(t_ocl_platform) * (ocl->num_platforms));
	if (!ocl->platforms)
		return (0);
	p = 0;
	while (p < ocl->num_platforms)
	{
		clGetPlatformIDs(1, &ocl->platforms[p].platform_id, NULL);
		ocl_setup_devices(ocl, p);
		p++;
	}
	return (1);
}

static void	ocl_setup(t_ocl *ocl)
{
	ocl->platform_id = NULL;
	ocl->context = NULL;
	ocl->cq = NULL;
	ocl->program = NULL;
	ocl->kernel = NULL;
	ocl_setup_platforms(ocl);
}

t_ocl		*ocl_init(void)
{
	t_ocl	*ocl;

	if (!(ocl = malloc(sizeof(t_ocl))))
		return (NULL);
	ocl_setup(ocl);
	return (ocl);
}
