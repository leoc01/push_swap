/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:40:47 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/08/08 17:40:48 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_heap
{
	int		len;
	t_stack	*s;
	t_stack	*a;
	t_stack	*b;
	char	**nums;
}	t_heap;

void	ra(t_heap *h, int print);
void	rra(t_heap *h, int print);
void	sa(t_heap *h, int print);

void	rb(t_heap *h, int print);
void	rrb(t_heap *h, int print);
void	sb(t_heap *h, int print);

void	rr(t_heap *h);
void	rrr(t_heap *h);
void	ss(t_heap *h);

int		pa(t_heap *h, int print);
int		pb(t_heap *h, int print);

int		is_sorted(t_stack *s);
void	sort_three(t_heap *h);
void	push_swap(t_heap *h);
int		a_target(int num, t_stack *s);
int		b_target(int num, t_stack *s);
int		get_max(t_stack *s);
int		get_min(t_stack *s);


void	debug_interactive(t_heap *h);

#endif
