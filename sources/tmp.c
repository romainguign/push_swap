/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:58:49 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/10 15:01:37 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack_content(t_stack *stacks)
{
	t_list	*current_a;
	t_list	*current_b;
	int size;
	current_a = stacks->stack_a;
	current_b = stacks->stack_b;
	int i = 0;
	sa(stacks->stack_a, stacks->top_a);
	pb(stacks);
	size = ft_lstsize(stacks->stack_a, stacks->top_a);
	
	if (ft_lstsize(stacks->stack_b, stacks->top_b) > size)
		size = ft_lstsize(stacks->stack_a, stacks->top_a);
	printf ("         a                                                      b\n");
	printf ("    ============                                          =============\n");
	
	while (size > 0)
	{
		if (current_a)
			printf("%d---------------->%lld ", i, *(long long int *)current_a->content);
		if (current_b)
			printf("        %d---->%lld ", i, *(long long int *)current_b->content);
		printf("\n");
		if (current_a)
			printf("prev------------->%p", (long long int *)current_a->prev);
		if (current_b)
			printf("       prev---->%p", (long long int *)current_b->prev);
		printf ("\n");
		if (current_a)
			printf("current---------->%p\n", (long long int *)current_a);
		if (current_b)
			printf("current---------->%p\n", (long long int *)current_a);
		if (current_a)
			printf("next------------>%p\n\n", (long long int *)current_a->next);
		if (current_b)
			printf("next------------>%p\n\n", (long long int *)current_b->next);
		if (current_a && current_a->next != stacks->top_a)
			current_a = current_a->next;
		if (current_b && current_b->next != stacks->top_b)
			current_b = current_b->next;
		i++;
		size--;
	}
	printf("%d------------->%lld\n", i, *(long long int *)current_a->content);
		printf("prev----------->%p\n", (long long int *)current_a->prev);
		printf("current_a-------->%p\n", (long long int *)current_a);
		printf("next----------->%p\n\n", (long long int *)current_a->next);
		current_a = current_a->next;
	///////////////// FIN PRINT
}
