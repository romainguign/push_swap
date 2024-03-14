/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 11:52:47 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/14 13:31:15 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;
	t_list	*top_to;
	t_list	*top_from;
	int		size;

	size = ft_lstsize(*stack_from);
	if (size == 0)
		return ;
	top_to = *stack_to;
	top_from = *stack_from;
	tmp = top_from;
	if (size == 1)
	{
		tmp->next = top_to;
		tmp->prev = top_to->prev;
		top_to->prev = tmp;
		tmp->prev->next = tmp;
		*stack_to = tmp;
		*stack_from = NULL;
	}
	
	top_from->prev->next = top_from->next;
	top_from->next->prev = top_from->prev;
	top_from = top_from->next;
	*stack_from = top_from;
	if (!top_to)
	{
		top_to = tmp;
		top_to->next = top_to;
        top_to->prev = top_to;
		*stack_to = top_to;
	}
	else
	{
		tmp->next = top_to;
		tmp->prev = top_to->prev;
		top_to->prev = tmp;
		tmp->prev->next = tmp;
		*stack_to = tmp;
	}
	return ;
}

void    pa(t_stack *stacks)
{
    push(&(stacks->stack_a), &(stacks->stack_b));
    write(1, "pa\n", 3); 
}

void    pb(t_stack *stacks)
{
    push(&(stacks->stack_b), &(stacks->stack_a));
    write(1, "pb\n", 3);
}
