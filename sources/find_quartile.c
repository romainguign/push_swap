/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_quartile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:33:47 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/20 14:28:27 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(long long int *a, long long int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	ft_sort_int_tab(long long int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i +1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}

int	find_quartile(t_stack *stacks, int i)
{
	t_list			*tmp;
	t_list			*top_a;
	long long int	*tab;
	int				size;

	tmp = stacks->stack_a;
	top_a = tmp;
	size = ft_lstsize(stacks->stack_a);
	tab = ft_calloc(size + 1, sizeof(long long int));
	if (!tab)
		return (0);
	while (tmp->next != top_a)
	{
		tab[i] = *tmp->content;
		tmp = tmp->next;
		i++;
	}
	tab[i] = *tmp->content;
	ft_sort_int_tab(tab, size);
	stacks->quartile[0] = tab[size / 4];
	stacks->quartile[1] = tab[size / 2];
	stacks->quartile[2] = tab[size - size / 4];
	free(tab);
	return (1);
}
