/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:56:30 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/19 14:26:33 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	texture_load(t_m *m)
{
	int		width;
	int		height;

	m->wall[0] = mlx_xpm_file_to_image(m->mlx,
			"gfx/marblefloor.xpm", &width, &height);
	m->wall[1] = mlx_xpm_file_to_image(m->mlx,
			"gfx/goldwall.xpm", &width, &height);
	m->wall[2] = mlx_xpm_file_to_image(m->mlx,
			"gfx/versace3.xpm", &width, &height);
	m->wall[3] = mlx_xpm_file_to_image(m->mlx,
			"gfx/Freebandz.xpm", &width, &height);
	m->wall[4] = mlx_xpm_file_to_image(m->mlx,
			"gfx/MacArt.xpm", &width, &height);
	m->wall[5] = mlx_xpm_file_to_image(m->mlx,
			"gfx/2pacaeom.xpm", &width, &height);
	m->wall[6] = mlx_xpm_file_to_image(m->mlx,
			"gfx/versace3.xpm", &width, &height);
	m->wall[7] = mlx_xpm_file_to_image(m->mlx,
			"gfx/versace2.xpm", &width, &height);
	m->wall[8] = mlx_xpm_file_to_image(m->mlx,
			"gfx/2pacaeom.xpm", &width, &height);
	m->wall[9] = mlx_xpm_file_to_image(m->mlx,
			"gfx/portalrm.xpm", &width, &height);
}
