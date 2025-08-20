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

static void	do_move(t_heap *h, char stack, char *instruction);
static void	min_to_top(t_heap *h);

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
		rra(h, 1);
	else if (h->a->num > h->a->next->num && h->a->num > h->a->prev->num)
		ra(h, 1);
	if (h->a->num > h->a->next->num)
		sa(h, 1);
}

void	push_swap(t_heap *h)
{
	int		c;
	t_move	best;

	c = 2;
	while (h->a_len > 3 && c--)
		pb(h, 1);
	while (h->a_len > 3)
	{
		best = find_cheaper(h, h->a, h->b);
		do_move(h, 'a', best.instruction);
	}
	if (!is_sorted(h->a) && h->a_len == 3)
		sort_three(h);
	while (h->b_len > 0)
	{
		best = find_cheaper(h, h->b, h->a);
		do_move(h, 'b', best.instruction);
	}
	min_to_top(h);
}

static void	min_to_top(t_heap *h)
{
	int		a_min;
	int		a_pos;
	int		rot;

	a_min = get_min(h->a);
	a_pos = get_position(a_min, h->a);
	rot = 1;
	if (a_pos < h->a_len / 2)
		rot = -1;
	while (h->a->num != a_min)
	{
		if (rot == 1)
			rra(h, 1);
		else
			ra(h, 1);
	}
}

static void	do_move(t_heap *h, char stack, char *instruction)
{
	if (ft_strncmp(instruction, "rr", 4) == 0)
		rr(h);
	else if (ft_strncmp(instruction, "rrr", 4) == 0)
		rrr(h);
	else if (stack == 'a' && ft_strncmp(instruction, "p", 4) == 0)
		pb(h, 1);
	else if (stack == 'b' && ft_strncmp(instruction, "p", 4) == 0)
		pa(h, 1);
	else if ((stack == 'a' && ft_strncmp(instruction, "rn", 4) == 0)
		|| (stack == 'b' && ft_strncmp(instruction, "rt", 4) == 0))
		ra(h, 1);
	else if ((stack == 'a' && ft_strncmp(instruction, "rt", 4) == 0)
		|| (stack == 'b' && ft_strncmp(instruction, "rn", 4) == 0))
		rb(h, 1);
	else if ((stack == 'a' && ft_strncmp(instruction, "rrn", 4) == 0)
		|| (stack == 'b' && ft_strncmp(instruction, "rrt", 4) == 0))
		rra(h, 1);
	else if ((stack == 'a' && ft_strncmp(instruction, "rrt", 4) == 0)
		|| (stack == 'b' && ft_strncmp(instruction, "rrn", 4) == 0))
		rrb(h, 1);
}
