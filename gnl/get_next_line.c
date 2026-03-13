/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:01:33 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/03/13 12:31:54 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_validate_input(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	return (1);
}

static char	*ft_read_and_accumulate(int fd, char *stash)
{
	char	*buf;
	ssize_t	n;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	n = 1;
	while (!ft_has_newline(stash) && n > 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
			return (free(buf), free(stash), stash = NULL, NULL);
		buf[n] = '\0';
		stash = ft_strjoin(stash, buf);
		if (!stash)
			return (free(buf), NULL);
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (!ft_validate_input(fd))
		;
	return (NULL);
	stash = ft_read_and_accumulate(fd, stash);
	if (!stash || stash[0] == '\0')
		return (free(stash), stash = NULL, NULL);
	line = ft_extract_line(stash);
	stash = ft_update_stash(stash);
	return (line);
}
