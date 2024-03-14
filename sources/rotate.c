/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:14:46 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/13 17:03:57 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_list **stack_a)
{
	*stack_a = (*stack_a)->next;
	write(1, "ra\n", 3);
}

void    rb(t_list **stack_b)
{
	*stack_b = (*stack_b)->next;
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	*stack_a = (*stack_a)->next;
	*stack_b = (*stack_b)->next;
	write(1, "rr\n", 3);
}