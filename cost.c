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

void	find_cheaper(t_heap *h, t_stack *s, t_stack *d)
{
	int		cost;
	int		new_cost;
	t_stack	*first;

	first = s;
	cost = get_cost(h, s->num, first, d);
	while (s != first && cost != 0)
	{
		new_cost = get_cost(h, s->num, first, d);
		if (new_cost < cost)
			cost = new_cost;
		s = s->next;
	}
}

int	get_cost(t_heap *h, int num, t_stack *s, t_stack *d)
{
	int	rrn;
	int	rrt;
	int	rn;
	int	rt;
	int	target;

	target = get_target(h, num, d);
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


