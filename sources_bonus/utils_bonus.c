/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:18:10 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/21 15:22:49 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	**ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (tab);
}

long long int	ft_atoll(const char *nptr)
{
	long long int	i;
	long long int	nbr;
	long long int	negative;

	i = 0;
	nbr = 0;
	negative = 0;
	while ((nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			negative = 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + (nptr[i] - 48);
		i++;
	}
	if (negative == 1)
		nbr *= -1;
	return (nbr);
}

int	is_sorted(t_list *stack, int len_a)
{
	t_list	*top;

	top = stack;
	if (!stack || ft_lstsize(stack) != len_a)
		return (0);
	while (stack->next != top)
	{
		if (*stack->next->content < *stack->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	free_stacks(t_stack *stacks, int len_a)
{
	while (len_a != ft_lstsize(stacks->stack_a))
		pa(stacks);
	if (stacks->stack_a)
		ft_lstclear(&stacks->stack_a, free);
	free(stacks);
}
