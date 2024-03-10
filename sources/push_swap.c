/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:38:25 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/10 12:58:46 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stacks;
	
	if (argc < 2)
		return (1);
	stacks = ft_calloc(1, sizeof(t_stack));
	parsing(&stacks, argv);
	
	////////////////////PRINT
	print_stack_content(stacks);
	ft_lstclear(&stacks->stack_a, free);
	free(stacks);
	
}
