/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:51:17 by sde-mull          #+#    #+#             */
/*   Updated: 2022/06/21 15:07:44 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkmap(int **mat, int dx, int dy)
{
	t_check	var;

	var.p = 0;
	var.c = 0;
	var.e = 0;
	var.y = 0;
	checkwalls(mat, dx - 1, dy - 1, &var);
	if (var.p > 1 || var.p == 0)
		printerror(4);
	else if (var.e > 1 || var.e == 0)
		printerrorv2(1);
	else if (var.c == 0)
		printerrorv2(2);
	else if (dx == dy)
		printerrorv2(3);
	return (var.c);
}

int	checkwalls(int **mat, int dx, int dy, t_check *var)
{
	while (var->y <= dy)
	{
		var->x = 0;
		while (var->x <= dx)
		{
			if (mat[0][var->x] != '1' || mat[var->y][0] != '1'
				|| mat[var->y][dx] != '1' || mat[dy][var->x] != '1')
				printerror(3);
			if (mat[var->y][var->x] == 'P')
				var->p += 1;
			else if (mat[var->y][var->x] == 'C')
				var->c += 1;
			else if (mat[var->y][var->x] == 'E')
				var->e += 1;
			else if (mat[var->y][var->x] != 'E' && mat[var->y][var->x] != 'C'
			&& mat[var->y][var->x] != '1' && mat[var->y][var->x] != '0'
			&& mat[var->y][var->x] != 'P' && mat[var->y][var->x] != 'L')
				printerrorv2(4);
			var->x += 1;
		}
		var->y += 1;
	}
	return (var->c);
}
