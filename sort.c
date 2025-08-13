/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:12:47 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/08/11 18:10:54 by lbuscaro         ###   ########.fr       */
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
	//if (!is_sorted(h->a))
	//	sort_three(h);
}

int	a_target(int num, t_stack *b)
{
	long	diff;
	int		new_diff;
	int		max;
	int		min;
	t_stack	*first;

	first = b;
	max = get_max(b);
	min = get_min(b);
	diff = max - min;
	new_diff = num - b->num;
	if(new_diff > 0)
		diff = new_diff;
	b = b->next;
	while (b != first)
	{
		new_diff = num - b->num;
		if (new_diff > 0 && new_diff < diff)
			diff = new_diff;
		b = b->next;
	}
	if (diff == max - min)
		return (max);
	return (num - diff);
}

int	b_target(int num, t_stack *a)
{
	int		diff;
	int		new_diff;
	int		max;
	int		min;
	t_stack	*first;

	first = a;
	max = get_max(a);
	min = get_min(a);
	diff = max - min;
	new_diff = a->num - num;
	if (new_diff > 0)
		diff = new_diff;
	a = a->next;
	while (a != first)
	{
		new_diff = a->num - num;
		if (new_diff > 0 && new_diff < diff)
			diff = new_diff;
		a = a->next;
	}
	if (diff == max - min)
		return (min);
	return (num + diff);
}

int	get_max(t_stack *s)
{
	int		max;
	t_stack	*first;

	first = s;
	max = first->num;
	s = s->next;
	while (s != first)
	{
		if (s->num > max)
			max = s->num;
		s = s->next;
	}
	return (max);
}

int	get_min(t_stack *s)
{
	int		min;
	t_stack	*first;

	first = s;
	min = first->num;
	s = s->next;
	while (s != first)
	{
		if (s->num < min)
			min = s->num;
		s = s->next;
	}
	return (min);
}
