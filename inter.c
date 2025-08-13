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

static void		print_stack(t_stack *s);

void	debug_interactive(t_heap *h)
{
	char	cmd[32];

	while (1)
	{
		write(1, "\033[H\033[J", 6);
		printf("\nStack A:\n");
		print_stack(h->a);
		printf("\nStack B:\n");
		print_stack(h->b);
		if (is_sorted(h->a) && h->b == NULL)
		{
			printf("\nA is sorted!\n");
			break ;
		}
		else if (h->a && h->b)
		{
			printf("\nTarget for %d in A is %d in B.", h->a->num, a_target(h->a->num, h->b));
			printf("\nTarget for %d in B is %d in A.", h->b->num, b_target(h->b->num, h->a));
		}
		printf("\nA length is %d.", h->a_len);
		printf("\nB length is %d.", h->b_len);
		//else
		//	printf("\nKeep pushing and swapping, or maybe just rotating!");
		printf("\nEnter instruction (or 'q' to quit): ");
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

static void	print_stack(t_stack *s)
{
	t_stack	*first;

	if (!s)
		return ;
	ft_putnbr_fd(s->num, 1);
	ft_putstr_fd("\n", 1);
	first = s;
	s = s->next;
	while (s && s != first)
	{
		ft_putnbr_fd(s->num, 1);
		ft_putstr_fd("\n", 1);
		s = s->next;
	}
}
