/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocl_kernel_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 17:04:58 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/07 13:24:24 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ocl.h"
#include "libft.h"
#include <stdlib.h>

//todo: fonction qui charge une ligne par element de tableau char[][]

static void	kernel_display(const char **kernel)
{
	unsigned int	p;

	ft_putendl("kernel source:");
	p = 0;
	while (kernel[p])
		ft_putendl(kernel[p++]);
	ft_putendl("end of kernel source");
}

static void	clean_split(char **tab)
{
	unsigned int	p;

	p = 0;
	while (tab[p])
		free(tab[p++]);
	free(tab);
}

static int	ocl_kernel_load(t_ocl *ocl, const char *kernel_source)
{
	char		**kernel_split;
	const char	***kernel_const;
	cl_int		err;

	err = 0;
	ft_putendl("splitting kernel source");
	if (!(kernel_split = ft_strsplit(kernel_source, '\n')))
		return (-2);
	ft_putendl("loading kernel source");
	kernel_const = (const char ***)&kernel_split;
	kernel_display(*kernel_const);
	ocl->program = clCreateProgramWithSource(ocl->context, 1,
		*kernel_const, NULL, &err);
	ft_putendl("cleaning kernel source");
	clean_split(kernel_split);
	if (ocl_showerrori("failed to load kernel", err))
		return (-1);
	return (0);
}

int		ocl_kernel_init(t_ocl *ocl)
{
	char	kernel_source[OCL_KERNEL_MAXSIZE];

	ft_putendl("init kernel");
	if (ocl_kernel_bufferize("/tmp/kernel.cl", kernel_source) < 0)
	{
		ft_putendl("failed to load kernel: unable to access to the file.");
		return (0);
	}
	if (ocl_kernel_load(ocl, kernel_source) < 0)
		return (0);
	return (1);
}
