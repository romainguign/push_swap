/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:51:46 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/21 14:29:36 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_args(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if ((args[i][j] == '+' || args[i][j] == '-')
				&& !ft_isdigit(args[i][j + 1]))
				return (0);
			if (j != 0 && (args[i][j] == '+' || args[i][j] == '-')
				&& ft_isdigit(args[i][j - 1]))
				return (0);
			if (ft_isalpha(args[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_double(t_stack *stacks, long long int *num)
{
	t_list	*stack_a;

	stack_a = stacks->stack_a;
	while (stack_a)
	{
		if (*(long long int *)stack_a->content == *num)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	make_stack(t_stack **stacks, char **args, int j)
{
	long long int	*num;

	num = ft_calloc(1, sizeof(long long int *));
	*num = ft_atoll(args[j]);
	if (!check_double(*stacks, num) || *num > INT_MAX || *num < INT_MIN)
	{
		write(2, "Error\n", 6);
		ft_free_tab(args);
		ft_lstclear(&(*stacks)->stack_a, free);
		free(num);
		return (0);
	}
	ft_lstadd_back(&(*stacks)->stack_a, ft_lstnew(num));
	return (1);
}

int	pars_args(t_stack **stacks, char **argv, int i)
{
	int		j;
	char	**args;

	while (argv[i])
	{
		j = 0;
		args = ft_split(argv[i], ' ');
		if (!args || !args[0] || !check_args(args))
		{
			write(2, "Error\n", 6);
			ft_free_tab(args);
			if ((*stacks)->stack_a)
				ft_lstclear(&(*stacks)->stack_a, free);
			return (0);
		}
		while (args[j])
		{
			if (make_stack(stacks, args, j) == 0)
				return (0);
			j++;
		}
		ft_free_tab(args);
		i++;
	}
	return (1);
}

int	parsing(t_stack **stacks, char **argv)
{
	int		i;

	i = 1;
	if (pars_args(stacks, argv, i) == 0)
		return (0);
	(*stacks)->top_a = (*stacks)->stack_a;
	(*stacks)->stack_a->prev = ft_lstlast((*stacks)->stack_a);
	(*stacks)->stack_a->prev->next = (*stacks)->top_a;
	return (1);
}
