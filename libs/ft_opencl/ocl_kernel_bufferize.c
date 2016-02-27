/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocl_kernel_bufferize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 17:20:53 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/27 17:28:25 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ocl.h"
#include <fcntl.h>

int		ocl_kernel_bufferize(const char *filepath, char *buff)
{
	int		ret;
	int		fd;

	if ((fd = open(filepath, O_RDONLY)) < 0)
		return (-1);
	ret = (int)read(fd, buff, OCL_KERNEL_MAXSIZE);
	close(fd);
	return (ret);
}
