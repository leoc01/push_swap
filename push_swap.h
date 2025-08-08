#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct	s_stack
{
	int				num;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct	s_heap
{
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

void debug_interactive(t_heap *h);

#endif
