/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_coast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:42:37 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/19 15:44:25 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int test_rrr(t_list *stack_from, t_list *stack_to, int count, int element_nbr)
{
    int best_count;
    int size_from;
    int size_to;
    
    size_from = ft_lstsize(stack_from);
    size_to = ft_lstsize(stack_from);
    element_nbr = size_from - element_nbr + 1;
    count = size_to - count + 1;
    if (element_nbr >= count)
        best_count = element_nbr;
    else
        best_count = count;
    return (best_count + 1);
}

int test_rr(int count, int element_nbr)
{
    int best_count;
    
    if (element_nbr >= count)
        best_count = element_nbr;
    else
        best_count = count;
    return (best_count + 1);
}

int	opti_coast(t_list *stack_from, t_list *stack_to, int count, int element_nbr)
{
    int best_count;
    int	size_from;
	int	size_to;

	size_from = ft_lstsize(stack_from);
	size_to = ft_lstsize(stack_to);
    
    if (stack_from->type == 1)
        best_count = size_from - element_nbr + 1 + count;
    else
        best_count = size_to - count + 1 + element_nbr;
    // printf ("best : %d\n", best_count);
    // if (test_rrr(stack_from, stack_to, count, element_nbr) < best_count)
    // {
    //     best_count = test_rrr(stack_from, stack_to, count, element_nbr);
    //     stack_from->target->type = 1;
    //     stack_from->type = 1;
    // }
    // if (test_rr(count, element_nbr) < best_count)
    // {
    //     best_count = test_rr(count, element_nbr);
    //     stack_from->target->type = 2;
    //     stack_from->type = 2;
    // }
    //     // printf ("best : %d\n\n", best_count);

	return (best_count);
}

int		count_nbr(t_list *stack_from, t_list *stack_to, int count, int element_nbr)
{
	int	size_from;
	int	size_to;

	size_from = ft_lstsize(stack_from);
	size_to = ft_lstsize(stack_to);
	if (size_to == 2)
	{
		if (stack_from->type == 1)
			element_nbr = size_from - element_nbr;
		count = element_nbr + count + 1;
	}
	else if (stack_from->type == 1 && stack_from->target->type == 1)
	{
		if (count < element_nbr)
			count = size_to - count + 1;
		else
			count = size_from - element_nbr + 1;
	}
	else if (stack_from->type == 2 && stack_from->target->type == 2)
	{
		if (count < element_nbr)
			count = (element_nbr + 1);
		else
			count = count + 1;
	}
	else
		count = opti_coast(stack_from, stack_to, count, element_nbr);
	return (count);
}
