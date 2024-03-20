/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:23:32 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/20 14:02:01 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *stack_a)
{
	void	*tmp;
	t_list	*top_a;

	top_a = stack_a;
	if (ft_lstsize(stack_a) < 2)
		return ;
	tmp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_list *stack_b)
{
	void	*tmp;
	t_list	*top_b;

	top_b = stack_b;
	if (ft_lstsize(stack_b) < 2)
		return ;
	tmp = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = tmp;
	write(1, "sb\n", 3);
}

void	ss_sa(t_list *stack_a)
{
	void	*tmp;
	t_list	*top_a;

	top_a = stack_a;
	if (ft_lstsize(stack_a) < 2)
		return ;
	tmp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = tmp;
}

void	ss_sb(t_list *stack_b)
{
	void	*tmp;
	t_list	*top_b;

	top_b = stack_b;
	if (ft_lstsize(stack_b) < 2)
		return ;
	tmp = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = tmp;
}

void	ss(t_stack *stacks)
{
	ss_sa(stacks->stack_a);
	ss_sb(stacks->stack_b);
	write(1, "ss\n", 3);
}
