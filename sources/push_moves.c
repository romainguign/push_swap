/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 11:52:47 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/10 15:07:34 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stacks)
{

}

void	pb(t_stack *stacks)
{
    stacks->stack_b = stacks->stack_a;
    stacks->stack_a->next->prev = stacks->stack_a->prev;
    stacks->stack_a->prev->next = stacks->stack_a->next;
    stacks->stack_a = stacks->stack_a->next;
    stacks->top_a = stacks->stack_a;
    stacks->stack_b->next = NULL;
    stacks->stack_b->prev = NULL;
    // stacks->top_b = stacks->stack_b;
    printf ("stack b : %p  ", stacks->stack_b);
	write(1, "pb\n", 3);
}
