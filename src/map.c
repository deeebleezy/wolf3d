/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:54:50 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/19 17:21:05 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			atoi_free(char *tab)
{
	int		nb;

	nb = ft_atoi(tab);
	free(tab);
	return (nb);
}

static void	free_these_things(t_list *l, char *content, char *tab, char **tabb)
{
	free(content);
	free(l);
	free(tab);
	free(tabb);
}

t_map		*map_parse(t_list *list)
{
	t_map	*map;
	t_list	*tmp;
	char	**tab;
	int		x;
	int		y;

	map = (t_map*)malloc(sizeof(t_map));
	if (list && map && !(y = 0))
	{
		map->y = ft_lstlen(list);
		map->wall = (int**)malloc(sizeof(int*) * map->y);
		while (list && (x = -1))
		{
			tab = ft_strsplit(list->content, ' ');
			map->x = ft_tablen(tab);
			map->wall[y] = (int*)malloc(sizeof(int) * map->x);
			while (++x < map->x)
				map->wall[y][x] = atoi_free(tab[x]);
			tmp = list;
			list = list->next;
			free_these_things(tmp, tmp->content, tab[x], tab);
			y++;
		}
	}
	return (map);
}

void		map_print(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			ft_putnbr(map->wall[y][x]);
			ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
