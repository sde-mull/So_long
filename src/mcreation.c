/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mcreation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:15:34 by sde-mull          #+#    #+#             */
/*   Updated: 2022/06/21 15:01:37 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	magicprocess(char *argv, t_arr *arr)
{
	int		fd;
	char	*line;
	int		i;
	int		y;
	int		x;

	y = -1;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (++y < arr->dy)
	{
		x = -1;
		i = -1;
		while (line[++i] != '\0')
			arr->mat[y][++x] = line[i];
		if (line[i - 1] == '\n' && (arr->dx + 1 > i || arr->dx + 1 < i))
			printerrorv2(3);
		free(line);
		line = get_next_line(fd);
	}
	if (arr->dx > i || arr->dx < i)
		printerrorv2(3);
	close(fd);
}

void	printerror(int error)
{
	if (error == 1)
	{
		ft_printf("\nError:\n No map chosen\n\n");
		exit(EXIT_FAILURE);
	}
	else if (error == 2)
	{
		ft_printf("\nError:\n You can only choose 1 map\n\n");
		exit(EXIT_FAILURE);
	}
	else if (error == 3)
	{
		ft_printf("\nError:\n The wall is not closed\n\n");
		exit(EXIT_FAILURE);
	}
	else if (error == 4)
	{
		ft_printf("\nError:\n No Player or multiple players\n\n");
		exit(EXIT_FAILURE);
	}
}

void	printerrorv2(int error)
{
	if (error == 1)
	{
		ft_printf("\nError:\n No escape or multiple escapes\n\n");
		exit(EXIT_FAILURE);
	}
	else if (error == 2)
	{
		ft_printf("\nError:\n No collectible\n\n");
		exit(EXIT_FAILURE);
	}
	else if (error == 3)
	{
		ft_printf("\nError:\n the map must be rectangular\n\n");
		exit(EXIT_FAILURE);
	}
	else if (error == 4)
	{
		ft_printf("\nError:\n There is a wrong character\n\n");
		exit(EXIT_FAILURE);
	}
}
