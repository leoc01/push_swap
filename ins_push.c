#include "push_swap.h"

static t_stack	*remove_s(t_stack **s);
static void	insert_s(t_stack *i, t_stack **s);

void	pa(t_heap *h, int print)
{
	t_stack	*na;

	if (!h->b)
		return;
	na = remove_s(&h->b);
	if (na)
		insert_s(na, &h->a);
	if (print)
		ft_putstr_fd("\npa\n", 1);
}

void	pb(t_heap *h, int print)
{
	t_stack	*nb;

	if (!h->a)
		return;
	nb = remove_s(&h->a);
	if (nb)
		insert_s(nb, &h->b);
	if (print)
		ft_putstr_fd("\npb\n", 1);
}

static t_stack	*remove_s(t_stack **s)
{
	t_stack	*r;

	if (!s || !*s)
		return (NULL);
	r = *s;
	if (*s == (*s)->next)
		*s = NULL;
	else
	{
		(*s)->prev->next = (*s)->next;
		(*s)->next->prev = (*s)->prev;
		*s = (*s)->next;
	}
	return (r);
}

static void	insert_s(t_stack *i, t_stack **s)
{
	if (!i || !s)
		return ;
	if (!*s)
	{
		i->next = i;
		i->prev = i;
	}
	else
	{
		i->next = *s;
		i->prev = (*s)->prev;
		i->prev->next = i;
		i->next->prev = i;
	}
	*s = i;
}
