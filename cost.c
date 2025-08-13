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
/*
void	find_cheaper()
{
	int	cost;

	cost = calculate_cost(
}
*/
int	calculate_cost(t_heap *h, int num, int target, t_stack *from, t_stack *dest)
{
	int	rrn;
	int	rrt;
	int	rn;
	int	rt;

	if (!from || !dest)
		return (0);
	rrn = get_position(num, from);
	rrt = get_position(target, dest);
	if (from == h->a)
	{
		rn = h->a_len - rrn;
		rt = h->b_len - rrt;
	}
	else
	{
		rn = h->b_len - rrn;
		rt = h->a_len - rrt;
	}
	if (min(max(rn, rt), max(rrn, rrt)) < min(rn + rrt, rrn + rt))
		return (min(max(rn, rt), max(rrn, rrt)));
	return (min(rn+rrt, rrn + rt));
}

int get_position(int num, t_stack *s)
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
