#include "push_swap.h"

static t_stack	*init_stack(t_heap *h, char **nums);
static t_stack	*stack_new(t_heap *h, int num);
static t_stack	*stack_add(t_heap *h, t_stack *a, int num);
static void		print_stack(t_stack *s);
static void		close_ps(t_heap *h, int code);

void	ra(t_heap *h)
{
	h->a = h->a->prev;
	ft_putstr_fd("ra\n", 1);
}

void	rra(t_heap *h)
{
	h->a = h->a->next;
	ft_putstr_fd("rra\n", 1);
}

t_stack	*remove(t_stack **s)
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

void	insert(t_stack *i, t_stack **s)
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

void	pb(t_heap *h)
{
	t_stack	*nb;

	if (!h->a)
		return;
	nb = remove(&h->a);
	if (nb)
		insert(nb, &h->b);
	ft_putstr_fd("\npb\n", 1);
}

int	main(int ac, char **av)
{
	char	**nums;
	t_heap	h;

	nums = NULL;
	h.nums = NULL;
	if (ac < 2)
		return (55);
	else if (ac == 2)
	{
		h.nums = ft_split(av[1], ' ');
		h.a = init_stack(&h, h.nums);
	}
	else
	{
		nums = &av[1];
		h.a = init_stack(&h, nums);
	}
	h.b = NULL;
	ft_putstr_fd("Stack A:\n", 1);
	print_stack(h.a);
	pb(&h);
	pb(&h);
	pb(&h);
	//ra(&h);
	ft_putstr_fd("\nStack A:\n", 1);
	print_stack(h.a);
	ft_putstr_fd("\nStack B:\n", 1);
	print_stack(h.b);
	close_ps(&h, 0);
}

static t_stack	*init_stack(t_heap *h, char **nums)
{
	t_stack	*first;
	t_stack	*last;

	if (!nums)
		close_ps(h, 1);
	first = stack_new(h, ft_atoi(*nums));
	nums++;
	while (*nums)
	{
		last = stack_add(h, first, ft_atoi(*nums));
		nums++;
	}
	first->prev = last;
	last->next = first;
	return (first);
}

static t_stack	*stack_new(t_heap *h, int num)
{
	t_stack	*new;

	new = ft_calloc(1, sizeof(t_stack));
	if (!new)
		close_ps(h, 1);
	new->num = num;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static t_stack	*stack_add(t_heap *h, t_stack *first, int num)
{
	t_stack	*last;
	t_stack *current;

	if (!first)
		close_ps(h, 1);
	current = first;
	last = ft_calloc(1, sizeof(t_stack));
	if (!last)
		close_ps(h, 1);
	last->num = num;
	while (current->next)
		current = current->next;
	last->prev = current;
	current->next = last;
	return (last);
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

static void	stack_free(t_stack **stack)
{
	t_stack *aux;
	t_stack *current;

	current = *stack;
	current->prev->next = NULL;
	while (current)
	{
		aux = current->next;
		current->next = NULL;
		free(current);
		current = aux;
	}
}

static void	close_ps(t_heap *h, int code)
{
	char **nums;

	nums = h->nums;
	if (nums)
	{
		while (*nums)
		{
			free(*nums);
			nums++;
		}
		free(h->nums);
	}
	if (h->a)
		stack_free(&h->a);
	if (h->b)
		stack_free(&h->b);
	if (code)
		ft_putstr_fd("Error\n", 2);
	exit(code);
}
