/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:14:46 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/20 17:06:09 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a)
{
	if (stack_a && *stack_a)
		*stack_a = (*stack_a)->next;
}

void	rb(t_list **stack_b)
{
	if (stack_b && *stack_b)
		*stack_b = (*stack_b)->next;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a)
		*stack_a = (*stack_a)->next;
	if (stack_b && *stack_b)
		*stack_b = (*stack_b)->next;
}
