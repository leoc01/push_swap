/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:49:06 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/05/06 14:49:07 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			position;
	unsigned char	*dest_ptr;

	dest_ptr = (unsigned char *)dest;
	if (dest == NULL && src == NULL)
		return (dest_ptr);
	position = 0;
	while (position < n)
	{
		dest_ptr[position] = ((unsigned char *)src)[position];
		position++;
	}
	return (dest_ptr);
}

t_gnlist	*new_list(char *buffer, int r_buffer)
{
	t_gnlist	*node;
	int		i;

	i = 0;
	node = malloc(sizeof(t_gnlist));
	if (!node)
		return (NULL);
	while (i < BUFFER_SIZE)
		node->buffer[i++] = '\0';
	i = 0;
	node->next = NULL;
	node->line_len = 0;
	while (i < r_buffer)
	{
		node->buffer[i] = buffer[i];
		node->line_len++;
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	return (node);
}

t_gnlist	*list_last(t_gnlist *buffer_list)
{
	if (!buffer_list)
		return (NULL);
	while (buffer_list->next)
		buffer_list = buffer_list->next;
	return (buffer_list);
}

int	list_add(t_gnlist **buffer_list, t_gnlist *new)
{
	if (!new)
	{
		list_clear(buffer_list);
		return (0);
	}
	if (!(*buffer_list))
	{
		*buffer_list = new;
		return (1);
	}
	(list_last(*buffer_list))->next = new;
	return (1);
}

void	list_clear(t_gnlist **buffer_list)
{
	t_gnlist	*aux_list;

	if (buffer_list == NULL)
		return ;
	while (*buffer_list != NULL)
	{
		aux_list = (*buffer_list)->next;
		free(*buffer_list);
		*buffer_list = aux_list;
	}
}
