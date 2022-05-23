/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:26:46 by sde-mull          #+#    #+#             */
/*   Updated: 2022/01/12 16:26:46 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (s == 0)
	{
		count = write(1, "(null)", 6);
		return (count);
	}
	while (*s != '\0')
	{
		count += write(1, s, 1);
		s++;
	}
	return (count);
}
