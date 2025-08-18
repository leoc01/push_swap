/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:25:37 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/08/14 15:25:38 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(int num, t_stack *s)
{
	t_stack	*first;
	int		p;

	if (!s)
		return (0);
	p = 0;
	first = s;
	if (first->num == num)
		return (p);
	s = s->next;
	while (s != first)
	{
		p++;
		if (s->num == num)
			return (p);
		s = s->next;
	}
	return (0);
}

int	get_len(t_heap *h, t_stack *s)
{
	if (s == h->a)
		return (h->a_len);
	return (h->b_len);
}

int	max(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	return (n2);
}

int	min(int n1, int n2)
{
	if (n1 <= n2)
		return (n1);
	return (n2);
}
