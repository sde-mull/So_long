/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:22:25 by sde-mull          #+#    #+#             */
/*   Updated: 2022/05/14 14:22:53 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_struct(t_arr *screen)
{
    screen->key.W = 0;
    screen->key.A = 0;
    screen->key.D = 0;
    screen->key.S = 0;
    screen->key.ESC = 0;
}

int	scan_key(int keycode, t_arr *screen)
{
    init_struct(screen);
	if (keycode == UP)
        screen->key.W = 1;
    if (keycode == LEFT)
        screen->key.A = 1;
    if (keycode == RIGHT)
        screen->key.D = 1;
    if (keycode == DOWN)
        screen->key.S = 1;
    if (keycode == CLOSE)
        screen->key.ESC = 1;
	return (0);
}