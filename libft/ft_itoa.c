/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:13:03 by etattevi          #+#    #+#             */
/*   Updated: 2022/11/02 11:22:44 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	digit_nb(int n)
{
	if (n == 0)
		return (1);
	if (n > 9)
		return (1 + digit_nb(n / 10));
	return (1);
}

static bool	handle_special(char **out, int *n)
{
	if (*n == INT_MIN)
	{
		*out = ft_strdup("-2147483648");
		return (true);
	}
	if (*n == 0)
	{
		*out = ft_strdup("0");
		return (true);
	}
	return (false);
}

static void	handle_neg(bool *is_neg, int *n, int *i)
{
	*is_neg = false;
	if (*n < 0)
	{
		*is_neg = true;
		*n = -(*n);
		(*i)++;
	}
}

char	*ft_itoa(int n)
{
	char	*out;
	int		i;
	bool	is_neg;

	out = NULL;
	if (handle_special(&out, &n))
		return (out);
	i = -1;
	handle_neg(&is_neg, &n, &i);
	i += digit_nb(n);
	out = malloc(sizeof(char) * (i + 2));
	if (!out)
		return (NULL);
	out[i + 1] = '\0';
	if (is_neg)
		out[0] = '-';
	while (n > 0)
	{
		out[i--] = '0' + n % 10;
		n /= 10;
	}
	return (out);
}
