/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_sorting_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:20:01 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/20 13:42:16 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr_sort_a(t_stack *stacks, t_list *cheapest_element)
{
	t_list	*top_to;
	t_list	*top_from;

	top_to = stacks->stack_a;
	top_from = stacks->stack_b;
	while (stacks->stack_a && stacks->stack_b && cheapest_element
		!= top_from && cheapest_element->target != top_to)
	{
		rrr(&(stacks->stack_a), &(stacks->stack_b));
		top_from = stacks->stack_b;
		top_to = stacks->stack_a;
	}
	while (stacks->stack_b && cheapest_element != top_from)
	{
		rrb(&(stacks->stack_b));
		top_from = stacks->stack_b;
	}
	while (stacks->stack_a && cheapest_element->target != top_to)
	{
		rra(&(stacks->stack_a));
		top_to = stacks->stack_a;
	}
}

void	rr_sort_a(t_stack *stacks, t_list *cheapest_element)
{
	t_list	*top_to;
	t_list	*top_from;

	top_to = stacks->stack_a;
	top_from = stacks->stack_b;
	while (stacks->stack_a && stacks->stack_b && cheapest_element != top_from
		&& cheapest_element->target != top_to)
	{
		rr(&(stacks->stack_a), &(stacks->stack_b));
		top_from = stacks->stack_b;
		top_to = stacks->stack_a;
	}
	while (cheapest_element != top_from)
	{
		rb(&(stacks->stack_b));
		top_from = stacks->stack_b;
	}
	while (cheapest_element->target != top_to)
	{
		ra(&(stacks->stack_a));
		top_to = stacks->stack_a;
	}
}

void	rrb_and_ra(t_stack *stacks, t_list *cheapest_element)
{
	t_list	*top_to;
	t_list	*top_from;

	top_to = stacks->stack_a;
	top_from = stacks->stack_b;
	while (top_to != cheapest_element->target)
	{
		ra(&(stacks->stack_a));
		top_to = stacks->stack_a;
	}
	while (top_from != cheapest_element)
	{
		rrb(&(stacks->stack_b));
		top_from = stacks->stack_b;
	}
}

void	basic_sort_a(t_stack *stacks, t_list *cheapest_element)
{
	t_list	*top_to;
	t_list	*top_from;

	top_to = stacks->stack_a;
	top_from = stacks->stack_b;
	if (cheapest_element->type == RR)
		rrb_and_ra(stacks, cheapest_element);
	else
	{
		while (top_to != cheapest_element->target)
		{
			rra(&(stacks->stack_a));
			top_to = stacks->stack_a;
		}
		while (top_from != cheapest_element)
		{
			rb(&(stacks->stack_b));
			top_from = stacks->stack_b;
		}
	}
}

void	sort_and_push_a(t_stack *stacks, t_list *cheapest_element)
{
	if (cheapest_element->type == 1 && cheapest_element->target->type == 1)
		rrr_sort_a(stacks, cheapest_element);
	if (cheapest_element->type == 2 && cheapest_element->target->type == 2)
		rr_sort_a(stacks, cheapest_element);
	else
		basic_sort_a(stacks, cheapest_element);
	pa(stacks);
}
