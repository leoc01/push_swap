/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:46:43 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/08/08 17:46:45 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_heap *h, int print)
{
	if (!h->b)
		return ;
	h->b = h->b->next;
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rrb(t_heap *h, int print)
{
	if (!h->b)
		return ;
	h->b = h->b->prev;
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	sb(t_heap *h, int print)
{
	int	aux;

	if (!h->b || h->b == h->b->next)
		return ;
	aux = h->b->num;
	h->b->num = h->b->next->num;
	h->b->next->num = aux;
	if (print)
		ft_putstr_fd("sb\n", 1);
}
