#include "push_swap.h"

void	ra(t_heap *h, int print)
{
	if (!h->a)
		return ;
	h->a = h->a->prev;
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rra(t_heap *h, int print)
{
	if (!h->a)
		return ;
	h->a = h->a->next;
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	sa(t_heap *h, int print)
{
	int	aux;

	if (!h->a || h->a == h->a->next)
		return ;
	aux = h->a->num;
	h->a->num = h->a->next->num;
	h->a->next->num = aux;
	if (print)
		ft_putstr_fd("\nsa\n", 1);
}
