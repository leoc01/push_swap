/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:47:39 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/04/18 17:52:29 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if ((unsigned char)little[0] == '\0')
		return ((char *)big);
	i = 0;
	j = 0;
	while ((unsigned char)big[i] != '\0' && i < len)
	{
		while ((unsigned char)big[i + j] == (unsigned char)little[j])
		{
			j++;
			if (i + j > len)
				break ;
			if ((unsigned char)little[j] == '\0')
				return (&((char *)big)[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
