/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:44:58 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/07 18:12:41 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*e_last;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	e_last = *lst;
	while (e_last->next)
		e_last = e_last->next;
	e_last->next = new;
	e_last->next->prev = e_last;
}
