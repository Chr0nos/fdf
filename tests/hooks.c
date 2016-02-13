/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 13:43:31 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/13 15:39:35 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

typedef struct 	s_x
{
	t_mlx		*x;
	t_point		p;
}				t_x;

static int		display(void *userdata)
{
	t_x		*c;

	c = userdata;
	draw_px(c->x, &c->p, COLOR_GREEN);
	draw_flush_image(c->x, c->x->img);
	return (0);
}

int				key(int keycode, void *userdata)
{
	const int	offset = 2;
	t_x			*c;

	c = userdata;
	if ((keycode == 124) && (c->p.x + offset < c->x->width))
		c->p.x += offset;
	else if ((keycode == 123) && (c->p.x - offset >= 0))
		c->p.x -= offset;
	else if ((keycode == 125) && (c->p.y + offset < c->x->height))
		c->p.y += offset;
	else if ((keycode == 126) && (c->p.y - offset >= 0))
		c->p.y -= offset;
	else if (keycode == 12)
		exit(0);
	display(c);
	ft_printf("keycode: %d -- ptr: %p\n", keycode, userdata);
	return (0);
}

int				mouse(int x, int y, void *userdata)
{
	t_x		*c;

	ft_printf("x: %d %y %d -- ptr: %p\n", x, y, userdata);
	c = userdata;
	if ((x > c->x->width) || (y > c->x->height) || (x < 0) || (y < 0))
		return (0);
	c->p.x = x;
	c->p.y = y;
	display(c);
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
	draw_sethook_ng(c.x, &mouse, &c, MOUSEMOVE);
	draw_loop(c.x);
	draw_clear(c.x);
	return (0);
}
