#include "push_swap.h"

static void	init_stack(t_stack **a);

int	main(int ac, char **av)
{
	int		i;
	t_stack *a;
	//t_stack	*b;

	a = NULL;
	//b = NULL;
	if (ac < 2)
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		av = &av[1];
	i = 0;
	while (av[i])
		ft_putstr_fd(av[i++], 1);
	init_stack(&a, av);
	return (0);
}

static void	init_stack(t_stack **a)
{
	(void)a;
	return ;
}
