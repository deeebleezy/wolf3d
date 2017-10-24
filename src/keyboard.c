/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:54:30 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/19 15:43:28 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	initkeyboard(t_m *m)
{
	m->key.up = 0;
	m->key.down = 0;
	m->key.left = 0;
	m->key.right = 0;
	m->key.sleft = 0;
	m->key.sright = 0;
}

void	key_press(t_keyboard *key, int keycode)
{
	if (keycode == KEY_UP)
		key->up = 1;
	if (keycode == KEY_DOWN)
		key->down = 1;
	if (keycode == KEY_LEFT)
	{
		key->right = 0;
		key->left = 1;
	}
	if (keycode == KEY_RIGHT)
	{
		key->left = 0;
		key->right = 1;
	}
}

void	key_release(t_keyboard *key, int keycode)
{
	if (keycode == KEY_UP)
		key->up = 0;
	if (keycode == KEY_DOWN)
		key->down = 0;
	if (keycode == KEY_LEFT)
		key->left = 0;
	if (keycode == KEY_RIGHT)
		key->right = 0;
}

void	key_up_down(t_m *m)
{
	if (m->key.up)
	{
		if (m->map->wall[(int)(m->player->pos->y + m->player->dir->y
			* MOVESPEED * 1.5)][(int)(m->player->pos->x)] == 0)
			m->player->pos->y += m->player->dir->y * MOVESPEED;
		if (m->map->wall[(int)(m->player->pos->y)][(int)(m->player->pos->x
			+ m->player->dir->x * MOVESPEED * 1.5)] == 0)
			m->player->pos->x += m->player->dir->x * MOVESPEED;
	}
	if (m->key.down)
	{
		if (m->map->wall[(int)(m->player->pos->y - m->player->dir->y
			* MOVESPEED * 1.5)][(int)(m->player->pos->x)] == 0)
			m->player->pos->y -= m->player->dir->y * MOVESPEED;
		if (m->map->wall[(int)(m->player->pos->y)][(int)(m->player->pos->x
			- m->player->dir->x * MOVESPEED * 1.5)] == 0)
			m->player->pos->x -= m->player->dir->x * MOVESPEED;
	}
}

void	key_left_right(t_m *m)
{
	double olddirx;
	double oldplanex;

	olddirx = m->player->dir->x;
	oldplanex = m->player->plane->x;
	if (m->key.left)
	{
		m->player->dir->x = m->player->dir->x * C_R - m->player->dir->y * S_R;
		m->player->dir->y = olddirx * S_R + m->player->dir->y * C_R;
		m->player->plane->x = m->player->plane->x
			* C_R - m->player->plane->y * S_R;
		m->player->plane->y = oldplanex * S_R + m->player->plane->y * C_R;
	}
	if (m->key.right)
	{
		m->player->dir->x = m->player->dir->x * CR - m->player->dir->y * SR;
		m->player->dir->y = olddirx * SR + m->player->dir->y * CR;
		m->player->plane->x = m->player->plane->x
			* CR - m->player->plane->y * SR;
		m->player->plane->y = oldplanex * SR + m->player->plane->y * CR;
	}
}
