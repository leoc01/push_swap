/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:12:47 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/08/14 13:58:11 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	int	c;

	c = 2;
	while (h->a_len > 3 && c--)
		pb(h, 1);
	while (h->a_len > 3)
		break ;
	if (!is_sorted(h->a) && h->a_len == 3)
		sort_three(h);
}
