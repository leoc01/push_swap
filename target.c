/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:12:47 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/08/14 13:57:33 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target(t_heap *h, int num, t_stack *d)
{
	int	lo;
	int	hi;

	lo = get_min(d);
	hi = get_max(d);
	if (d == h->b)
		return (a_target(num, d, lo, hi));
	else if (d == h->a)
		return (b_target(num, d, lo, hi));
	return (0);
}

int	a_target(int num, t_stack *s, int l, int h)
{
	long	diff;
	int		new_diff;
	t_stack	*first;

	first = s;
	new_diff = num - first->num;
	s = s->next;
	diff = h - l;
	if (new_diff > 0)
		diff = new_diff;
	while (s != first)
	{
		new_diff = num - s->num;
		if (new_diff > 0 && new_diff < diff)
			diff = new_diff;
		s = s->next;
	}
	if (diff == h - l)
		return (h);
	return (num - diff);
}

int	b_target(int num, t_stack *s, int l, int h)
{
	int		diff;
	int		new_diff;
	t_stack	*first;

	first = s;
	new_diff = num - first->num;
	s = s->next;
	diff = l - h;
	if (new_diff < 0)
		diff = new_diff;
	while (s != first)
	{
		new_diff = num - s->num;
		if (new_diff < 0 && new_diff > diff)
			diff = new_diff;
		s = s->next;
	}
	if (diff == l - h)
		return (l);
	return (num - diff);
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
