/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 11:52:47 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/21 14:23:10 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_null(t_list	***stack_to, t_list **top_to, t_list **tmp)
{
	*top_to = *tmp;
	(*top_to)->next = *top_to;
	(*top_to)->prev = *top_to;
	**stack_to = *top_to;
}

void	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;
	t_list	*top_to;
	t_list	*top_from;

	top_to = *stack_to;
	top_from = *stack_from;
	tmp = top_from;
	top_from->prev->next = top_from->next;
	top_from->next->prev = top_from->prev;
	top_from = top_from->next;
	*stack_from = top_from;
	if (!top_to)
		push_to_null(&stack_to, &top_to, &tmp);
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

void	pa(t_stack *stacks)
{
	int	size;

	if (!stacks->stack_a)
		return ;
	size = ft_lstsize(stacks->stack_b);
	if (size == 0)
		return ;
	push(&(stacks->stack_a), &(stacks->stack_b));
}

void	pb(t_stack *stacks)
{
	int	size;

	if (!stacks->stack_a)
		return ;
	size = ft_lstsize(stacks->stack_a);
	if (size == 0)
		return ;
	push(&(stacks->stack_b), &(stacks->stack_a));
}
