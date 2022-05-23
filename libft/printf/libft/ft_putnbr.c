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

char	*ft_base(char format, int base)
{
	char	*str;

	if ((base == 10) && ((format == 'd') || (format == 'i')))
		str = "0123456789";
	else if ((format == 'x') && (base == 16))
		str = "0123456789abcdef";
	else if ((format == 'X') && (base == 16))
		str = "0123456789ABCDEF";
	else
		return (NULL);
	return (str);
}

int	ft_putnbr(int n, int base, char format)
{
	char	*str;
	int		count;

	count = 0;
	str = ft_base(format, base);
	if (n == -2147483648)
		count += write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			count += ft_putchar('-');
			n = -n;
		}
		if (n >= base)
			count += ft_putnbr(n / base, base, format);
		count += ft_putchar(str[n % base]);
	}
	return (count);
}
