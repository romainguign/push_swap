/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:08:27 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/14 18:42:34 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list		*find_max(t_list	*stack)
{
	long long int content;
	t_list			*max;
	t_list			*top;
	
	top = stack;
	max = stack;
	stack = stack->next;
	while (stack->next != top->next)
	{
		if (*stack->content > *max->content)
			max = stack;
		stack = stack->next;
	}
	if (*stack->content > *max->content)
			max = stack;
	return (max);
}

int		find_target_b(t_list *stack_from, t_list *stack_to, t_list *top_to)
{
	int	count;
	int	near_content;
	int	target_content;
	t_list	*max;

	count = 0;
	target_content = 0;
	max = find_max(stack_to);
	while (stack_to->next != top_to)
	{
		if (*stack_from->content > *stack_to->content && *stack_to->prev->content > *stack_from->content)
			break ;
		stack_to = stack_to->next;
	}
	if (*stack_from->content > *max->content || (*stack_to->content > *stack_from->content))
		stack_from->target = max;
	else
		stack_from->target = stack_to;
	while (stack_from->target != top_to)
	{
		count++;
		top_to = top_to->next;
	}
	return (count);
}

int	calc_count_b(t_list *stack_from, t_list *stack_to, int size_from, int element_nbr)
{
	int	target_nb;
	int	size_to;
	t_list	*top_to;
	int	best_count;

	top_to = stack_to;
	size_to = ft_lstsize(stack_to);
	target_nb = find_target_b(stack_from, stack_to, top_to);
	best_count = element_nbr + target_nb + 1;
	stack_from->type = 3;
	if (element_nbr <= target_nb)
	{
		if (best_count > size_from - element_nbr)
		{
			best_count = size_from - element_nbr;
			stack_from->type = 1;
		}
		if (best_count > target_nb)		
		{
			best_count = target_nb;
			stack_from->type = 2;
		}
	}
	else
	{
		if (best_count > size_to - target_nb)
		{
			best_count = size_to - target_nb;
			stack_from->type = 1;
		}
		if (best_count > size_to - target_nb)
		{
			best_count = element_nbr;
			stack_from->type = 2;
		}
	}
	return (best_count + 1);
}

t_list	*find_cheapest_count_b(t_list *stack_from, t_list *stack_to, int size_from)
{
	t_list	*top_from;
	t_list	*cheapest_count;
	int		current_cheapest_count;
	int		count;
	int		element_nbr;

	top_from = stack_from;
	count = 0;
	element_nbr = 0;
	current_cheapest_count = 0;
	cheapest_count = stack_from;
	while (element_nbr < size_from)
	{
		count = calc_count_b(stack_from, stack_to, size_from, element_nbr);
		if (!current_cheapest_count || count < current_cheapest_count)
		{
			current_cheapest_count = count;
			cheapest_count = stack_from;
		}
		element_nbr++;
		stack_from = stack_from->next;
	}
	return (cheapest_count);
}

void	sort_stack_b(t_stack *stacks)
{
	int		size_a;
	int		size_b;
	int		mediane;
	t_list	*cheapest_element;

	size_a = ft_lstsize(stacks->stack_a);
	size_b = ft_lstsize(stacks->stack_b);
	// printf ("stack a : %lld, stack b : %lld\n", *stacks->stack_a->content, *stacks->stack_b->content);
	cheapest_element = find_cheapest_count_b(stacks->stack_a, stacks->stack_b, size_a);
	// printf("cheapest element : %lld, target : %lld\n", *cheapest_element->content, *cheapest_element->target->content);
	sort_and_push_b(stacks, cheapest_element);
}