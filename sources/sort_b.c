/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:08:27 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/14 20:32:27 by roguigna         ###   ########.fr       */
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

// int		calc_count_b(t_list *stack_from, t_list *stack_to, int size_from, int element_nbr)
// {
// 	int	count;
// 	int	size_to;
// 	t_list	*top_to;

// 	top_to = stack_to;
// 	size_to = ft_lstsize(stack_to);
// 	count = find_target_b(stack_from, stack_to, top_to);
// 	printf("current count : %d\n", count);
// 	if (element_nbr + 1 > (size_from / 2) && (count > size_to / 2))
// 	{
// 		stack_from->type = 1;
// 		count = count_nbr(stack_from, stack_to, 1, size_to - count, size_from - element_nbr);
// 		printf("caca count : %d element nbr %d\n", count, element_nbr);
// 	}
// 	else if (element_nbr + 1 <= size_from / 2 && count + 1 <= size_to / 2)
// 	{
// 		stack_from->type = 2;
// 		count = count_nbr(stack_from, stack_to, 2,count, element_nbr);
// 		printf("pipi count : %d element nbr %d\n", count, element_nbr);
// 	}
// 	else
// 	{
// 		stack_from->type = 3;
// 		count = count_nbr(stack_from, stack_to, 3, count, element_nbr);
// 		printf("testicules count : %d element nbr %d\n", count, element_nbr);
// 	}
// 	return (count);
// }

int		calc_count_b(t_list *stack_from, t_list *stack_to, int size_from, int element_nbr)
{
	int	count;
	int	size_to;
	int	mediane_from;
	int	mediane_to;
	t_list	*top_to;

	mediane_from = calc_mediane(stack_from);
	mediane_to = calc_mediane(stack_to);
	top_to = stack_to;
	size_to = ft_lstsize(stack_to);
	count = find_target_b(stack_from, stack_to, top_to);
	if (element_nbr + 1 > mediane_from || (mediane_from % 2 == 0 && element_nbr == mediane_from + 1))
		stack_from->type = 1;
	if (count + 1 > mediane_to || (mediane_to % 2 == 0 && element_nbr == mediane_to + 1))
		stack_from->target->type = 1;
	if (element_nbr + 1 < mediane_from || (mediane_from % 2 == 0 && element_nbr == mediane_from))
		stack_from->type = 2;
	if (count + 1 < mediane_to || (mediane_to % 2 == 0 && element_nbr == mediane_to))
		stack_from->target->type = 2;
	if (element_nbr + 1 == mediane_from && mediane_from % 2 == 1)
		stack_from->type = 3;
	if (count + 1 == mediane_to && mediane_from % 2 == 1)
		stack_from->target->type = 3;
	if (size_to == 2)
		stack_from->target->type = 3;
	if (size_from == 2)
		stack_from->type = 3;
	count = count_nbr(stack_from, stack_to, count, element_nbr);
	return (count);
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
		// printf("\nCHIASSE NUMBER : %lld\n", *stack_from->content);
		count = calc_count_b(stack_from, stack_to, size_from, element_nbr);
		// printf("CHEAPEST COUNT : %d\n", count);
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