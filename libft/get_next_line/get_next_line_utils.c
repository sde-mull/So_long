/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde.mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:49:28 by sde-mull          #+#    #+#             */
/*   Updated: 2022/05/18 15:17:40 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlenn(char *s)
{
	size_t	var2;

	var2 = 0;
	while ((s[var2] != '\0'))
		var2++;
	return (var2);
}

char	*ft_strchrr(char *s, int c)
{
	size_t	index;

	index = 0;
	if (s == 0)
		return (NULL);
	if (c == 0)
		return (&((char *)s)[ft_strlenn(s)]);
	while (s[index] != '\0')
	{
		if (s[index] == (unsigned char)c)
			return (&((char *)s)[index]);
		index++;
	}
	if (s[index] == ((unsigned char)c))
		return (&((char *)s)[index]);
	return (NULL);
}

char	*ft_strjoinn(char *s1, char *s2)
{
	size_t	index;
	size_t	index_2;
	char	*str;

	index = -1;
	index_2 = 0;
	if (s1 == 0)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (s1 == 0 || s2 == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlenn(s1) + ft_strlenn(s2) + 1));
	if (str == 0)
		return (NULL);
	if (s1 != 0)
		while (s1[++index] != '\0')
			str[index] = s1[index];
	while (s2[index_2] != '\0')
		str[index++] = s2[index_2++];
	str[index] = '\0';
	free(s1);
	return (str);
}
