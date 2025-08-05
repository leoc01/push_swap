/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:11:30 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/04/22 13:38:32 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmedstr;
	size_t	start;
	size_t	end;

	if (s1 == NULL)
	{
		return (NULL);
	}
	if (set == NULL)
	{
		trimmedstr = ft_strdup(s1);
		return (trimmedstr);
	}
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
	{
		start++;
	}
	while (end > start && ft_strchr(set, s1[end]))
	{
		end--;
	}
	trimmedstr = ft_substr(s1, start, end - start + 1);
	return (trimmedstr);
}
