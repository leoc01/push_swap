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
	while (s != first && best.cost != 0)
	{
		new = get_cost(h, s->num, first, d);
		if (new.cost < best.cost)
			best = new;
		s = s->next;
	}
	def_move(&best);
	return (best);
}

void	def_move(t_move *best)
{
	(void)best;
	return ;	
}

t_move	get_cost(t_heap *h, int num, t_stack *s, t_stack *d)
{
	t_move	move;
	int	rn;
	int	rt;
	int rrn;
	int rrt;

	move.instruction = 'p';
	move.num = num;
	move.target = get_target(h, num, d);
	if (!s || !d)
		return (move);
	rrn = get_position(num, s);
	rrt = get_position(move.target, d);
	rn = get_len(h, s) - rrn;
	rt = get_len(h, d) - rrt;
	move.cost = (min(min(max(rn, rt), max(rrn, rrt)), min(rn + rrt, rrn + rt)));
	return (move);
}
