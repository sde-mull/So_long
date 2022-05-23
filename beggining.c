/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beggining.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:46:23 by sde-mull          #+#    #+#             */
/*   Updated: 2022/05/09 13:21:12 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    mat_len(t_arr *arr, char *argv)
{
    int index;
    int fd;
    char *line;

    index = 0;
    fd = open(argv, O_RDONLY);
    line = get_next_line(fd);
    while (line[index++] != '\0')
    arr->dx = index - 1;
    index = 0;
    while (line != (void *)0)
    {
        free(line);
        line = get_next_line(fd);
        index++;
    }
    arr->dy = index;
    close(fd);
}

int  **create_map(t_arr *arr)
{
    int index;
    int **mat;

    index = -1;
    mat = malloc(arr->dy * sizeof(int *));
    while (++index < arr->dy)
       mat[index] = malloc(arr->dx * sizeof(int *));
    return (mat);
}

void deallocate(int **arr, int lx, int ly)
{
    int index;

    index = -1;
    while (++index < ly)
        free(arr[index]);
    free(arr);
}