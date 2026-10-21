/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakong <yakong@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:23:32 by yakong            #+#    #+#             */
/*   Updated: 2026/10/20 16:09:10 by yakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_stash(int fd, char *stash)
{
	char	*buffer;
	char	*new_stash;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(stash), NULL);
	while (!ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(stash), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		new_stash = ft_strjoin(stash, buffer);
		if (!new_stash)
			return (free(buffer), free(stash), NULL);
		free (stash);
		stash = new_stash;
	}
	free (buffer);
	return (stash);
}

static char	*extract_line(char *stash)
{
	char	*p;
	int		line_len;
	char	*line;

	if (!stash || !*stash)
		return (NULL);
	p = stash;
	while (*p && *p != '\n')
		p++;
	if (*p == '\n')
		p++;
	line_len = p - stash;
	line = ft_substr(stash, 0, line_len);
	return (line);
}

static char	*updated_stash(int line_len, char *stash)
{
	int		rest_len;
	char	*new_stash;

	if (!stash || !stash[line_len])
		return (NULL);
	rest_len = ft_strlen(stash) - line_len;
	new_stash = ft_substr(stash, line_len, rest_len);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*new_stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash || !*stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	new_stash = updated_stash(ft_strlen(line), stash);
	free(stash);
	stash = new_stash;
	return (line);
}
