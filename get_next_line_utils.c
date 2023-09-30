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

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s1) + 1;
	ptr = malloc(len);
	if (ptr)
		ft_memcpy(ptr, s1, len);
	return (ptr);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	unsigned long	len1;
	unsigned long	len2;
	char			*result;

	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
	result = (char *)malloc(len1 + len2 + 1);
	if (result == NULL)
		return (NULL);
	if (len1 > 0)
		ft_memcpy(result, s1, len1);
	if (len2 > 0)
		ft_memcpy(result + len1, s2, len2);
	result[len1 + len2] = '\0';
	return (result);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			s_len;
	size_t			i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		len = 0;
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[len] = '\0';
	return (substr);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str++ != '\0')
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (src == NULL && dst == NULL)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dst);
}
