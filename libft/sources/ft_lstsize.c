/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:22:19 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/14 15:22:48 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;
	t_list	*top;
	t_list	*tmp;
	
	size = 0;
	top = lst;
	tmp = lst;
	if (!lst)
		return (0);
	if (tmp->next == top)
		return (1);
	while (tmp->next != NULL && tmp->next != top)
	{
		size++;
		tmp = tmp->next;
	}
	size++;
	return (size);
}
