/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:57:42 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/04/10 16:00:08 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_ptr;

	dest_ptr = (unsigned char *)dest;
	if ((unsigned char *)src > dest_ptr)
	{
		ft_memcpy(dest, src, n);
	}
	else if ((unsigned char *)src < dest_ptr)
	{
		while (n-- > 0)
		{
			dest_ptr[n] = ((unsigned char *)src)[n];
		}
	}
	return (dest);
}
