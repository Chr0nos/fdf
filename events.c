/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 19:32:13 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/09 20:11:08 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

inline static void	more_keys(int keycode, t_context *c, t_scales *scales)
{
	(void)c;
	if ((keycode == 2) || (keycode == 'd'))
		scales->offsets.x += 0.01f;
	else if ((keycode == 0) || (keycode == 'a'))
		scales->offsets.x += -0.01f;
	else if ((keycode == 1) || (keycode == 's'))
		scales->offsets.z += 0.01f;
	else if ((keycode == 13) || (keycode == 'w'))
		scales->offsets.z += -0.01f;
}

int					key_hook(int keycode, void *userdata)
{
	t_context		*c;
	static t_scales	scale = { 0.04f, 0.8f, -0.2f, -4.0f, { 0.08f, 0.0f, 0.1f} };

	c = userdata;
	if ((keycode == 53) || (keycode == 65307) || (keycode == 12))
		exit(0);
	else if ((keycode == 126) || (keycode == 125))
		scale.rx += (keycode == 126) ? 0.1f : -0.1f;
	else if ((keycode == 124) || (keycode == 123))
		scale.rz += (keycode == 124) ? 0.1f : -0.1f;
	else if ((keycode == 24) || (keycode == 27))
		scale.zoom += (keycode == 24) ? 0.001f : -0.001f;
	else if ((keycode == 35) || (keycode == 31))
		scale.zoom_z += (keycode == 35) ? -3.0f : 3.0f;
	else if ((keycode == 37) || (keycode == 41))
		scale.zoom_z += (keycode == 37) ? 0.3f : -0.3f;
	else if (keycode == 34)
		scale.zoom_z = 0.0f;
	else
		ft_printf("keycode: %d\n", keycode);
	more_keys(keycode, c, &scale);
	display(c, &scale);
	return (0);
}
