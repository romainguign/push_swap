/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:38:25 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/25 16:35:24 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sort(t_stack *stacks)
{
	t_list	*min;
	t_list	*tmp;
	int		count;

	min = find_min(stacks->stack_a);
	tmp = stacks->stack_a;
	count = 0;
	while (tmp != min)
	{
		tmp = tmp->next;
		count++;
	}
	if (count > ft_lstsize(stacks->stack_a) / 2)
	{
		while (stacks->stack_a != min)
			rra(&(stacks)->stack_a);
	}
	else
	{
		while (stacks->stack_a != min)
			ra(&(stacks)->stack_a);
	}
}

void	n_elements_case(t_stack *stacks)
{
	int	size_b;

	sort_stack_b(stacks);
	three_elements_case(stacks, stacks->stack_a);
	size_b = ft_lstsize(stacks->stack_b);
	while (size_b > 0)
	{
		sort_stack_a(stacks);
		size_b--;
	}
	stacks->stack_b = NULL;
	final_sort(stacks);
}

void	three_elements_case(t_stack *stacks, t_list *stack_a)
{
	if (is_sorted(stacks->stack_a) == 1)
		return ;
	if (*stack_a->content > *stack_a->next->content
		&& *stack_a->content > *stack_a->prev->content)
		biggest_first(stacks);
	else if (*stack_a->content < *stack_a->next->content
		&& *stack_a->next->content > *stack_a->prev->content)
		biggest_second(stacks);
	else
		sa(stacks->stack_a);
}

void	push_swap(t_stack *stacks)
{
	if (ft_lstsize(stacks->stack_a) == 2)
		sa(stacks->stack_a);
	else if (ft_lstsize(stacks->stack_a) == 3)
		three_elements_case(stacks, stacks->stack_a);
	else if (ft_lstsize(stacks->stack_a) == 5)
	{
		pb(stacks);
		pb(stacks);
		three_elements_case(stacks, stacks->stack_a);
		sort_stack_a(stacks);
		sort_stack_a(stacks);
		final_sort(stacks);
	}
	else
		n_elements_case(stacks);
}

int	main(int argc, char **argv)
{
	t_stack	*stacks;

	if (argc < 2)
		return (1);
	stacks = ft_calloc(1, sizeof(t_stack));
	if	(!stacks)
		return (1);
	if (!parsing(&stacks, argv))
	{
		free(stacks);
		return (0);
	}
	if (is_sorted(stacks->stack_a) == 1 || find_quartile(stacks, 0) == 0)
	{
		ft_lstclear(&stacks->stack_a, free);
		free(stacks);
		return (0);
	}
	push_swap(stacks);
	ft_lstclear(&stacks->stack_a, free);
	free(stacks);
	return (0);
}
