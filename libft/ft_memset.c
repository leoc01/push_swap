/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:16:10 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/04/07 20:16:19 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			cont;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	cont = 0;
	while (cont < n)
	{
		ptr[cont] = (unsigned char)c;
		cont ++;
	}
	return (s);
}
