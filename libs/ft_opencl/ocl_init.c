/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:05:28 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/04 01:21:11 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ocl.h"
#include "libft.h"
#include <string.h>
#include <stdlib.h>

static void	ocl_setup_buffer(t_ocl *ocl)
{
	cl_int err;

	ocl->context = clCreateContext(NULL, 1,
		ocl->platforms[0].devices, NULL, ocl->userdata, &err);
	if (err)
		ocl_showerror("context failure", err);
	else
	{
		ocl->buffer = clCreateBuffer(ocl->context,
			CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR,
			ocl->hostsize,
			ocl->hostptr,
			&err);
		if (err)
			ocl_showerror("create buffer failure", err);
	}
}

static int	ocl_setup_devices(t_ocl *ocl, unsigned int pid)
{
	ocl->platforms[pid].devices = NULL;
	clGetDeviceIDs(ocl->platforms[pid].platform_id,
		CL_DEVICE_TYPE_ALL, 0, NULL, &ocl->platforms[pid].num_devices);
	ocl->platforms[pid].devices = malloc(sizeof(cl_device_id) *
		(ocl->platforms[pid].num_devices));
	if (!ocl->platforms[pid].devices)
		return (-1);
	clGetDeviceIDs(ocl->platforms[pid].platform_id, CL_DEVICE_TYPE_GPU,
		ocl->platforms[pid].num_devices, ocl->platforms[pid].devices, NULL);
	ocl_setup_buffer(ocl);
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
	ocl->buffer = NULL;
	ocl_setup_platforms(ocl);
}

t_ocl		*ocl_init(void *userdata, void *hostptr, size_t hsize)
{
	t_ocl	*ocl;

	if (!(ocl = malloc(sizeof(t_ocl))))
		return (NULL);
	ocl->userdata = userdata;
	ocl->hostptr = hostptr;
	ocl->hostsize = hsize;
	ocl_setup(ocl);
	return (ocl);
}
