/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:44:37 by sde-mull          #+#    #+#             */
/*   Updated: 2022/05/23 15:22:24 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
    t_arr arr;
    
    arr.coll = 0;
    arr.counter = 0;
    arr.ie = 0;
    arr.ic = 0;
    if (argc == 1)
        printerror(1);
    else if (argc > 2)
        printerror(2);
    mat_len(&arr, argv[1]);
    arr.mat = create_map(&arr);
    magicprocess(argv[1], &arr);
    arr.toC = checkmap(arr.mat, arr.dx, arr.dy);
    startgame(arr);
    deallocate(arr.mat, arr.dx, arr.dy);
    return (0);
}

