/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:22:25 by sde-mull          #+#    #+#             */
/*   Updated: 2022/06/15 15:14:48 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_arr *screen)
{
	screen->key.w = 0;
	screen->key.a = 0;
	screen->key.d = 0;
	screen->key.s = 0;
	screen->key.esc = 0;
}

int	scan_key(int keycode, t_arr *screen)
{
	init_struct(screen);
	if (keycode == UP)
		screen->key.w = 1;
	if (keycode == LEFT)
		screen->key.a = 1;
	if (keycode == RIGHT)
		screen->key.d = 1;
	if (keycode == DOWN)
		screen->key.s = 1;
	if (keycode == CLOSE)
		screen->key.esc = 1;
	return (0);
}

int	scan_key_release(int keycode, t_arr *screen)
{
	if (keycode == UP)
		screen->key.w = 0;
	if (keycode == LEFT)
		screen->key.a = 0;
	if (keycode == RIGHT)
		screen->key.d = 0;
	if (keycode == DOWN)
		screen->key.s = 0;
	return (0);
}
