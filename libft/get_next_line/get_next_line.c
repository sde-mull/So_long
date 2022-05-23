/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:50:28 by sde-mull          #+#    #+#             */
/*   Updated: 2022/05/18 15:16:26 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_backup(char *saved_line)
{
	int		index;
	int		index_2;
	char	*p_line;

	index = 0;
	index_2 = 0;
	while (saved_line[index] != '\0' && saved_line[index] != '\n')
		index++;
	if (saved_line[index] == '\0')
	{
		free(saved_line);
		return (NULL);
	}
	p_line = (char *)malloc(sizeof(char) * (ft_strlenn(saved_line) - index + 1));
	if (p_line == 0)
		return (NULL);
	index++;
	while (saved_line[index])
		p_line[index_2++] = saved_line[index++];
	p_line[index_2] = '\0';
	free(saved_line);
	return (p_line);
}

char	*ft_get_line(char *saved_line)
{
	char	*line;
	int		index;

	index = 0;
	if (saved_line[index] == 0)
		return (NULL);
	while (saved_line[index] != '\0' && saved_line[index] != '\n')
		index++;
	line = (char *)malloc(sizeof(char) * (index + 2));
	if (line == 0)
		return (NULL);
	index = 0;
	while (saved_line[index] != '\0' && saved_line[index] != '\n')
	{
		line[index] = saved_line[index];
		index++;
	}
	if (saved_line[index] == '\n')
	{
		line[index] = saved_line[index];
		index++;
	}
	line[index] = '\0';
	return (line);
}

char	*ft_read_save(int fd, char *saved_line)
{
	char	*line;
	int		reader;

	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (line == 0)
		return (NULL);
	reader = 1;
	while (!ft_strchrr(saved_line, '\n') && reader != 0)
	{
		reader = read(fd, line, BUFFER_SIZE);
		if (reader == -1)
		{
			free(line);
			return (NULL);
		}
		line[reader] = '\0';
		saved_line = ft_strjoinn(saved_line, line);
	}
	free(line);
	return (saved_line);
}

char	*get_next_line(int fd)
{
	static char	*saved_line;
	char		*get_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (0);
	saved_line = ft_read_save(fd, saved_line);
	if (saved_line == NULL)
		return (NULL);
	get_line = ft_get_line(saved_line);
	saved_line = ft_backup(saved_line);
	return (get_line);
}
