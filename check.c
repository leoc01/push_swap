/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:10:57 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/08/21 15:11:11 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_nums(t_heap *h, char **nums)
{
	int	w;
	int	d;

	if (!nums)
		close_ps(h, 4);
	w = 0;
	while (nums && nums[w])
	{
		d = 0;
		while (nums[w][d])
		{
			if (!ft_isdigit(nums[w][d]) && nums[w][d] != '-')
				close_ps(h, 5);
			if (nums[w][d] == '-' && !ft_isdigit(nums[w][d + 1]))
				close_ps(h, 6);
			if (d > 0 && !ft_isdigit(nums[w][d]))
				close_ps(h, 7);
			d++;
		}
		w++;
	}
}

void	check_dup(t_heap *h, t_stack *s)
{
	t_stack *first;
	t_stack *this;

	first = s;
	this = first->next;
	while (this != first)
	{
		s = this->next;
		while (s != this)
		{
			if (this->num == s->num)
				close_ps(h, 8);
			s = s->next;
		}
		this = this->next;
	}
}
