/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:13:03 by etattevi          #+#    #+#             */
/*   Updated: 2022/11/10 11:42:51 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx_haystack;
	size_t	idx_needle;
	char	*guess;

	idx_haystack = 0;
	idx_needle = 0;
	if (needle[0] == '\0' || (!haystack && len == 0))
		return ((char *)haystack);
	while (haystack[idx_haystack] && idx_haystack < len)
	{
		if (needle[idx_needle] != haystack[idx_haystack])
			idx_needle = 0;
		if (needle[idx_needle] == haystack[idx_haystack])
		{
			guess = (char *)(haystack + idx_haystack);
			idx_needle++;
		}
		if (!needle[idx_needle])
			return (guess - idx_needle + 1);
		idx_haystack++;
	}
	return (NULL);
}
