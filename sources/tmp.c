/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:58:49 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/14 13:59:20 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	test(t_stack *stacks)
{
	// ra(&stacks->stack_a);
	//  sa(stacks->stack_a);
	print_stack_content(stacks);
	
}

void	print_stack_content(t_stack *stacks)
{
	t_list	*current_a;
	t_list	*current_b;
	t_list	*top_a;
	t_list	*top_b;
	int a_status;
	int b_status;
	

	////////////////////////////////test changements

	
	a_status = 1;
	b_status = 1;
	int size;
	current_a = stacks->stack_a;
	current_b = stacks->stack_b;
	int i = 0;
	size = ft_lstsize(stacks->stack_a);
	if (ft_lstsize(stacks->stack_b) > size)
		size = ft_lstsize(stacks->stack_b);
	top_a = current_a;
	top_b = current_b;
	printf ("         a                                                      b\n");
	printf ("    ============                                          =============\n");
	while (size > 0)
	{
		if (current_a && *current_a->content && a_status == 1)
			printf("content---------------->%lld ", *current_a->content);
		else
			printf("                           ");
		if (current_b && b_status == 1)
			printf("                          content--------------->%lld ", *current_b->content);
		printf("\n");
		// if (current_a && a_status == 1)
		// 	printf("prev------------->%p", (long long int *)current_a->prev);
		// else
		// 	printf("                           ");
		// if (current_b && b_status == 1)
		// 	printf("                           prev------------->%p", (long long int *)current_b->prev);
		// printf ("\n");
		// if (current_a && a_status == 1)
		// 	printf("current---------->%p", (long long int *)current_a);
		// else
		// 	printf("                           ");
		// if (current_b && b_status == 1)
		// 	printf("                           current--------->%p", (long long int *)current_b);
		// printf ("\n");
		// if (current_a && a_status == 1)
		// 	printf("next------------->%p", (long long int **)current_a->next);
		// else
		// 	printf("                          ");
		// if (current_b && b_status == 1)
		// 	printf("                            next------------->%p", (long long int **)current_b->next);
		// printf ("\n");
		if (current_a && current_a->next != top_a && a_status == 1)
			current_a = current_a->next;
		else
			a_status = 0;
		if (current_b && current_b->next != top_b)
			current_b = current_b->next;
		else
			b_status = 0;
		i++;
		size--;
		printf ("\n");
	}
	// // printf("%d------------->%lld\n", i, *(long long int *)current_a->content);
	// // 	printf("prev----------->%p\n", (long long int *)current_a->prev);
	// // 	printf("current_a-------->%p\n", (long long int *)current_a);
	// // 	printf("next----------->%p\n\n", (long long int *)current_a->next);
	// // 	current_a = current_a->next;
	// // ///////////////// FIN PRINT
}
