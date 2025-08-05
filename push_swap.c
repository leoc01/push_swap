#include "push_swap.h"

static t_stack	*init_stack(t_heap *h, char **nums);
static t_stack	*stack_new(t_heap *h, int num);
static t_stack	*stack_add(t_heap *h, t_stack *a, int num);
static void		print_stack(t_heap *h, t_stack *a);
static void		close_ps(t_heap *h, int code);

int	main(int ac, char **av)
{
	char	**nums;
	t_heap	*h;

	h = NULL;
	if (ac < 2)
		return (1);
	h = ft_calloc(1, sizeof(t_heap));
	if (ac == 2)
		h->nums = ft_split(av[1], ' ');
	else
		nums = &av[1];
	h->a = init_stack(h, nums);
//	write(1, "0", 1);
	print_stack(h, h->a);
	close_ps(h, 0);
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

static void		print_stack(t_heap *h, t_stack *a)
{
	if (!a)
		close_ps(h, 1);
	ft_putnbr_fd(a->num, 1);
	ft_putstr_fd("\n", 1);
	a = a->next;
	while (a->num > a->prev->num)
	{
		ft_putnbr_fd(a->num, 1);
		ft_putstr_fd("\n", 1);
		a = a->next;
	}
}

static void	stack_free(t_stack **stack)
{
	t_stack *aux;
	t_stack *first;

	first = *stack;
	aux = first->next->next;
	while (aux != first)
	{
		free(aux->prev);
		aux = aux->next;
	}
	free(aux->prev);
	free(aux);
}

static void	close_ps(t_heap *h, int code)
{
	if (h)
	{
		if (h->nums)
		{
			while (*h->nums)
			{
				free(*h->nums);
				h->nums++;
			}
			free(h->nums);
		}
		if (h->a)
		{
			stack_free(&h->a);
		}
		free(h);
	}
	if (code)
		ft_putstr_fd("Error\n", 2);
	exit(code);
}
