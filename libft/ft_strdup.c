/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:46:46 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/04/21 20:24:37 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s) + 1;
	str = malloc(size);
	if (!str)
	{
		return (NULL);
	}
	while (i < size)
	{
		str[i] = s[i];
		i++;
	}
	i = 0;
	return (str);
}
