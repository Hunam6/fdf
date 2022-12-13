/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:32:31 by etattevi          #+#    #+#             */
/*   Updated: 2022/12/07 13:01:27 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*fds[OPEN_MAX];
	int			nb_of_read;
	int			just_read;
	int			tmp_i;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	nb_of_read = 0;
	while (42)
	{
		tmp = malloc(chr_i(fds[fd], '\0') + ++nb_of_read * BUFFER_SIZE + 1);
		if (!tmp)
			return (NULL);
		ft_memmove(tmp, fds[fd], chr_i(fds[fd], '\0') + 1);
		if (fds[fd] != tmp)
			free(fds[fd]);
		fds[fd] = tmp;
		tmp_i = chr_i(fds[fd], '\0');
		just_read = read(fd, fds[fd] + tmp_i, BUFFER_SIZE);
		tmp_i += just_read;
		tmp = eof(fds[fd], tmp, &just_read, tmp_i);
		if (just_read)
			return (tmp);
	}
}
