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
	def_move(h, &best);
	return (best);
}

void	def_move(t_heap *h, t_move *best)
{	
	int	rn;
	int	rt;
	int rrn;
	int rrt;

	rn = get_position(best->num, best->s);
	rt = get_position(best->target, best->d);
	rrn = get_len(h, best->s) - rn;
	rrt = get_len(h, best->d) - rt;

	if (best->cost == 0)
		return ;
	else if (best->cost == rn + rrt && rn)
		ft_strlcpy(best->instruction, "rn", 4);
	else if (best->cost == rn + rrt && !rn) 
		ft_strlcpy(best->instruction, "rrt", 4);
	else if (best->cost == rrn + rt && rt)
		ft_strlcpy(best->instruction, "rt", 4);
	else if (best->cost == rrn + rt && !rt) 
		ft_strlcpy(best->instruction, "rrn", 4);
	else if (best->cost == max(rn, rt) && rn && rt)
		ft_strlcpy(best->instruction, "rr", 4);
	else if (best->cost == max(rn, rt) && rn && !rt)
		ft_strlcpy(best->instruction, "rn", 4);
	else if (best->cost == max(rn, rt) && !rn && rt)
		ft_strlcpy(best->instruction, "rt", 4);
	else if (best->cost == max(rrn, rrt) && rrn && rrt)
		ft_strlcpy(best->instruction, "rrr", 4);
	else if (best->cost == max(rrn, rrt) && rrn && !rrt)
		ft_strlcpy(best->instruction, "rrn", 4);
	else if (best->cost == max(rrn, rrt) && !rrn && rrt)
		ft_strlcpy(best->instruction, "rrt", 4);
}

t_move	get_cost(t_heap *h, int num, t_stack *s, t_stack *d)
{
	t_move	move;
	int	rn;
	int	rt;
	int rrn;
	int rrt;

	ft_strlcpy(move.instruction, "p", 4);
	move.num = num;
	move.target = get_target(h, num, d);
	move.s = s;
	move.d = d;
	if (!s || !d)
		return (move);
	rn = get_position(num, s);
	rt = get_position(move.target, d);
	rrn = get_len(h, s) - rn;
	rrt = get_len(h, d) - rt;
	move.cost = (min(min(max(rn, rt), max(rrn, rrt)), min(rn + rrt, rrn + rt)));
	return (move);
}
