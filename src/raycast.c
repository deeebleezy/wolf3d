/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:55:29 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/19 15:42:58 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	rayinit(t_m *m, t_raycast *rc, int x)
{
	rc->camerax = 2 * x / (double)(WIDTH) - 1;
	rc->rayposx = m->player->pos->x;
	rc->rayposy = m->player->pos->y;
	rc->raydirx = m->player->dir->x + m->player->plane->x * rc->camerax;
	rc->raydiry = m->player->dir->y + m->player->plane->y * rc->camerax;
	rc->mapx = (int)rc->rayposx;
	rc->mapy = (int)rc->rayposy;
	rc->deltadistx = sqrt(1 + (rc->raydiry * rc->raydiry)
			/ (rc->raydirx * rc->raydirx));
	rc->deltadisty = sqrt(1 + (rc->raydirx * rc->raydirx)
			/ (rc->raydiry * rc->raydiry));
}

void	rayfindside(t_raycast *rc)
{
	if (rc->raydirx < 0)
	{
		rc->stepx = -1;
		rc->sidedistx = (rc->rayposx - rc->mapx) * rc->deltadistx;
	}
	else
	{
		rc->stepx = 1;
		rc->sidedistx = (rc->mapx + 1.0 - rc->rayposx) * rc->deltadistx;
	}
	if (rc->raydiry < 0)
	{
		rc->stepy = -1;
		rc->sidedisty = (rc->rayposy - rc->mapy) * rc->deltadisty;
	}
	else
	{
		rc->stepy = 1;
		rc->sidedisty = (rc->mapy + 1.0 - rc->rayposy) * rc->deltadisty;
	}
}

void	raydda(t_raycast *rc, t_m *m)
{
	while (rc->hit == 0)
	{
		if (rc->sidedistx < rc->sidedisty)
		{
			rc->sidedistx += rc->deltadistx;
			rc->mapx += rc->stepx;
			rc->side = 0;
		}
		else
		{
			rc->sidedisty += rc->deltadisty;
			rc->mapy += rc->stepy;
			rc->side = 1;
		}
		if (m->map->wall[(int)rc->mapy][(int)rc->mapx] > 0)
			rc->hit = 1;
	}
}

void	raydist(t_raycast *rc)
{
	if (rc->side == 0)
		rc->perpwalldist = fabs(
				(rc->mapx - rc->rayposx + (1 - rc->stepx) / 2) / rc->raydirx);
	else
		rc->perpwalldist = fabs(
				(rc->mapy - rc->rayposy + (1 - rc->stepy) / 2) / rc->raydiry);
}

void	raycast(t_m *m)
{
	t_raycast	rc;
	int			x;

	x = 0;
	while (x < WIDTH)
	{
		rayinit(m, &rc, x);
		rc.hit = 0;
		rayfindside(&rc);
		raydda(&rc, m);
		raydist(&rc);
		draw_ray(&rc, x, m);
		x++;
	}
}
