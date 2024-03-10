/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:22:19 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/10 13:22:01 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_lstsize(t_list *lst, t_list *first)
{
	int	size;

	size = 0;
	if (!lst)
		return (0);
	while (lst->next != first)
	{
		size++;
		lst = lst->next;
	}
	size++;
	return (size);
}
