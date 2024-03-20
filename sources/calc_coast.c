/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_coast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:42:37 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/20 13:26:05 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test_rrr(t_list *stack_from, t_list *stack_to, int count, int element_nbr)
{
	int	best_count;
	int	size_from;
	int	size_to;

	size_from = ft_lstsize(stack_from);
	size_to = ft_lstsize(stack_to);
	element_nbr = size_from - element_nbr + 1;
	count = size_to - count + 1;
	if (element_nbr >= count)
		best_count = element_nbr;
	else
		best_count = count;
	return (best_count + 1);
}

int	test_rr(int count, int element_nbr)
{
	int	best_count;

	if (element_nbr >= count)
		best_count = element_nbr;
	else
		best_count = count;
	return (best_count + 1);
}

int	test_basic(t_list *stack_from, t_list *stack_to, int count,
	int element_nbr)
{
	int	size_from;
	int	size_to;
	int	best_count;

	size_from = ft_lstsize(stack_from);
	size_to = ft_lstsize(stack_to);
	if (size_from - element_nbr + count < size_to - count + element_nbr)
	{
		stack_from->target->type = R;
		stack_from->type = RR;
		best_count = size_from - element_nbr + 1 + count;
	}
	else
	{
		stack_from->target->type = RR;
		stack_from->type = R;
		best_count = size_to - count + 1 + element_nbr;
	}
	return (best_count);
}

int	better_coast(t_list *stack_from, t_list *stack_to, int count,
	int element_nbr)
{
	int	best_count;

	best_count = test_basic(stack_from, stack_to, count, element_nbr);
	if (test_rrr(stack_from, stack_to, count, element_nbr) < best_count)
	{
		best_count = test_rrr(stack_from, stack_to, count, element_nbr);
		stack_from->target->type = RR;
		stack_from->type = RR;
	}
	if (test_rr(count, element_nbr) < best_count)
	{
		best_count = test_rr(count, element_nbr);
		stack_from->target->type = R;
		stack_from->type = R;
	}
	return (best_count);
}

int	count_nbr(t_list *stack_from, t_list *stack_to, int count, int element_nbr)
{
	int	size_from;
	int	size_to;

	size_from = ft_lstsize(stack_from);
	size_to = ft_lstsize(stack_to);
	count = better_coast(stack_from, stack_to, count, element_nbr);
	return (count);
}
