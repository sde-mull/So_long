/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:20:54 by sde-mull          #+#    #+#             */
/*   Updated: 2022/05/23 15:26:42 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include "libft/libft.h"
#include "libft/get_next_line/get_next_line.h"
#include "libft/printf/src/ft_printf.h"
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

# define UP 13
# define LEFT 0
# define RIGHT 2
# define DOWN 1
# define CLOSE 53

typedef struct s_player
{
    int W;
    int S;
    int A;
    int D;
    int ESC;
    int px;
    int py;
} t_player;

typedef struct s_img
{
    void	*img;
    void    *imgw;
    void    *imga;
    void    *imgs;
    void    *imgd;
    void    *imgl[6];
    void    *imgc[4];
	int     width;
	int		height;  
} t_img;

typedef struct arr
{
    void	*mlx;
	void	*win;
    int     h;
    int     w;
    int     **mat;
    int     dx;
    int     dy;
    int     toC;
    int     coll;
    int     counter;
    int     ie;
    int     ic;
    t_img   img0;
    t_img   img1;
    t_img   imgc;
    t_img   imge;
    t_img   imgp;
    t_img   imgl;
    t_player key;
} t_arr;

typedef struct checkmap
{
    int P;
    int E;
    int C;
    int x;
    int y;
} t_check;

void    mat_len(t_arr *arr, char *argv);
void    deallocate(int **arr, int lx, int ly);
int     **create_map(t_arr *arr);
void    magicprocess(char *argv, t_arr *arr);
void    printerror(int error);
void    startgame(t_arr arr);
int     checkmap(int **mat, int dx, int dy);
int     checkwalls(int **mat, int dx, int dy, t_check *var);
void    printerrorv2(int error);
void    get_player_position (t_arr *p);
void    new_screen(t_arr *screen);
void    init_img(t_arr *screen);
void    printback_map(t_arr *screen);
int	    scan_key(int keycode, t_arr *screen);
void    init_struct(t_arr *screen);
int     gamesetup(t_arr *screen);
int 	exit_game(t_arr *screen);
void    move_player(t_arr *p, int movx, int movy);
void    key_player(t_arr *screen);
void    upplayer(t_arr *screen);
void    upcollectexit(t_arr *screen);
void    init_player(t_arr *screen);
void    init_enemy(t_arr *screen);
void    updatenemy(t_arr *screen, int x, int y);
void    findenemy(t_arr *screen);
int 	exit_error(t_arr *window);
void    updatecollectible(t_arr *screen, int x, int y);
void    init_collectible(t_arr *screen);

#endif