/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowman.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:31:50 by sde-mull          #+#    #+#             */
/*   Updated: 2022/06/15 15:13:27 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_screen(t_arr *screen)
{
	screen->w = screen->dx * 32;
	screen->h = screen->dy * 32;
	screen->mlx = mlx_init();
	screen->win = mlx_new_window(screen->mlx, screen->w, screen->h, "so_long");
	if (!screen->mlx)
		exit(EXIT_FAILURE);
}

void	init_img(t_arr *screen)
{
	screen->img0.img = mlx_xpm_file_to_image(screen->mlx, \
	"images/background.xpm", &screen->img0.width, &screen->img0.height);
	screen->img1.img = mlx_xpm_file_to_image(screen->mlx, \
	"images/wall.xpm", &screen->img1.width, &screen->img1.height);
	screen->imge.img = mlx_xpm_file_to_image(screen->mlx, \
	"images/door.xpm", &screen->imge.width, &screen->imge.height);
	init_enemy(screen);
	init_collectible(screen);
}

void	init_enemy(t_arr *screen)
{
	screen->imgl.imgl[0] = mlx_xpm_file_to_image(screen->mlx, \
	"images/enemy/enemy1.xpm", &screen->imgl.width, &screen->imgl.height);
	screen->imgl.imgl[1] = mlx_xpm_file_to_image(screen->mlx, \
	"images/enemy/enemy2.xpm", &screen->imgl.width, &screen->imgl.height);
	screen->imgl.imgl[2] = mlx_xpm_file_to_image(screen->mlx, \
	"images/enemy/enemy3.xpm", &screen->imgl.width, &screen->imgl.height);
	screen->imgl.imgl[3] = mlx_xpm_file_to_image(screen->mlx, \
	"images/enemy/enemy4.xpm", &screen->imgl.width, &screen->imgl.height);
	screen->imgl.imgl[4] = mlx_xpm_file_to_image(screen->mlx, \
	"images/enemy/enemy5.xpm", &screen->imgl.width, &screen->imgl.height);
	screen->imgl.imgl[5] = mlx_xpm_file_to_image(screen->mlx, \
	"images/enemy/enemy6.xpm", &screen->imgl.width, &screen->imgl.height);
	screen->imgl.img = screen->imgl.imgl[0];
}

void	init_collectible(t_arr *screen)
{
	screen->imgc.imgc[0] = mlx_xpm_file_to_image(screen->mlx, \
	"images/coll/collect1.xpm", &screen->imgc.width, &screen->imgc.height);
	screen->imgc.imgc[1] = mlx_xpm_file_to_image(screen->mlx, \
	"images/coll/collect2.xpm", &screen->imgc.width, &screen->imgc.height);
	screen->imgc.imgc[2] = mlx_xpm_file_to_image(screen->mlx, \
	"images/coll/collect3.xpm", &screen->imgc.width, &screen->imgc.height);
	screen->imgc.imgc[3] = mlx_xpm_file_to_image(screen->mlx, \
	"images/coll/collect4.xpm", &screen->imgc.width, &screen->imgc.height);
	screen->imgc.img = screen->imgc.imgc[0];
}
