/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:32:36 by sde-mull          #+#    #+#             */
/*   Updated: 2022/01/12 16:32:36 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_base1(char format, int base)
{
	char	*str;

	if ((base == 10) && ((format == 'd') || (format == 'i')))
		str = "0123456789";
	else if (((format == 'x') || (format == 'p')) && (base == 16))
		str = "0123456789abcdef";
	else if ((format == 'X') && (base == 16))
		str = "0123456789ABCDEF";
	else
		return (NULL);
	return (str);
}

int	ft_putnbr_p(unsigned long n, unsigned long base, char format)
{
	char	*str;
	int		count;

	count = 0;
	str = ft_base1(format, base);
	if (n >= base)
		count += ft_putnbr_p(n / base, base, format);
	count += ft_putchar(str[n % base]);
	return (count);
}
