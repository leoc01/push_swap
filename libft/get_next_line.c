/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:08:27 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/06/03 16:08:28 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_buffer(int fd, char *buffer, int *nextline_in)
{
	int	i;

	i = 0;
	*nextline_in = 0;
	while (i < BUFFER_SIZE)
		buffer[i++] = '\0';
	return (read(fd, buffer, BUFFER_SIZE));
}

static char	*save_line(t_gnlist *buffer_list)
{
	char	*line;
	int		size;
	int		i;
	t_gnlist	*aux_list;

	aux_list = buffer_list;
	size = 0;
	while (aux_list)
	{
		size += aux_list->line_len;
		aux_list = aux_list->next;
	}
	line = malloc((size + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer_list && buffer_list->line_len)
	{
		ft_memcpy(&line[i], buffer_list->buffer, buffer_list->line_len);
		i += buffer_list->line_len;
		buffer_list = buffer_list->next;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE];
	static int	r_buffer;
	static int	nextline_in;
	t_gnlist		*buffer_list;

	buffer_list = NULL;
	line = NULL;
	if (r_buffer <= 0)
		r_buffer = get_buffer(fd, buffer, &nextline_in);
	while (r_buffer > 0)
	{
		if (!list_add(&buffer_list, new_list(&buffer[nextline_in], r_buffer)))
			break ;
		nextline_in += list_last(buffer_list)->line_len;
		r_buffer -= list_last(buffer_list)->line_len;
		if (nextline_in < BUFFER_SIZE || buffer[BUFFER_SIZE - 1] == '\n')
			break ;
		r_buffer = get_buffer(fd, buffer, &nextline_in);
	}
	if (r_buffer != -1 && buffer_list)
		line = save_line(buffer_list);
	list_clear(&buffer_list);
	return (line);
}
