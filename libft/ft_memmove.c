/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:13:03 by etattevi          #+#    #+#             */
/*   Updated: 2022/11/01 16:35:45 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(
		void *dst,
		const void *src,
		size_t len
		)
{
	size_t	i;

	if (len == 0 || (dst == NULL && src == NULL))
		return (dst);
	if (src < dst)
	{
		i = len;
		while (--i > 0)
			((char *)dst)[i] = ((char *)src)[i];
		((char *)dst)[i] = ((char *)src)[i];
		return (dst);
	}
	i = 0;
	while (i < len)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
