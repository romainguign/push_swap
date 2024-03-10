/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:23:32 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/10 15:00:13 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *stack_a, t_list *top_a)
{
	void	*tmp;

	if (ft_lstsize(stack_a, top_a) < 2)
		return ;
	tmp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_list *stack_b, t_list *top_b)
{
	void	*tmp;

	if (ft_lstsize(stack_b, top_b) < 2)
		return ;
	tmp = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = tmp;
	write(1, "sa\n", 3);
}

void	ss(t_stack *stacks)
{
	sa(stacks->stack_a, stacks->top_a);
	sb(stacks->stack_b, stacks->top_b);
}