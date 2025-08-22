/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:15:20 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/08/22 16:55:55 by lbuscaro         ###   ########.fr       */
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

void	def_move(t_move *mov)
{
	if (mov->cost == 0)
		return ;
	else if (mov->cost == mov->rn + mov->rrt && mov->rn)
		ft_strlcpy(mov->instruction, "rn", 4);
	else if (mov->cost == mov->rn + mov->rrt && !mov->rn)
		ft_strlcpy(mov->instruction, "rrt", 4);
	else if (mov->cost == mov->rrn + mov->rt && mov->rt)
		ft_strlcpy(mov->instruction, "rt", 4);
	else if (mov->cost == mov->rrn + mov->rt && !mov->rt)
		ft_strlcpy(mov->instruction, "rrn", 4);
	else if (mov->cost == max(mov->rn, mov->rt) && mov->rn && mov->rt)
		ft_strlcpy(mov->instruction, "rr", 4);
	else if (mov->cost == max(mov->rn, mov->rt) && mov->rn && !mov->rt)
		ft_strlcpy(mov->instruction, "rn", 4);
	else if (mov->cost == max(mov->rn, mov->rt) && !mov->rn && mov->rt)
		ft_strlcpy(mov->instruction, "rt", 4);
	else if (mov->cost == max(mov->rrn, mov->rrt) && mov->rrn && mov->rrt)
		ft_strlcpy(mov->instruction, "rrr", 4);
	else if (mov->cost == max(mov->rrn, mov->rrt) && mov->rrn && !mov->rrt)
		ft_strlcpy(mov->instruction, "rrn", 4);
	else if (mov->cost == max(mov->rrn, mov->rrt) && !mov->rrn && mov->rrt)
		ft_strlcpy(mov->instruction, "rrt", 4);
}

t_move	get_cost(t_heap *h, int num, t_stack *s, t_stack *d)
{
	t_move	move;
	int		rn;
	int		rt;
	int		rrn;
	int		rrt;

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
	move.rn = rn;
	move.rt = rt;
	move.rrn = rrn;
	move.rrt = rrt;
	move.cost = (min(min(max(rn, rt), max(rrn, rrt)), min(rn + rrt, rrn + rt)));
	return (move);
}
