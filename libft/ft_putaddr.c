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

size_t	ft_putaddr(unsigned long int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (ft_putstr_fd("(nil)", 1));
	if (n >= 16)
		i += ft_putaddr(n / 16);
	else
		i += ft_putstr_fd("0x", 1);
	if ((n % 16) < 10)
		i += ft_putchar_fd(n % 16 + '0', 1);
	else if ((n % 16) < 16)
		i += ft_putchar_fd(n % 16 + 'a' - 10, 1);
	return (i);
}
