/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:34:30 by sde-mull          #+#    #+#             */
/*   Updated: 2022/06/15 15:15:28 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_arr *p, int movx, int movy)
{
	if (p->mat[p->key.py + movy][p->key.px + movx] == 'E')
	{
		if (p->toc == p->coll)
			exit_game(p);
	}
	else if (p->mat[p->key.py + movy][p->key.px + movx] == 'L')
		exit_game(p);
	else if (p->mat[p->key.py + movy][p->key.px + movx] != '1')
	{
		if (p->mat[p->key.py + movy][p->key.px + movx] == 'C')
			p->coll += 1;
		p->mat[p->key.py][p->key.px] = '0';
		p->key.py += movy;
		p->key.px += movx;
		p->mat[p->key.py][p->key.px] = 'P';
		ft_printf("Number of movements: %d\n", p->counter);
		p->counter += 1;
	}
}

void	key_player(t_arr *screen)
{
	if (screen->key.w == 1)
	{
		move_player(screen, 0, -1);
		screen->imgp.img = screen->imgp.imgw;
	}
	if (screen->key.d == 1)
	{
		move_player(screen, 1, 0);
		screen->imgp.img = screen->imgp.imgd;
	}
	if (screen->key.a == 1)
	{
		move_player(screen, -1, 0);
		screen->imgp.img = screen->imgp.imga;
	}
	if (screen->key.s == 1)
	{
		move_player(screen, 0, 1);
		screen->imgp.img = screen->imgp.imgs;
	}
	if (screen->key.esc == 1)
		exit_game(screen);
}
