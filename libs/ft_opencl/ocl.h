/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:08:13 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/27 17:27:34 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OCL_H
# define OCL_H
# define OCL_KERNEL_MAXSIZE 100000
# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif

typedef struct			s_ocl_platform
{
	cl_platform_id		platform_id;
	cl_device_id		*devices;
	cl_uint				num_devices;
	int					padding;
}						t_ocl_platform;

typedef struct			s_ocl
{
	t_ocl_platform		*platforms;
	cl_device_id		*devices;
	cl_platform_id		platform_id;
	cl_uint				num_platforms;
	int					padding;
	cl_context			context;
	cl_command_queue	cq;
	cl_program			program;
	cl_kernel			kernel;
}						t_ocl;

t_ocl					*ocl_init(void);
void					ocl_clean(t_ocl **ocl);
void					ocl_display_devices(t_ocl *ocl);
int						ocl_kernel_bufferize(const char *filepath, char *buff);

#endif
