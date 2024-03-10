#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

typedef struct s_stack
{
	t_list	*stack_b;
	t_list	*stack_a;
	t_list	*top_a;
	t_list	*top_b;
} t_stack;

int	parsing(t_stack **stacks, char **argv);
long long int	ft_atoll(const char *nptr);
char	**ft_free_tab(char **tab);

/////////////////////////////TMP
void	print_stack_content(t_stack *stacks);

/////////////////////////   MOVES  //////////////////////////

void	sa(t_list *stack_a, t_list *top_a);
void	sb(t_list *stack_b, t_list *start_b);
void	ss(t_stack *stacks);
void	pa(t_stack *stacks);
void	pb(t_stack *stacks);

#endif