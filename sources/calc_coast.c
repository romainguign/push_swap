/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_coast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:42:37 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/14 20:30:18 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	opti_coast(t_list *stack_from, t_list *stack_to, int count, int element_nbr)
{
    int best_count;
    int size_from;
    int size_to;
    int mediane_from;
    int mediane_to;

    best_count = count + 1;
    size_from = ft_lstsize(stack_from);
    size_to = ft_lstsize(stack_to);
    mediane_from = calc_mediane(stack_from);
    mediane_to = calc_mediane(stack_to);
    if (element_nbr > count)
        best_count = element_nbr + 1;
    stack_from->type = 2;
    if (element_nbr <= count && best_count > size_from - element_nbr + 1)
    {
            best_count = size_from - element_nbr + 1;
            stack_from->type = 1;
    }
    else if (element_nbr >= count && best_count > size_to - count + 1)
    {
            best_count = size_to - count + 1;
            stack_from->type = 1;
    }
    else if (element_nbr <= mediane_from && count >= mediane_to && best_count > element_nbr + size_to - count + 1)
    {
        best_count = element_nbr + size_to - count + 1;
        stack_from->type = 3;
    }
    else if (element_nbr >= mediane_from && count <= mediane_to && best_count > count + size_from - element_nbr + 1)
    {
        best_count = count + size_from - element_nbr + 1;
        stack_from->type = 3;
    }
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