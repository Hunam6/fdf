/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:13:03 by etattevi          #+#    #+#             */
/*   Updated: 2022/11/10 12:15:00 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	beg;
	int	end;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	beg = 0;
	end = ft_strlen(s1) - 1;
	while (isinstr(s1[i++], set))
		beg++;
	i = end;
	while (isinstr(s1[i--], set))
		end--;
	if (beg == end)
		return (ft_strdup(""));
	return (ft_substr(s1, beg, end - beg + 1));
}
/* 
#include <stdio.h>

int	main()
{
	char	*strtrim;
	char s1[] = "          ";
	if (!(strtrim = ft_strtrim(s1, " ")))
		printf("NULL\n");
	else
		printf("-%s-\n", strtrim);
	if (strtrim == s1)
		printf("\nA new string was not returned\n");
} */