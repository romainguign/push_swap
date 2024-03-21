/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:28:02 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/20 17:06:04 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_list **stack_a)
{
	if (stack_a && *stack_a)
		*stack_a = (*stack_a)->prev;
}

void	rrb(t_list **stack_b)
{
	if (stack_b && *stack_b)
		*stack_b = (*stack_b)->prev;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (stack_a && *stack_a)
		*stack_a = (*stack_a)->prev;
	if (stack_b && *stack_b)
		*stack_b = (*stack_b)->prev;
}
