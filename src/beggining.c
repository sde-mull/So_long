/* ************************************************************************** */
/*	                                                                    	  */
/*                                                        :::      ::::::::   */
/*   beggining.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:46:23 by sde-mull          #+#    #+#             */
/*   Updated: 2022/06/15 14:32:30 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mat_len(t_arr *arr, char *argv)
{
	int		index;
	int		fd;
	char	*line;

	index = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (line[index++] != '\0')
	arr->dx = index - 1;
	index = 0;
	while (line != (void *)0)
	{
		free (line);
		line = get_next_line(fd);
		index++;
	}
	arr->dy = index;
	close(fd);
}

int	**create_map(t_arr *arr)
{
	int	index;
	int	**mat;

	index = -1;
	mat = malloc(arr->dy * sizeof(int *));
	if (!mat)
		return (0);
	while (++index < arr->dy)
	{
		mat[index] = malloc(arr->dx * sizeof(int *));
		if (!mat[index])
			return (0);
	}
	return (mat);
}

void	deallocate(int **arr, int ly)
{
	int	index;

	index = -1;
	while (++index < ly)
		free (arr[index]);
	free(arr);
}
