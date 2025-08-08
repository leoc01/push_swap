/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_g.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:46:54 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/08/08 17:46:54 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_heap *h)
{
	ra(h, 0);
	rb(h, 0);
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_heap *h)
{
	rra(h, 0);
	rrb(h, 0);
	ft_putstr_fd("rrr\n", 1);
}

void	ss(t_heap *h)
{
	sa(h, 0);
	sb(h, 0);
	ft_putstr_fd("ss\n", 1);
}
