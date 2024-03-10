/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:51:46 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/10 15:00:06 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check_args(char **args)
{
	int	i;
	int	j;
	
	i = 0;
	while (args[i])
	{
		j = 0;
		if (!ft_isdigit(args[i][j]) && (args[i][j] != '+' && args[i][j] != '-'))
			return(0);
		j++;
		while(args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_double(t_stack *stacks, long long int *num)
{
	t_list *stack_a;

	stack_a = stacks->stack_a;
	while (stack_a)
	{
		if (*(long long int *)stack_a->content == *num)
			return (0);
		stack_a = stack_a->next;
	}
	return(1);
}

int	make_stack(t_stack **stacks, char **args, int j)
{
	long long int	*num;

	num = ft_calloc(1, sizeof(long long int *));
	*num = ft_atoll(args[j]);
	if (!check_double(*stacks, num))
	{
		printf("Error \n");
		ft_free_tab(args);
		ft_lstclear(&(*stacks)->stack_a, free);
		free(num);
		return (0);
	}
	ft_lstadd_back(&(*stacks)->stack_a, ft_lstnew(num));
	return (1);
}

int	parsing(t_stack **stacks, char **argv)
{
	int		i;
	int		j;
	char	**args;

	i = 1;
	while (argv[i])
	{
		j = 0;
		args = ft_split(argv[i], ' ');
		if (!args || !check_args(args))
		{
			printf("Error \n");
			ft_free_tab(args);
			ft_lstclear(&(*stacks)->stack_a, free);
			return (0);
		}
		while (args[j])
		{
			if (make_stack(stacks, args, j) == 0)
				return 0;
			j++;
		}
		ft_free_tab(args);
		i++;
	}
	(*stacks)->top_a = (* stacks)->stack_a;
	(*stacks)->stack_a->prev = ft_lstlast((*stacks)->stack_a);
	(*stacks)->stack_a->prev->next = (*stacks)->top_a;
	return (1);
}
