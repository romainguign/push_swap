/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_element_cases.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:39:04 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/20 14:41:55 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	biggest_first(t_stack *stacks)
{
	if (*stacks->stack_a->next->content > *stacks->stack_a->prev->content)
	{
		sa(stacks->stack_a);
		rra(&(stacks->stack_a));
		return ;
	}
	else
	{
		ra(&(stacks->stack_a));
		return ;
	}
}

void	biggest_second(t_stack *stacks)
{
	if (*stacks->stack_a->content > *stacks->stack_a->prev->content)
	{
		rra(&(stacks->stack_a));
		return ;
	}
	else
	{
		sa(stacks->stack_a);
		ra(&(stacks->stack_a));
	}
}
