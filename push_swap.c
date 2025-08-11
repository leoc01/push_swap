/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:41:35 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/08/08 17:41:39 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*init_stack(t_heap *h, char **nums);
static void		link_stack(t_stack *s, int l);
static void		close_ps(t_heap *h, int code);

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
	push_swap(&h);
	debug_interactive(&h);
	close_ps(&h, 0);
}

static t_stack	*init_stack(t_heap *h, char **nums)
{
	t_stack	*s;
	int		c;
	int		l;

	if (!nums)
		close_ps(h, 1);
	l = 0;
	while (nums[l])
		l++;
	h->len = l;
	s = ft_calloc(l, sizeof(t_stack));
	if (!s)
		close_ps(h, 1);
	h->s = s;
	c = 0;
	while (c < l)
	{
		s[c].num = ft_atoi(nums[c]);
		c++;
	}
	link_stack(s, l);
	return (s);
}

static void	link_stack(t_stack *s, int l)
{
	int	c;

	s[0].next = &s[1];
	s[0].prev = &s[l - 1];
	c = 1;
	while (c < l - 1)
	{
		s[c].next = &s[c + 1];
		s[c].prev = &s[c - 1];
		c++;
	}
	s[l - 1].next = &s[0];
	s[l - 1].prev = &s[l - 2];
}

static void	close_ps(t_heap *h, int code)
{
	char	**nums;

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
	if (h->s)
		free(h->s);
	if (code)
		ft_putstr_fd("Error\n", 2);
	exit(code);
}
