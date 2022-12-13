/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:13:03 by etattevi          #+#    #+#             */
/*   Updated: 2022/11/01 13:29:38 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	isinstr(char const ch, char const *str)
{
	while (*str)
	{
		if (*str == ch)
			return (true);
		str++;
	}
	return (false);
}

static void	handle_sign(const char *str, int *i, int *sign)
{
	if (str[*i] == '-')
	{
		(*i)++;
		*sign = -1;
	}
	else if (str[*i] == '+')
		(*i)++;
}

int	ft_atoi(const char *str)
{
	long	res;
	int		i;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (isinstr(str[i], "\a\b\f\n\r\t\v "))
		i++;
	handle_sign(str, &i, &sign);
	while (str[i] != '\0')
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			break ;
		res = res * 10 + (str[i] - 48);
		if (res * sign > INT_MAX)
			return (-1);
		else if (res * sign < INT_MIN)
			return (0);
		i++;
	}
	return (res * sign);
}
