/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:04:22 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/08/22 19:04:24 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(t_heap *h, char **nums)
{
	t_stack	*s;
	int		c;
	int		l;

	if (!nums)
		close_ps(h, 2);
	l = 0;
	while (nums[l])
		l++;
	h->a_len = l;
	h->b_len = 0;
	s = ft_calloc(l, sizeof(t_stack));
	if (!s)
		close_ps(h, 3);
	h->s = s;
	c = 0;
	while (c < l)
	{
		s[c].num = ft_atoi(nums[c]);
		if ((s[c].num == 0 && nums[c][0] != '0') || ft_strlen(nums[c]) > 11)
			close_ps(h, 9);
		c++;
	}
	link_stack(s, l);
	return (check_dup(h, s), s);
}

void	link_stack(t_stack *s, int l)
{
	int	c;

	s[0].next = &s[1];
	s[0].prev = &s[l - 1];
	c = 1;
	while (c < l - 1)
	{
		s[c].next = &s[c + 1];
		s[c].prev = &s[c - 1];
		c++;
	}
	s[l - 1].next = &s[0];
	s[l - 1].prev = &s[l - 2];
}

void	close_ps(t_heap *h, int code)
{
	char	**nums;

	nums = h->nums;
	if (nums)
	{
		while (*nums)
		{
			free(*nums);
			nums++;
		}
		free(h->nums);
	}
	if (h->s)
		free(h->s);
	if (code)
		ft_putstr_fd("Error\n", 2);
	exit(code);
}
