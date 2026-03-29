/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:22:04 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/03/29 19:08:47 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen(char *str)
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
	char	*tmp;
	int		len;
	int		i;
	int		j;

	tmp = stash;
	if (!stash)
		stash = "";
	if (!buf)
		return (free(tmp), NULL);
	len = ft_strlen(stash);
	res = malloc(sizeof(char) * (len + ft_strlen(buf) + 1));
	if (!res)
		return (free(tmp), NULL);
	i = -1;
	while (stash[++i])
		res[i] = stash[i];
	if (tmp)
		free(tmp);
	j = -1;
	while (buf[++j])
		res[len + j] = buf[j];
	res[len + j] = '\0';
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
	int		i;
	int		j;

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
	return (free(stash), NULL);
}
