/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:08:27 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/20 13:31:31 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_small_nbr(t_stack *stacks)
{
	int	size_a;
	int	i;

	i = 0;
	size_a = ft_lstsize(stacks->stack_a);
	while (size_a > i)
	{
		if (*stacks->stack_a->content <= stacks->quartile[0])
			pb(stacks);
		else if (*stacks->stack_a->content <= stacks->quartile[1])
		{
			pb(stacks);
			rb(&stacks->stack_b);
		}
		else
			ra(&stacks->stack_a);
		i++;
	}
}

void	sort_stack_b(t_stack *stacks)
{
	push_small_nbr(stacks);
	while (ft_lstsize(stacks->stack_a) > 3)
	{
		if (*stacks->stack_a->content <= stacks->quartile[2])
			pb(stacks);
		else
		{
			pb(stacks);
			rb(&stacks->stack_b);
		}
	}
}
