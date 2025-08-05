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

size_t	ft_putnbr_fd(int n, int fd)
{
	int	i;

	i = 0;
	if (n >= 0)
	{
		if (n >= 10)
		{
			i += ft_putnbr_fd(n / 10, fd);
		}
		i += ft_putchar_fd(n % 10 + '0', fd);
	}
	else if (n == INT_MIN)
	{
		ft_putstr_fd("-2147483648", fd);
		i = 11;
	}
	else
	{
		i += ft_putchar_fd('-', fd);
		i += ft_putnbr_fd(n * -1, fd);
	}
	return (i);
}
