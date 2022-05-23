/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:36:21 by sde-mull          #+#    #+#             */
/*   Updated: 2022/01/14 16:36:21 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <unistd.h>
# include <stdio.h>

int	ft_putchar(char c);
int	ft_putnbr(int n, int base, char format);
int	ft_putnbr_u(unsigned int n, unsigned int base);
int	ft_putstr(char *s);
int	ft_putnbr_p(unsigned long n, unsigned long base, char format);

#endif