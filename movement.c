/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:34:30 by sde-mull          #+#    #+#             */
/*   Updated: 2022/05/23 15:39:17 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_player(t_arr *p, int movx, int movy)
{
    if (p->mat[p->key.py + movy][p->key.px + movx] == 'E')
    {
        if (p->toC == p->coll)
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

void key_player(t_arr *screen)
{
    if (screen->key.W == 1)
    {
        move_player(screen, 0, -1);
        screen->imgp.img = screen->imgp.imgw;
    }
    if (screen->key.D == 1)
    {
        move_player(screen, 1, 0);
        screen->imgp.img = screen->imgp.imgd;
    }
    if (screen->key.A == 1)
    {
        move_player(screen, -1, 0);
        screen->imgp.img = screen->imgp.imga;
    }
    if (screen->key.S == 1)
    {
        move_player(screen, 0, 1);
        screen->imgp.img = screen->imgp.imgs;
    }
    if (screen->key.ESC == 1)
        exit_game(screen);
}

void upplayer(t_arr *screen)
{
    mlx_put_image_to_window(screen->mlx, screen->win, \
	screen->imgp.img, screen->key.px * 32 , screen->key.py * 32);
    init_struct(screen);
}

void upcollectexit(t_arr *screen)
{
    int y;
    int x;
    
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
				screen->imge.img, x * 32 , y * 32);
        }
    }
}

void updatenemy(t_arr *screen, int x, int y)
{
    if (screen->ie++ < 5)
        screen->imgl.img = screen->imgl.imgl[screen->ie];
    else
        screen->ie = 0;
    mlx_put_image_to_window(screen->mlx, screen->win, \
	    screen->imgl.img, x * 32 , y * 32);
}

void updatecollectible(t_arr *screen, int x, int y)
{
    static int pace;

    mlx_put_image_to_window(screen->mlx, screen->win, \
	screen->imgc.img, x * 32 , y * 32);
    if (pace++ < screen->toC - screen->coll)
        return ;
    pace = 0;
    if (screen->ic++ < 3)
        screen->imgc.img = screen->imgc.imgc[screen->ic];
    else
        screen->ic = 0;
}