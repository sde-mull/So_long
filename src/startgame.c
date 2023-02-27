/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startgame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:16:03 by sde-mull          #+#    #+#             */
/*   Updated: 2022/06/15 15:16:49 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_error(t_arr *window)
{
	if (window)
		exit_game(window);
	return (0);
}

void	startgame(t_arr screen)
{
	new_screen(&screen);
	init_img(&screen);
	get_player_position(&screen);
	init_player(&screen);
	mlx_hook(screen.win, 17, 0, exit_error, &screen);
	mlx_hook(screen.win, 2, 1L << 0, scan_key, &screen);
	mlx_hook(screen.win, 3, 1L << 1, scan_key_release, &screen);
	mlx_loop_hook(screen.mlx, gamesetup, &screen);
	mlx_loop(screen.mlx);
}

void	printback_map(t_arr *screen)
{
	int	y;
	int	x;

	y = -1;
	while (++y < screen->dy)
	{
		x = -1;
		while (++x < screen->dx)
		{
			if (screen->mat[y][x] == '1')
				mlx_put_image_to_window(screen->mlx, screen->win, \
				screen->img1.img, x * 32, y * 32);
			else
				mlx_put_image_to_window(screen->mlx, screen->win, \
				screen->img0.img, x * 32, y * 32);
		}
	}
}
