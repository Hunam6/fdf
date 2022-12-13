/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:13:03 by etattevi          #+#    #+#             */
/*   Updated: 2022/11/11 15:36:41 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_split {
	char	**out;
	int		i;
	int		part_beg;
	int		part_len;
	int		out_i;
}	t_split;

static size_t	count_parts(char const *str, char c)
{
	size_t	count;
	size_t	i;
	size_t	j;

	count = 0;
	i = 0;
	if (!str[0])
		return (0);
	if (str[0] != c)
		count++;
	while (str[i])
	{
		j = i;
		while (str[i] == c)
			i++;
		if (i != j && str[i])
			count++;
		if (str[i])
			i++;
	}
	return (count);
}

static t_split	*init(char const *str, char c)
{
	t_split	*s;

	s = malloc(sizeof(t_split));
	if (!s)
		return (NULL);
	s->out = ft_calloc(sizeof(char *), count_parts(str, c) + 1);
	if (!(s->out))
		return (NULL);
	s->i = 0;
	s->part_beg = -1;
	s->part_len = 0;
	s->out_i = 0;
	return (s);
}

static char	**end(char const *s, t_split *data)
{
	char	**out;

	if (data->part_beg != -1)
		data->out[data->out_i++] = ft_substr(s, data->part_beg, data->part_len);
	data->out[data->out_i] = NULL;
	out = data->out;
	free(data);
	return (out);
}

char	**ft_split(char const *s, char c)
{
	t_split	*data;

	if (!s)
		return (NULL);
	data = init(s, c);
	if (!data)
		return (NULL);
	while (s[data->i])
	{
		if (s[data->i] != c)
		{
			if (data->part_beg == -1)
				data->part_beg = data->i;
			data->part_len++;
		}
		else if (data->part_beg != -1)
		{
			data->out[data->out_i++]
				= ft_substr(s, data->part_beg, data->part_len);
			data->part_beg = -1;
			data->part_len = 0;
		}
		data->i++;
	}
	return (end(s, data));
}
