/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocl_kernel_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 17:04:58 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/07 10:19:16 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ocl.h"
#include "libft.h"

//todo: fonction qui charge une ligne par element de tableau char[][]

int		ocl_kernel_init(t_ocl *ocl)
{
	char	kernel_source[OCL_KERNEL_MAXSIZE];
	cl_int	err;

	if (ocl_kernel_bufferize("/tmp/kernel.cl", kernel_source) < 0)
	{
		ft_putendl("failed to load kernel: unable to access to the file.");
		return (0);
	}
	ocl->program = clCreateProgramWithSource(ocl->context, 1,
		(const char **)&kernel_source, NULL, &err);
	if (ocl_strerrori("failed to load kernel", err))
		return (0);
	return (1);
}
