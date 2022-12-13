/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:13:03 by etattevi          #+#    #+#             */
/*   Updated: 2022/11/01 13:19:30 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	if (!n)
		return (0);
	idx = 0;
	while (
		s1[idx] != '\0' && s2[idx] != '\0'
		&& s1[idx] == s2[idx]
		&& idx + 1 < n
	)
		idx++;
	if (s1[idx] == s2[idx])
		return (0);
	return (((unsigned char *)s1)[idx] - ((unsigned char *)s2)[idx]);
}
