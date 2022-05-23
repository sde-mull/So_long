/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:51:17 by sde-mull          #+#    #+#             */
/*   Updated: 2022/05/09 13:43:05 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int checkmap(int **mat, int dx, int dy)
{
    t_check var;

    var.P = 0;
    var.C = 0;
    var.E = 0;
    var.y = 0;
    checkwalls(mat, dx - 1, dy - 1, &var);
    if (var.P > 1 || var.P == 0)
        printerror(4);
    else if (var.E > 1 || var.E == 0)
        printerrorv2(1);
    else if (var.C == 0)
        printerrorv2(2);
    else if (dx == dy)
        printerrorv2(3);
    return(var.C);
}

int checkwalls(int **mat, int dx, int dy, t_check *var)
{
    while(var->y <= dy)
    {
        var->x = 0;
        while (var->x <= dx)
        {
            if (mat[0][var->x] != '1' || mat[var->y][0] != '1'
                || mat[var->y][dx] != '1' || mat[dy][var->x] != '1')
                    printerror(3);
            if (mat[var->y][var->x] == 'P')
                var->P += 1;
            else if (mat[var->y][var->x] == 'C')
                var->C += 1;
            else if (mat[var->y][var->x] == 'E')
                var->E += 1;
            var->x += 1;
        }
        var->y += 1;
    }
    return (var->C);
}
