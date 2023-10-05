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

void	polish_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	clean_node = malloc(sizeof(t_list));
	if (!clean_node || !buffer)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	j = 0;
	while (last_node->str_buffer[i] && last_node->str_buffer[i] != '\n')
		i++;
	while (last_node->str_buffer[i] && last_node->str_buffer[i++])
		buffer[j++] = last_node->str_buffer[i];
	buffer[j] = '\0';
	clean_node->str_buffer = buffer;
	clean_node->next = NULL;
	dealloc(list, clean_node, buffer);
}

char	*get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (!list)
		return (NULL);
	str_len = len_to_newline(list);
	next_str = malloc(sizeof(char) * (str_len + 1));
	if (!next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

void	append(t_list **list, char *buffer)
{
	t_list	*new;
	t_list	*last_node;

	new = malloc(sizeof(t_list));
	last_node = find_last_node(*list);
	if (!new)
		return ;
	if (!last_node)
		*list = new;
	else
		last_node->next = new;
	new->str_buffer = buffer;
	new->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buffer;

	while (!found_newline(*list))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (!char_read)
		{
			free(buffer);
			return ;
		}
		buffer[char_read] = '\0';
		append(list, buffer);
	}
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
