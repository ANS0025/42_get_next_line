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

char	*get_line(char *read_lines)
{
	int		i;
	char	*str;

	i = 0;
	if (!read_lines[i])
		return (NULL);
	while (read_lines[i] && read_lines[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (read_lines[i] && read_lines[i] != '\n')
	{
		str[i] = read_lines[i];
		i++;
	}
	if (read_lines[i] == '\n')
	{
		str[i] = read_lines[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_remaining_line(char *read_lines)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (read_lines[i] && read_lines[i] != '\n')
		i++;
	if (!read_lines[i])
	{
		free(read_lines);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(read_lines) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (read_lines[i])
		str[j++] = read_lines[i++];
	str[j] = '\0';
	free(read_lines);
	return (str);
}

char	*find_newline(int fd, char *read_lines)
{
	char	*buf;
	int		rd_bytes;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(read_lines, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buf, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rd_bytes] = '\0';
		read_lines = strjoin_and_free(read_lines, buf);
	}
	free(buf);
	return (read_lines);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*read_lines = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_lines = find_newline(fd, read_lines);
	if (!read_lines)
		return (NULL);
	line = get_line(read_lines);
	read_lines = get_remaining_line(read_lines);
	return (line);
}
