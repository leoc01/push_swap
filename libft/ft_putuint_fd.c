/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:45:58 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/04/29 13:46:11 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putuint_fd(unsigned int n, char *base, int fd)
{
	size_t	div;
	size_t	i;

	i = 0;
	div = ft_strlen(base);
	if (n >= div)
	{
		i += ft_putuint_fd(n / div, base, fd);
	}
	i += ft_putchar_fd(base[n % div], fd);
	return (i);
}
