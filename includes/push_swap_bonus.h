/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:34:00 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/21 15:22:18 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# define RR	1
# define R	2

typedef struct s_stack
{
	t_list				*stack_a;
	t_list				*stack_b;
	t_list				*top_a;
	t_list				*top_b;
	int					quartile[3];
}	t_stack;

int				parsing(t_stack **stacks, char **argv);
int				is_sorted(t_list *stack, int len_a);
long long int	ft_atoll(const char *nptr);
char			**ft_free_tab(char **tab);
void			free_stacks(t_stack *stacks, int len_a);

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

#endif