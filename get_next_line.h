/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiseki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:52:27 by akiseki           #+#    #+#             */
/*   Updated: 2023/09/30 13:52:31 by akiseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			*str_buffer;
	struct s_list	*next;
}		t_list;

char	*get_next_line(int fd);
void	create_list(t_list **list, int fd);
void	append(t_list **list, char *buffer);
char	*get_line(t_list *list);
void	polish_list(t_list **list);
int		len_to_newline(t_list *list);
void	copy_str(t_list	*list, char *str);
void	dealloc(t_list **list, t_list *clean_node, char *buffer);
t_list	*find_last_node(t_list *list);
int		found_newline(t_list *list);

#endif
