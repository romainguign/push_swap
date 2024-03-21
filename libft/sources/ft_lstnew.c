/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:53:11 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/21 13:58:50 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(long long int *content)
{
	t_list	*element_lst;

	element_lst = malloc(sizeof(t_list));
	if (!element_lst)
		return (0);
	element_lst->content = content;
	element_lst->next = NULL;
	element_lst->prev = NULL;
	element_lst->target = NULL;
	element_lst->type = 0;
	return (element_lst);
}
