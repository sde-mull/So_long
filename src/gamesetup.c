/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamesetup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:31:30 by sde-mull          #+#    #+#             */
/*   Updated: 2022/06/15 14:45:06 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	gamesetup(t_arr *screen)
{
	char	*s;

	printback_map(screen);
	upcollectexit(screen);
	key_player(screen);
	upplayer(screen);
	mlx_string_put(screen->mlx, screen->win, 0, 0, 0x00FFFFFF, \
	"NUMBER OF MOVES: ");
	s = ft_itoa(screen->counter);
	mlx_string_put(screen->mlx, screen->win, 160, 0, 0x00FFFFFF, s);
	free(s);
	return (0);
}

void	get_player_position(t_arr *p)
{
	int	y;
	int	x;

	y = 0;
	while (y < p->dy)
	{
		x = 0;
		while (x < p->dx)
		{
			if (p->mat[y][x] == 'P')
			{
				p->key.py = y;
				p->key.px = x;
				return ;
			}
			x++;
		}
		y++;
	}
}
