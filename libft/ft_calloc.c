/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:46:05 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/04/21 17:52:21 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_space;

	if (size != 0 && nmemb > SIZE_MAX / size)
	{
		return (NULL);
	}
	total_space = nmemb * size;
	ptr = malloc(total_space);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_memset(ptr, '\0', total_space);
	return (ptr);
}
