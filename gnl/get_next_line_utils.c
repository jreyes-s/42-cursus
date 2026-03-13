/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:22:04 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/03/13 12:45:34 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	copy_stash(char *stash, char *res)
{
	int	i;

	i = 0;
	while (stash[i])
	{
		res[i] = stash[i];
		i++;
	}
}

static void	copy_buf(char *buf, char *res, int offset)
{
	int	j;

	j = 0;
	while (buf[j])
	{
		res[offset + j] = buf[j];
		j++;
	}
	res[offset + j] = '\0';
}

char	*ft_strjoin(char *stash, char *buf)
{
	char	*res;
	char	*tmp;
	int		len;

	tmp = stash;
	if (!stash)
		stash = "";
	if (!buf)
		return (free(tmp), NULL);
	len = ft_strlen(stash);
	res = malloc(sizeof(char) * (len + ft_strlen(buf) + 1));
	if (!res)
		return (free(tmp), NULL);
	copy_stash(stash, res);
	if (tmp)
		free(tmp);
	copy_buf(buf, res, len);
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

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len && stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (i < len && stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_update_stash(char *stash)
{
	int		i;
	int		start;
	char	*new_stash;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			start = ++i;
			new_stash = malloc(sizeof(char) * (ft_strlen(stash) - start + 1));
			if (!new_stash)
				return (free(stash), NULL);
			start = 0;
			while (stash[i])
				new_stash[start++] = stash[i++];
			new_stash[start] = '\0';
			return (free(stash), new_stash);
		}
		i++;
	}
	return (free(stash), NULL);
}
