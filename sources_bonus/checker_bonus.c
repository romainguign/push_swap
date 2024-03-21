/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:38:25 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/21 15:15:45 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	do_moves(t_stack *stacks, char *line)
{
	if (!ft_strncmp(line, "rra\n", 4))
		rra(&(stacks->stack_a));
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(&(stacks->stack_b));
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(&(stacks->stack_a), &(stacks->stack_b));
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(&(stacks->stack_a), &(stacks->stack_b));
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(&(stacks->stack_a));
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(&(stacks->stack_b));
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(stacks);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(stacks);
	else if (!ft_strncmp(line, "sa\n", 3))
		sa(stacks->stack_a);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(stacks->stack_b);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(stacks);
	else
		return (0);
	return (1);
}

int	check_moves(t_stack *stacks)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
		{
			get_next_line(-1);
			if (line)
				free(line);
			break ;
		}
		if (!do_moves(stacks, line))
		{
			get_next_line(-1);
			free(line);
			write(2, "Error\n", 6);
			return (0);
		}
		free(line);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stacks;
	int		len_a;

	if (argc < 2)
		return (1);
	stacks = ft_calloc(1, sizeof(t_stack));
	if (!parsing(&stacks, argv))
	{
		free(stacks);
		return (1);
	}
	len_a = ft_lstsize(stacks->stack_a);
	if (check_moves(stacks) == 0)
	{
		free_stacks(stacks, len_a);
		return (1);
	}
	if (is_sorted(stacks->stack_a, len_a) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(stacks, len_a);
	return (0);
}
