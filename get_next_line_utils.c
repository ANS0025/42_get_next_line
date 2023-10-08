/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:49:49 by akiseki           #+#    #+#             */
/*   Updated: 2023/09/30 13:49:52 by akiseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str++ != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*strjoin_and_free(char *read_lines, char *buf)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!read_lines)
	{
		read_lines = (char *)malloc(1 * sizeof(char));
		read_lines[0] = '\0';
	}
	if (!read_lines || !buf)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(read_lines) + ft_strlen(buf)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (read_lines)
		while (read_lines[++i] != '\0')
			str[i] = read_lines[i];
	while (buf[j] != '\0')
		str[i++] = buf[j++];
	str[ft_strlen(read_lines) + ft_strlen(buf)] = '\0';
	free(read_lines);
	return (str);
}
