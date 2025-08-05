/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:11:06 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/04/24 15:53:27 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	ft_getlen(int n);
static int	ft_isnegative(char *num, int n);

char	*ft_itoa(int n)
{
	char	*num;
	int		len;

	num = NULL;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = ft_getlen(n);
	num = ft_calloc((len + 1), sizeof(char));
	if (num == NULL)
		return (NULL);
	else
	{
		n = ft_isnegative(num, n);
		num[len] = '\0';
		while (len > 0)
		{
			--len;
			if (len > 0 || num[0] != '-')
				num[len] = n % 10 + 48;
			n /= 10;
		}
	}
	return (num);
}

static int	ft_isnegative(char *num, int n)
{
	if (n < 0)
	{
		num[0] = '-';
		n *= -1;
	}
	return (n);
}

static int	ft_getlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}
