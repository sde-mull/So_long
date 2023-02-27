/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerstruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:46:42 by sde-mull          #+#    #+#             */
/*   Updated: 2022/06/15 14:52:41 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_arr *screen)
{
	screen->imgp.imgs = mlx_xpm_file_to_image(screen->mlx, \
	"images/player_down/playerdown2.xpm", &screen->imgp.width, \
	&screen->imgp.height);
	screen->imgp.imgw = mlx_xpm_file_to_image(screen->mlx, \
	"images/player_up/playerup2.xpm", &screen->imgp.width, \
	&screen->imgp.height);
	screen->imgp.imgd = mlx_xpm_file_to_image(screen->mlx, \
	"images/player_right/playerright2.xpm", &screen->imgp.width, \
	&screen->imgp.height);
	screen->imgp.imga = mlx_xpm_file_to_image(screen->mlx, \
	"images/player_left/playerleft2.xpm", &screen->imgp.width, \
	&screen->imgp.height);
	screen->imgp.img = screen->imgp.imgd;
}

void	upplayer(t_arr *screen)
{
	mlx_put_image_to_window(screen->mlx, screen->win, \
	screen->imgp.img, screen->key.px * 32, screen->key.py * 32);
	init_struct(screen);
}

void	upcollectexit(t_arr *screen)
{
	int	y;
	int	x;

	y = -1;
	while (++y < screen->dy)
	{
		x = -1;
		while (++x < screen->dx)
		{
			if (screen->mat[y][x] == 'C')
				updatecollectible(screen, x, y);
			else if (screen->mat[y][x] == 'L')
				updatenemy(screen, x, y);
			else if (screen->mat[y][x] == 'E')
				mlx_put_image_to_window(screen->mlx, screen->win, \
				screen->imge.img, x * 32, y * 32);
		}
	}
}

void	updatenemy(t_arr *screen, int x, int y)
{
	static int	pace;

	if (pace++ < 25)
	{
		mlx_put_image_to_window(screen->mlx, screen->win, \
		screen->imgl.img, x * 32, y * 32);
		return ;
	}
	pace = 0;
	if (screen->ie++ < 5)
		screen->imgl.img = screen->imgl.imgl[screen->ie];
	else
		screen->ie = 0;
}

void	updatecollectible(t_arr *screen, int x, int y)
{
	static int	pace;

	if (pace++ < 50)
	{
		mlx_put_image_to_window(screen->mlx, screen->win, \
		screen->imgc.img, x * 32, y * 32);
		return ;
	}
	pace = 0;
	if (screen->ic++ < 3)
		screen->imgc.img = screen->imgc.imgc[screen->ic];
	else
		screen->ic = 0;
}
