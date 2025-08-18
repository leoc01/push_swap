/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:43:19 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/08/08 17:46:16 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>
#include <stdio.h>

static void		print_a(t_heap *h);
static void		print_b(t_heap *h);

void	debug_interactive(t_heap *h)
{
	char	cmd[32];
	t_move best;

	while (1)
	{
		write(1, "\033[H\033[J", 6);
		printf("\nStack A (%d)\tTarget\tCost\n", h->a_len);
		print_a(h);
		printf("\nStack B (%d)\tTarget\tCost\n", h->b_len);
		print_b(h);
		if (is_sorted(h->a) && h->b == NULL)
		{
			printf("\nCongrats!!\n\nThe stack is sorted!\n");
			break ;
		}
		best = find_cheaper(h, h->a, h->b);
		printf("\nKeep pushing and swapping, or maybe just rotating!\n");
		printf("\nEnter instruction (hint - %s, cost - %d) %d on %d: ", best.instruction, best.cost, best.num, best.target);
		if (!fgets(cmd, sizeof(cmd), stdin))
			break ;
		cmd[strcspn(cmd, "\n")] = 0;
		if (strcmp(cmd, "q") == 0)
			break ;
		if (strcmp(cmd, "sa") == 0)
			sa(h, 1);
		else if (strcmp(cmd, "sb") == 0)
			sb(h, 1);
		else if (strcmp(cmd, "ss") == 0)
			ss(h);
		else if (strcmp(cmd, "pa") == 0)
			pa(h, 1);
		else if (strcmp(cmd, "pb") == 0)
			pb(h, 1);
		else if (strcmp(cmd, "ra") == 0)
			ra(h, 1);
		else if (strcmp(cmd, "rb") == 0)
			rb(h, 1);
		else if (strcmp(cmd, "rr") == 0)
			rr(h);
		else if (strcmp(cmd, "rra") == 0)
			rra(h, 1);
		else if (strcmp(cmd, "rrb") == 0)
			rrb(h, 1);
		else if (strcmp(cmd, "rrr") == 0)
			rrr(h);
	}
}

static void	print_a(t_heap *h)
{
	t_stack	*first;
	t_stack	*s;
	t_stack	*d;
	int		target;
	int		cost;

	s = h->a;
	d = h->b;
	if (!s)
		return ;
	first = s;
	printf(" %d", s->num);
	if (d)
	{
		target = get_target(h, s->num, d);
		cost = get_cost(h, s->num, first, d).cost;
		printf("\t\t ->%d\t $%d", target, cost);
	}
	s = s->next;
	while (s && s != first)
	{
		printf("\n %d", s->num);
		if (d)
		{
			target = get_target(h, s->num, d);
			cost = get_cost(h, s->num, first, d).cost;
			printf("\t\t ->%d\t $%d", target, cost);
		}
		s = s->next;
	}
	printf("\n");
}

static void	print_b(t_heap *h)
{
	t_stack	*first;
	t_stack	*s;
	t_stack	*d;
	int		target;
	int		cost;

	s = h->b;
	d = h->a;
	if (!s)
		return ;
	first = s;
	printf(" %d", s->num);
	if (d)
	{
		target = get_target(h, s->num, d);
		cost = get_cost(h, s->num, first, d).cost;
		printf("\t\t ->%d\t $%d", target, cost);
	}
	s = s->next;
	while (s && s != first)
	{
		printf("\n %d", s->num);
		if (d)
		{
			target = get_target(h, s->num, d);
			cost = get_cost(h, s->num, first, d).cost;
			printf("\t\t ->%d\t $%d", target, cost);
		}
		s = s->next;
	}
	printf("\n");
}
