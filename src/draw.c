/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:53:39 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/19 15:42:13 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		rgb2i(int r, int g, int b)
{
	int	color;

	color = 256 * 256 * r;
	color += 256 * g;
	color += b;
	return (color);
}

int		getcolor(t_img *img, int x, int y, int fade)
{
	int	color;
	int	c;

	fade /= 8;
	c = (y * img->width + x) * 4;
	color = img->buffer[c];
	if (color == -120 && img->buffer[c + 1] == 0 && img->buffer[c + 2] == -104)
		return (256 * 256 * 256 + 256 * 256 + 256);
	color += img->buffer[c + 1] * 256;
	color += img->buffer[c + 2] * 256 * 256;
	return (color);
}

void	draw_dot(t_m *m, int x, int y, int color)
{
	char	b;
	char	g;
	char	r;
	int		i;

	if (color == 256 * 256 * 256 + 256 * 256 + 256)
		return ;
	b = color % 256;
	g = (color / 256) % 256;
	r = (color / 256 / 256) % 256;
	i = (m->size_line * y) + (x * (m->bpp / 8));
	m->imgpx[i] = b;
	m->imgpx[i + 1] = g;
	m->imgpx[i + 2] = r;
}

void	drawbyside(t_m *m, t_raycast *rc, int x, int y)
{
	if (rc->raydiry > 0 && rc->side)
		draw_dot(m, x, y, 0xFF0000);
	if (rc->raydiry < 0 && rc->side)
		draw_dot(m, x, y, 0x00FF00);
	if (rc->raydirx > 0 && rc->side == 0)
		draw_dot(m, x, y, 0x0000FF);
	if (rc->raydirx < 0 && rc->side == 0)
		draw_dot(m, x, y, 0xAA00BB);
}
