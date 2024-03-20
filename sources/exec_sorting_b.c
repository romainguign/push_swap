/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_sorting_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:10:57 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/20 12:57:18 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void    rrr_sort_b(t_stack *stacks, t_list *cheapest_element)
// {
// 	t_list	*top_to;
// 	t_list	*top_from;

// 	top_to = stacks->stack_b;
// 	top_from = stacks->stack_a;
	
// 	while (stacks->stack_a && stacks->stack_b && cheapest_element != top_from && cheapest_element->target != top_to)
// 	{
// 		rrr(&(stacks->stack_a), &(stacks->stack_b));
// 		top_from = stacks->stack_a;
// 		top_to = stacks->stack_b;
// 	}
// 	while (cheapest_element != top_from)
// 	{
// 		rra(&(stacks->stack_a));
// 		top_from = stacks->stack_a;
// 	}
// 	while (cheapest_element->target != top_to)
// 	{
// 		rrb(&(stacks->stack_b));
// 		top_to = stacks->stack_b;
// 	}
// }

// void    rr_sort_b(t_stack *stacks, t_list *cheapest_element)
// {
// 	t_list	*top_to;
// 	t_list	*top_from;

// 	top_to = stacks->stack_b;
// 	top_from = stacks->stack_a;
	
// 	while (stacks->stack_a && stacks->stack_b && cheapest_element != top_from && cheapest_element->target != top_to)
// 	{
// 		rr(&(stacks->stack_a), &(stacks->stack_b));
// 		top_from = stacks->stack_a;
// 		top_to = stacks->stack_b;
// 	}
// 	while (cheapest_element != top_from)
// 	{
// 		ra(&(stacks->stack_a));
// 		top_from = stacks->stack_a;
// 	}
// 	while (cheapest_element->target != top_to)
// 	{
// 		rb(&(stacks->stack_b));
// 		top_to = stacks->stack_b;
// 	}
// }

// void	basic_sort_b(t_stack *stacks, t_list *cheapest_element)
// {
// 	t_list	*top_to;
// 	t_list	*top_from;

// 	top_to = stacks->stack_b;
// 	top_from = stacks->stack_a;

// 	if (cheapest_element->type == 1)
// 	{
// 		while (top_to != cheapest_element->target)
// 		{
// 			rb(&(stacks->stack_b));
// 			top_to = stacks->stack_b;
// 		}
// 		while (top_from != cheapest_element)
// 		{
// 			rra(&(stacks->stack_a));
// 			top_from = stacks->stack_a;
// 		}
// 	}
// 	else
// 	{
// 		while (top_to != cheapest_element->target)
// 		{
// 			rrb(&(stacks->stack_b));
// 			top_to = stacks->stack_b;
// 		}
// 		while (top_from != cheapest_element)
// 		{
// 			ra(&(stacks->stack_a));
// 			top_from = stacks->stack_a;
// 		}
// 	}
// }

// void	sort_and_push_b(t_stack *stacks, t_list *cheapest_element)
// {
// 	// printf ("type : %d target type : %d\n", cheapest_element->type, cheapest_element->target->type);
// 	if (cheapest_element->type == 1 && cheapest_element->target->type == 1)
// 		rrr_sort_b(stacks, cheapest_element);
// 	if (cheapest_element->type == 2 && cheapest_element->target->type == 2)
// 		rr_sort_b(stacks, cheapest_element);
// 	else
// 		basic_sort_b(stacks, cheapest_element);
// 	pb(stacks);
// }