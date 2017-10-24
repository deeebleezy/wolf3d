/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:33:37 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/19 17:19:04 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				main(int argc, char **argv)
{
	t_map		*map;
	t_list		*list;
	t_player	*player;

	if (argc == 2)
	{
		list = read_file(argv[1]);
		map = map_parse(ft_lstrev(list));
		player = newplayer(2, 2);
		init_mlx(player, map);
		exit_hook();
	}
	else
		ft_putstr("invalid arguments: use map files\n");
	return (0);
}
