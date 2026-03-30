/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:22:04 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/03/30 23:16:15 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen(char const *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *stash, char *buf)
{
	char	*res;
	int		i;
	int		j;

	if (!buf)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buf) + 1));
	if (!res)
		return (free(stash), NULL);
	i = 0;
	while (stash && stash[i])
	{
		res[i] = stash[i];
		i++;
	}
	j = 0;
	while (buf && buf[j])
	{
		res[i + j] = buf[j];
		j++;
	}
	res[i + j] = '\0';
	free(stash);
	return (res);
}

int	ft_has_newline(char *stash)
{
	int	i;

	if (!stash)
		return (0);
	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_extract_line(char *stash)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	if (!stash || stash[0] == '\0')
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (stash[j] && stash[j] != '\n')
	{
		line[j] = stash[j];
		j++;
	}
	if (stash[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*ft_update_stash(char *stash)
{
	int	i;
	int	j;

	if (!stash || stash[0] == '\0')
		return (free(stash), NULL);
	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			i++;
			if (stash[i] == '\0')
				return (free(stash), NULL);
			j = 0;
			while (stash[i])
				stash[j++] = stash[i++];
			stash[j] = '\0';
			return (stash);
		}
		i++;
	}
	free(stash);
	return (NULL);
}
