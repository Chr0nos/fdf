/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 15:52:58 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/03 19:07:05 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ocl.h"
#include "libft.h"

int			main(void)
{
	t_ocl		*ocl;
	char		test[256];

	ft_memset(test, 0, 256);
	if (!(ocl = ocl_init(NULL, test, 256)))
		ft_putendl("opencl failed");
	else
	{
		ft_putendl("opencl ok");
		ocl_display_devices(ocl);
		ocl_clean(&ocl);
	}
	return (0);
}
