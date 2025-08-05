/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:18:22 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/04/10 19:18:32 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen((char *)src);
	i = 0;
	while (size != 0 && i < size - 1 && i < src_len)
	{
		dest[i] = (char)src[i];
		i++;
	}
	if (size > 0)
	{
		dest[i] = '\0';
	}
	return (src_len);
}
