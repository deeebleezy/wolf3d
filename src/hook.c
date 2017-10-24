/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:53:54 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/19 15:42:29 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_press_hook(int keycode, t_m *m)
{
	key_press(&m->key, keycode);
	if (keycode == KEY_ESC)
	{
		system("killall afplay 2> /dev/null");
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int		key_release_hook(int keycode, t_m *m)
{
	key_release(&m->key, keycode);
	return (0);
}

int		expose_hook(t_m *m)
{
	render(m);
	return (0);
}

int		exit_hook(void)
{
	system("killall afplay 2> /dev/null");
	exit(1);
	return (0);
}
