/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:39:53 by etattevi          #+#    #+#             */
/*   Updated: 2022/11/25 15:02:57 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	puthex(int *printed, unsigned long n, bool upper, bool is_long)
{
	if (n == 0)
	{
		putchr(printed, '0');
		return ;
	}
	if (is_long)
		puthexnbr(printed, (unsigned long)n, upper);
	else
		puthexnbr(printed, (unsigned int)n, upper);
}

void	puthexnbr(int *printed, unsigned long n, bool upper)
{
	if (n == 0)
		return ;
	if (n >= 16)
		puthexnbr(printed, n / 16, upper);
	if (0 <= n % 16 && n % 16 <= 9)
		ft_putchar_fd('0' + n % 16, 1);
	else if (upper)
		ft_putchar_fd('A' - 10 + n % 16, 1);
	else
		ft_putchar_fd('a' - 10 + n % 16, 1);
	(*printed)++;
}

void	putstr(int *printed, char *str)
{
	size_t	len;

	if (!str)
	{
		write(1, "(null)", 6);
		(*printed) += 6;
		return ;
	}
	len = 0;
	while (str[len])
	{
		len++;
		(*printed)++;
	}
	write(1, str, len);
}

void	putchr(int *printed, char chr)
{
	ft_putchar_fd(chr, 1);
	(*printed)++;
}

void	putnb(int *printed, long nb)
{
	if (nb < 0)
		putchr(printed, '-');
	if (nb == INT_MIN)
	{
		putchr(printed, '2');
		nb = -147483648;
	}
	if (nb < 0)
		nb = -nb;
	if (nb > 9)
		putnb(printed, nb / 10);
	putchr(printed, '0' + nb % 10);
}
