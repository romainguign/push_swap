/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:29:28 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/20 14:32:33 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define RR 1
# define R 2

typedef struct s_stack
{
	t_list				*stack_a;
	t_list				*stack_b;
	t_list				*top_a;
	t_list				*top_b;
	long long int		quartile[3];
}	t_stack;

int				parsing(t_stack **stacks, char **argv);
int				is_sorted(t_list *stack);
int				find_quartile(t_stack *stacks, int i);
long long int	ft_atoll(const char *nptr);
char			**ft_free_tab(char **tab);

/////////////////////////////TMP
void			print_stack_content(t_stack *stacks);
void			test(t_stack *stacks);

//////////////////////////// UTILS
t_list			*find_min(t_list	*stack);

/////////////////////////   MOVES  //////////////////////////

void			sa(t_list *stack_a);
void			sb(t_list *stack_b);
void			ss(t_stack *stacks);
void			pa(t_stack *stacks);
void			pb(t_stack *stacks);
void			ra(t_list **stack_a);
void			rb(t_list **stack_b);
void			rr(t_list **stack_a, t_list **stack_b);
void			rra(t_list **stack_b);
void			rrb(t_list **stack_b);
void			rrr(t_list **stack_a, t_list **stack_b);

////////////////////   Sorting algorithm   ////////////////////

// 3 elements cases;
void			three_elements_case(t_stack *stacks, t_list *stack_a);
void			biggest_first(t_stack *stacks);
void			biggest_second(t_stack *stacks);

// n elements cases;
t_list			*find_min(t_list	*stack);
void			sort_and_push_a(t_stack *stacks, t_list *cheapest_element);
void			sort_and_push_b(t_stack *stacks, t_list *cheapest_element);
void			sort_stack_b(t_stack *stacks);
void			sort_stack_a(t_stack *stacks);
int				calc_mediane(t_list *stack);
int				count_pos(t_list *stack, t_list *find);
int				count_nbr(t_list *stack_from, t_list *stack_to, int count, \
	int element_nbr);

#endif