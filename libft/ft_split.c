/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:56:55 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/04/22 15:00:56 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

static size_t	ft_countwords(char const *s, char *c);
static int		ft_memallo(char **words, size_t w_count, size_t w_size);
static size_t	ft_defwsize(char const *s, size_t i, char c);

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	i;
	size_t	w_count;
	size_t	w_size;

	if (s == NULL)
		return (NULL);
	words = (char **)malloc((ft_countwords(s, &c) + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	i = 0;
	w_count = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] == c && ++i)
			continue ;
		w_size = ft_defwsize(s, i, c);
		if (ft_memallo(words, w_count, w_size))
			return (NULL);
		ft_strlcpy(words[w_count], &s[i], w_size);
		i += w_size;
		w_count++;
	}
	words[w_count] = NULL;
	return (words);
}

static size_t	ft_defwsize(char const *s, size_t i, char c)
{
	size_t	w_size;

	if (ft_strchr(&s[i], c) == NULL)
		c = '\0';
	w_size = ft_strchr(&s[i], c) - &s[i] + 1;
	return (w_size);
}

static int	ft_memallo(char **words, size_t w_count, size_t w_size)
{
	words[w_count] = (char *)malloc((w_size) * sizeof(char));
	if (words[w_count] == NULL)
	{
		while (w_count > 0)
		{
			free(words[--w_count]);
		}
		free(words);
		return (1);
	}
	return (0);
}

static size_t	ft_countwords(char const *s, char *c)
{
	size_t	w_count;
	size_t	i;

	i = 0;
	w_count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == *c && ++i)
		{
			continue ;
		}
		if (s[i + 1] == *c || s[i + 1] == '\0')
		{
			w_count++;
		}
		i++;
	}
	return (w_count);
}
