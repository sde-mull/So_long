/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerstruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:46:42 by sde-mull          #+#    #+#             */
/*   Updated: 2022/05/21 21:16:42 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_player(t_arr *screen)
{
    screen->imgp.imgs = mlx_xpm_file_to_image(screen->mlx, \
    "images/player_down/playerdown2.xpm", &screen->imgp.width, &screen->imgp.height);
    screen->imgp.imgw = mlx_xpm_file_to_image(screen->mlx, \
    "images/player_up/playerup2.xpm", &screen->imgp.width, &screen->imgp.height);
    screen->imgp.imgd = mlx_xpm_file_to_image(screen->mlx, \
    "images/player_right/playerright2.xpm", &screen->imgp.width, &screen->imgp.height);
    screen->imgp.imga = mlx_xpm_file_to_image(screen->mlx, \
    "images/player_left/playerleft2.xpm", &screen->imgp.width, &screen->imgp.height);
}