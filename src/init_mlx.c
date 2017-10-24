/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:56:12 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/19 15:45:10 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		get_loop_hook(t_m *m)
{
	render(m);
	return (0);
}

void	init_mlx(t_player *player, t_map *map)
{
	t_m	m;

	m.map = map;
	m.player = player;
	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, WIDTH, HEIGHT, "Wolf3d");
	texture_load(&m);
	initkeyboard(&m);
	m.bpp = 0;
	m.size_line = 0;
	m.endian = 0;
	mlx_hook(m.win, 2, 1, key_press_hook, &m);
	mlx_hook(m.win, 3, 1, key_release_hook, &m);
	mlx_hook(m.win, 17, 0, exit_hook, &m);
	mlx_expose_hook(m.win, expose_hook, &m);
	mlx_loop_hook(m.mlx, &get_loop_hook, &m);
	mlx_loop(m.mlx);
}

void	render(t_m *m)
{
	key_up_down(m);
	key_left_right(m);
	m->img = mlx_new_image(m->mlx, WIDTH, HEIGHT);
	m->imgpx = mlx_get_data_addr(m->img,
	&(m->bpp), &(m->size_line), &(m->endian));
	raycast(m);
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	mlx_destroy_image(m->mlx, m->img);
}
