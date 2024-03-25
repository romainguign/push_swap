/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:59:27 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/25 16:32:10 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list	*stack)
{
	t_list			*min;
	t_list			*top;

	top = stack;
	min = stack;
	stack = stack->next;
	while (stack->next != top->next)
	{
		if (*stack->content < *min->content)
			min = stack;
		stack = stack->next;
	}
	return (min);
}
