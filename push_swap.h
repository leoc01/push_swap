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
	int		a_len;
	int		b_len;
	int		next_instruction;
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

void	pa(t_heap *h, int print);
void	pb(t_heap *h, int print);

int		is_sorted(t_stack *s);
void	sort_three(t_heap *h);
void	push_swap(t_heap *h);

int		get_target(t_heap *h, int num, t_stack *d);
int		a_target(int num, t_stack *s, int l, int h);
int		b_target(int num, t_stack *s, int l, int h);
int		get_max(t_stack *s);
int		get_min(t_stack *s);

void	find_cheaper(t_heap *h, t_stack *s, t_stack *d);
int		get_cost(t_heap *h, int num, t_stack *s, t_stack *d);
int		get_position(int n, t_stack *s);

int	max(int n1, int n2);
int	min(int n1, int n2);

void	debug_interactive(t_heap *h);

#endif
