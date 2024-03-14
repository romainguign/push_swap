/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_sorting_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:10:57 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/14 13:51:46 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rrr_sort_b(t_stack *stacks, t_list *cheapest_element)
{
	t_list	*top_to;
	t_list	*top_from;

	top_to = stacks->stack_b;
	top_from = stacks->stack_a;
	
	while (stacks->stack_a && stacks->stack_b && cheapest_element != top_from && cheapest_element->target != top_to)
	{
		rrr(&(stacks->stack_a), &(stacks->stack_b));
		top_from = stacks->stack_a;
		top_to = stacks->stack_b;
	}
	while (cheapest_element != top_from)
	{
		rra(&(stacks->stack_a));
		top_from = stacks->stack_a;
	}
	while (cheapest_element->target != top_to)
	{
		rrb(&(stacks->stack_b));
		top_to = stacks->stack_b;
	}
}

void    rr_sort_b(t_stack *stacks, t_list *cheapest_element)
{
	t_list	*top_to;
	t_list	*top_from;

	top_to = stacks->stack_b;
	top_from = stacks->stack_a;
	
	while (stacks->stack_a && stacks->stack_b && cheapest_element != top_from && cheapest_element->target != top_to)
	{
		rr(&(stacks->stack_a), &(stacks->stack_b));
		top_from = stacks->stack_a;
		top_to = stacks->stack_b;
	}
	while (cheapest_element != top_from)
	{
		ra(&(stacks->stack_a));
		top_from = stacks->stack_a;
	}
	while (cheapest_element->target != top_to)
	{
		rb(&(stacks->stack_b));
		top_to = stacks->stack_b;
	}
}

void	basic_sort_b(t_stack *stacks, t_list *cheapest_element)
{
	t_list	*top_to;
	t_list	*top_from;
	int		cheapest_type;
	int		target_type;
	
	top_to = stacks->stack_b;
	top_from = stacks->stack_a;
	cheapest_type = 0;
    target_type = 0;
    if (count_pos(top_from, cheapest_element) > ft_lstsize(top_from) / 2)
        cheapest_type = 1;
    if (count_pos(top_to, cheapest_element->target) > ft_lstsize(top_from) / 2)
        target_type = 1;
	while (stacks->stack_a && cheapest_element != top_from)
	{
		if (cheapest_element == 0)
			ra(&(stacks->stack_a));
		else
			rra(&(stacks->stack_a));
		top_from = stacks->stack_a;
	}
	while (stacks->stack_b && cheapest_element->target != top_to)
	{
		if (target_type == 0)
			rb(&(stacks->stack_b));
		else
			rrb(&(stacks->stack_b));
		top_to = stacks->stack_b;
	}
}

void	sort_and_push_b(t_stack *stacks, t_list *cheapest_element)
{
	
	if (cheapest_element->type == 1)
		rrr_sort_b(stacks, cheapest_element);
	if (cheapest_element->type == 2)
		rr_sort_b(stacks, cheapest_element);
	if (cheapest_element->type == 3)
		basic_sort_b(stacks, cheapest_element);
	pb(stacks);;
}