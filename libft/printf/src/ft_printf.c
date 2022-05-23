/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:54:09 by sde-mull          #+#    #+#             */
/*   Updated: 2021/12/16 20:36:17 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ftype(char format, va_list *args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (format == 'p')
		return (ft_putstr("0x")
			+ ft_putnbr_p(va_arg(*args, unsigned long), 16, format));
	else if ((format == 'd') || (format == 'i'))
		return (ft_putnbr(va_arg(*args, int), 10, format));
	else if (format == 'u')
		return (ft_putnbr_u(va_arg(*args, unsigned int), 10));
	else if ((format == 'x') || (format == 'X'))
		return (ft_putnbr_p(va_arg(*args, unsigned int), 16, format));
	else if (format == '%')
		return (ft_putchar(format));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		counter;
	va_list	args;

	counter = 0;
	va_start(args, format);
	if (format == 0)
		return (0);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			counter += ft_ftype(*format, &args);
		}
		else
			counter += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (counter);
}
