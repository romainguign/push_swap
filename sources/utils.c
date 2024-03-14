/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:18:10 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/14 17:37:53 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_pos(t_list *stack, t_list *find)
{
	int	pos;

	pos = 1;
	while (stack != find)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}

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

int	is_sorted(t_list *stack)
{
	t_list	*top;

	top = stack;
	if (!stack)
		return (1);
	while(stack->next != top)
	{
		if (*stack->next->content < *stack->content)
			return (0);
		stack = stack->next;
	}
	return (1);
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
	else if (stack_from->type == 1 && stack_from->target->type == 1 || stack_from->type == 3
		&&  stack_from->target->type == 1 || stack_from->type == 1 &&  stack_from->target->type == 3)
	{
		printf ("TYPE choosen : %d\n", 1);
		printf ("element_nbr : %d count : %d\n", element_nbr, count);
		if (count < element_nbr)
			count = size_to - count + 1;
		else
			count = size_from - element_nbr + 1;
	}
	else if (stack_from->type == 2 && stack_from->target->type == 2 || stack_from->type == 3
		&&  stack_from->target->type == 2 || stack_from->type == 2 &&  stack_from->target->type == 3)
	{
		printf ("TYPE choosen : %d\n", 2);
		if (count < element_nbr)
			count = (element_nbr + 1);
		else
			count = count + 1;
			// printf ("element_nbr : %d count : %d\n", element_nbr, count);
	}
	else
	{
		printf ("TYPE choosen : %d\n", 3);
		if (stack_from->type == 1)
			element_nbr = size_from - element_nbr;
		if (stack_from->type == 1)
			count = size_to - count;
		printf ("element_nbr : %d count : %d\n", element_nbr, count);
		count = element_nbr + count + 1;
	}
	return (count);
}

int	calc_mediane(t_list *stack)
{
	int	size;
	int	mediane;

	if (!stack)
		return (0);
	size = ft_lstsize(stack);
	mediane = size / 2 + size % 2;
	return (mediane);
}