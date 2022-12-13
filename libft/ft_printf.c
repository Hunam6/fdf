/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:39:53 by etattevi          #+#    #+#             */
/*   Updated: 2022/12/07 12:59:13 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_arg(int *printed, va_list args, char specifier)
{
	if (specifier == 'c')
		putchr(printed, va_arg(args, int));
	else if (specifier == 's')
		putstr(printed, va_arg(args, char *));
	else if (specifier == 'p')
	{
		putstr(printed, "0x");
		puthex(printed, va_arg(args, unsigned long), false, true);
	}
	else if (specifier == 'i' || specifier == 'd')
		putnb(printed, va_arg(args, int));
	else if (specifier == 'u')
		putnb(printed, va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		puthex(printed, va_arg(args, unsigned int), specifier == 'X', false);
	(*printed)--;
}

int	ft_printf(const char *str, ...)
{
	int			printed;
	bool		prev_was_percent;
	va_list		args;

	printed = 0;
	prev_was_percent = false;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && !prev_was_percent)
			prev_was_percent = true;
		else
		{
			if (prev_was_percent && *str != '%')
				write_arg(&printed, args, *str);
			else
				ft_putchar_fd(*str, 1);
			printed++;
			prev_was_percent = false;
		}
		str++;
	}
	va_end(args);
	return (printed);
}
