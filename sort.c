/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:12:47 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/08/11 11:23:37 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s)
{
	t_stack	*first;

	if (!s)
		return (0);
	first = s;
	s = s->next;
	while (s != first)
	{
		if (s->prev->num > s->num)
			return (0);
		s = s->next;
	}
	return (1);
}

void	sort_three(t_heap *h)
{
	if (h->a->next->num > h->a->num && h->a->next->num > h->a->prev->num)
		ra(h, 1);
	else if (h->a->num > h->a->next->num && h->a->num > h->a->prev->num)
		rra(h, 1);
	if (h->a->num > h->a->next->num)
		sa(h, 1);
}

void	push_swap(t_heap *h)
{
	if (!is_sorted(h->a))
		sort_three(h);
}
