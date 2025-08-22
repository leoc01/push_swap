/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:41:35 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/08/21 15:48:54 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	push_swap(&h);
	close_ps(&h, 0);
}
