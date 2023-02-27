/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:25:10 by sde-mull          #+#    #+#             */
/*   Updated: 2022/01/13 16:25:10 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_u(unsigned int n, unsigned int base)
{
	int	count;

	count = 0;
	if (n >= base)
		count += ft_putnbr_u(n / base, base);
	count += ft_putchar((n % base) + '0');
	return (count);
}
