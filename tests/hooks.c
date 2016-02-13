/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 13:43:31 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/13 14:08:40 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"
#include <unistd.h>

typedef struct 	s_x
{
	t_mlx		*x;
	t_point		p;
}				t_x;

static int		display(void *userdata)
{
	t_x		*c;

	c = userdata;
	draw_reset_image(c->x, 0x00000000);
	draw_px(c->x, &c->p, COLOR_GREEN);
	draw_flush_image(c->x, c->x->img);
	return (0);
}

int				key(int keycode, void *userdata)
{
	t_x		*c;

	c = userdata;
	if (keycode == 124)
		c->p.x++;
	else if ((keycode == 123) && (c->p.x > 0))
		c->p.x--;
	else if ((keycode == 125) && (c->p.y < c->x->height))
		c->p.y++;
	else if ((keycode == 126) && (c->p.y > 0))
		c->p.y--;
	display(c);
	ft_printf("keycode: %d -- ptr: %p\n", keycode, userdata);
	return (0);
}

int				main(void)
{
	t_x		c;

	c.x = draw_init("Tests hooks", 800, 600);
	c.p.x = 400;
	c.p.y = 300;
	display(&c);
	draw_sethook_ng(c.x, &key, &c, KEYDOWN);
	draw_loop(c.x);
	return (0);
}
