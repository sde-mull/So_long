/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:34:03 by sde-mull          #+#    #+#             */
/*   Updated: 2022/06/15 14:44:09 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_background(t_arr *screen)
{
	mlx_destroy_image(screen->mlx, screen->img0.img);
	mlx_destroy_image(screen->mlx, screen->img1.img);
}

void	free_player(t_arr *screen)
{
	mlx_destroy_image(screen->mlx, screen->imgp.imgw);
	mlx_destroy_image(screen->mlx, screen->imgp.imga);
	mlx_destroy_image(screen->mlx, screen->imgp.imgs);
	mlx_destroy_image(screen->mlx, screen->imgp.imgd);
}

void	free_collectible(t_arr *screen)
{
	int	i;

	i = -1;
	while (++i)
		mlx_destroy_image(screen->mlx, screen->imgc.imgc[i]);
}

void	free_enemy(t_arr *screen)
{
	int	i;

	i = -1;
	while (++i)
		mlx_destroy_image(screen->mlx, screen->imgl.imgl[i]);
}

int	exit_game(t_arr *screen)
{
	free_background(screen);
	free_player(screen);
	free_collectible(screen);
	free_enemy(screen);
	mlx_destroy_window(screen->mlx, screen->win);
	deallocate(screen->mat, screen->dy);
	exit(EXIT_SUCCESS);
}
