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

static char	*join_buffer(char *line, char *buffer, int read_bytes)
{
	char	*new_line;

	buffer[read_bytes] = '\0';
	if (!line)
		new_line = ft_strdup(buffer);
	else
		new_line = ft_strjoin(line, buffer);
	free(buffer);
	return (new_line);
}

static char	*get_line(char *line, int i)
{
	char	*new_line;

	if (line[i] == '\n')
		new_line = ft_substr(line, 0, i + 1);
	else if (line[i] == '\0' && i > 0)
		new_line = ft_substr(line, 0, i);
	else
		new_line = NULL;
	return (new_line);
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);

	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = get_line(list);
	polish_list(&list);

	return (next_line);
}
