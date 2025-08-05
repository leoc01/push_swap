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
	t_stack	*a;
	t_stack	*b;
	char	**nums;
}	t_heap;

#endif
