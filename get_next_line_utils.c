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

char	*strjoin_and_free(char *prev_line, char *buf)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!prev_line)
	{
		prev_line = (char *)malloc(1 * sizeof(char));
		prev_line[0] = '\0';
	}
	if (!prev_line || !buf)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(prev_line) + ft_strlen(buf)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (prev_line)
		while (prev_line[++i] != '\0')
			str[i] = prev_line[i];
	while (buf[j] != '\0')
		str[i++] = buf[j++];
	str[ft_strlen(prev_line) + ft_strlen(buf)] = '\0';
	free(prev_line);
	return (str);
}
