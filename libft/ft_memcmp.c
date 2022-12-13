/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:13:03 by etattevi          #+#    #+#             */
/*   Updated: 2022/10/31 17:31:49 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	idx;

	if (n == 0)
		return (0);
	idx = 0;
	while (
		((unsigned char *)s1)[idx] == ((unsigned char *)s2)[idx]
		&& idx + 1 < n
		)
		idx++;
	if (((unsigned char *)s1)[idx] == ((unsigned char *)s2)[idx])
		return (0);
	return (((unsigned char *)s1)[idx] - ((unsigned char *)s2)[idx]);
}
