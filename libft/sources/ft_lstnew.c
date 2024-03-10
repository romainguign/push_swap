/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:53:11 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/07 18:11:23 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*element_lst;

	element_lst = malloc(sizeof(t_list));
	if (!element_lst)
		return (0);
	element_lst->content = content;
	element_lst->next = NULL;
	element_lst->prev = NULL;
	return (element_lst);
}
