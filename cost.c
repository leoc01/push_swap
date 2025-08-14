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

t_move	find_cheaper(t_heap *h, t_stack *s, t_stack *d)
{
	t_move	best;
	t_move	new;
	t_stack	*first;

	first = s;
	best = get_cost(h, s->num, first, d);
	s = s->next;
	while (s != first && best.value != 0)
	{
		new = get_cost(h, s->num, first, d);
		if (new.value < best.value)
			best = new;
		s = s->next;
	}
	return (best);
}

t_move	get_cost(t_heap *h, int num, t_stack *s, t_stack *d)
{
	int	rrn;
	int	rrt;
	int	rn;
	int	rt;
	int	target;
	t_move	move;

	move.value = 0;
	move.instruction = 'x';
	target = get_target(h, num, d);
	if (!s || !d)
		return (move);
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
	move.value = (min(min(max(rn, rt), max(rrn, rrt)), min(rn + rrt, rrn + rt)));
	if (move.value == max(rrn, rrt))
			move.instruction = '1';
	else if (move.value == max(rn, rt))
			move.instruction = '2';
	else if (s->num != num)
	{
		if (move.value == rn + rrt)
			move.instruction = '2';
		else if (move.value == rrn + rt)
			move.instruction = '4';
	}
	else if (s->num == num)
	{
		if (move.value == rn + rrt)
			move.instruction = '3';
		else if (move.value == rrn + rt)
			move.instruction = '5';
	}
	return (move);
}
