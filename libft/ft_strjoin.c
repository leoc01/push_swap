/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:33:02 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/04/22 12:44:33 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*newstr;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	size = 1;
	if (s1)
		size += ft_strlen(s1);
	if (s2)
		size += ft_strlen(s2);
	newstr = malloc(size * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	newstr[0] = '\0';
	if (s1)
		ft_strlcat(newstr, s1, ft_strlen(s1) + 1);
	if (s2)
		ft_strlcat(newstr, s2, ft_strlen(newstr) + ft_strlen(s2) + 1);
	return (newstr);
}
