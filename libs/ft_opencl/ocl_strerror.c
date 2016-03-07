/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocl_strerror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 18:37:00 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/07 09:50:55 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ocl.h"
#include "libft.h"

void	ocl_strerror(char *buffer, cl_int err)
{
	if (err & CL_INVALID_CONTEXT)
		ft_strcpy(buffer, "invalid context");
	else if (err & CL_INVALID_VALUE)
		ft_strcpy(buffer, "invalid value");
	else if (err & CL_INVALID_BUFFER_SIZE)
		ft_strcpy(buffer, "invalid buffer size");
	else if (err & CL_INVALID_HOST_PTR)
		ft_strcpy(buffer, "invalid host ptr");
	else if (err & CL_MEM_OBJECT_ALLOCATION_FAILURE)
		ft_strcpy(buffer, "memory allocation failure");
	else if (err & CL_OUT_OF_HOST_MEMORY)
		ft_strcpy(buffer, "out of host memory");
	else
		ft_strcpy(buffer, "unknow error (deal with it !!)");
}

void	ocl_showerror(const char *part1, cl_int err)
{
	char	buffer[256];

	ocl_strerror(buffer, err);
	ft_printf("%s: %s (%d)\n", part1, buffer, (int)err);
}

int		ocl_showerrori(const char *part1, cl_int err)
{
	if (!err)
		return (0);
	ocl_showerror(part1, err);
	return (1);
}
