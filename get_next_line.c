/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:49:16 by akiseki           #+#    #+#             */
/*   Updated: 2023/09/30 13:49:25 by akiseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *prev_line)
{
	int		i;
	char	*str;

	i = 0;
	if (!prev_line[i])
		return (NULL);
	while (prev_line[i] && prev_line[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (prev_line[i] && prev_line[i] != '\n')
	{
		str[i] = prev_line[i];
		i++;
	}
	if (prev_line[i] == '\n')
	{
		str[i] = prev_line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_prev_line(char *prev_line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (prev_line[i] && prev_line[i] != '\n')
		i++;
	if (!prev_line[i])
	{
		free(prev_line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(prev_line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (prev_line[i])
		str[j++] = prev_line[i++];
	str[j] = '\0';
	free(prev_line);
	return (str);
}

char	*get_prev_line(int fd, char *prev_line)
{
	char	*buf;
	int		rd_bytes;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(prev_line, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buf, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rd_bytes] = '\0';
		prev_line = strjoin_and_free(prev_line, buf);
	}
	free(buf);
	return (prev_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*prev_line = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	prev_line = get_prev_line(fd, prev_line);
	if (!prev_line)
		return (NULL);
	line = get_line(prev_line);
	prev_line = new_prev_line(prev_line);
	return (line);
}
