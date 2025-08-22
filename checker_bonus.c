/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:12:53 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/08/22 18:13:27 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void check(t_heap *h);
static void	do_move(t_heap *h, char *instruction);

int	main(int ac, char **av)
{
	char	**nums;
	t_heap	h;

	nums = NULL;
	h.nums = NULL;
	h.s = NULL;
	if (ac < 2)
		return (55);
	else if (ac == 2)
	{
		h.nums = ft_split(av[1], ' ');
		if (!h.nums || !*h.nums)
			close_ps(&h, 1);
		check_nums(&h, h.nums);
		h.a = init_stack(&h, h.nums);
	}
	else
	{
		nums = &av[1];
		check_nums(&h, nums);
		h.a = init_stack(&h, nums);
	}
	h.b = NULL;
	check(&h);
	close_ps(&h, 0);
}

static void check(t_heap *h)
{
	char *in;

	in = get_next_line(0);
	while (in)
	{
		do_move(h, in);
		free(in);
		in = get_next_line(0);
	}
	if (is_sorted(h->a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

static void	do_move(t_heap *h, char *instruction)
{
	if (ft_strncmp(instruction, "ra\n", 3) == 0)
		ra(h, 0);
	else if (ft_strncmp(instruction, "pa\n", 3) == 0)
		pa(h, 0);
	else if (ft_strncmp(instruction, "sa\n", 3) == 0)
		sa(h, 0);
	else if (ft_strncmp(instruction, "rb\n", 3) == 0)
		rb(h, 0);
	else if (ft_strncmp(instruction, "pb\n", 3) == 0)
		pb(h, 0);
	else if (ft_strncmp(instruction, "sb\n", 3) == 0)
		sb(h, 0);
	else if (ft_strncmp(instruction, "rr\n", 3) == 0)
		rr(h, 0);
	else if (ft_strncmp(instruction, "rrb\n", 4) == 0)
		rrb(h, 0);
	else if (ft_strncmp(instruction, "rra\n", 4) == 0)
		rra(h, 0);
	else if (ft_strncmp(instruction, "rrr\n", 4) == 0)
		rrr(h, 0);
}
