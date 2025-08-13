/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:15:20 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/08/13 13:39:10 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max(int n1, int n2);
static int	min(int n1, int n2);

void	find_cheaper(t_heap *h, t_stack *s, t_stack *d)
{
	int		cost;
	int		new_cost;
	t_stack	*first;

	first = s;
	cost = calculate_cost(h, s->num, a_target(s->num, d), s, d);
	while (s != first && cost != 0)
	{
		new_cost = calculate_cost(h, s->num, a_target(s->num, d), s, d);
		if (new_cost < cost)
			cost = new_cost;
		s = s->next;
	}
}

int	calculate_cost(t_heap *h, int num, int target, t_stack *s, t_stack *d)
{
	int	rrn;
	int	rrt;
	int	rn;
	int	rt;

	if (!s || !d)
		return (0);
	rrn = get_position(num, s);
	rrt = get_position(target, d);
	if (s == h->a)
	{
		rn = h->a_len - rrn;
		rt = h->b_len - rrt;
	}
	else
	{
		rn = h->b_len - rrn;
		rt = h->a_len - rrt;
	}
	return (min(min(max(rn, rt), max(rrn, rrt)), min(rn + rrt, rrn + rt)));
}

int	get_position(int num, t_stack *s)
{
	t_stack	*first;
	int		p;

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

static int	max(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	return (n2);
}

static int	min(int n1, int n2)
{
	if (n1 <= n2)
		return (n1);
	return (n2);
}
