/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:50:36 by roguigna          #+#    #+#             */
/*   Updated: 2023/11/30 14:28:34 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_len_nbr(long int n)
{
	int	len;

	len = 0;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	int			negative;
	long int	nbr;
	char		str_nbr[12];
	char		*returned_number;

	nbr = (long int)n;
	negative = 0;
	if (nbr < 0)
	{
		negative = 1;
		nbr *= -1;
	}
	len = ft_len_nbr(nbr) + negative;
	if (negative == 1)
		str_nbr[0] = '-';
	str_nbr[len] = '\0';
	while (len - 1 >= negative)
	{
		str_nbr[len - 1] = nbr % 10 + 48;
		nbr = nbr / 10;
		len--;
	}
	returned_number = ft_strdup(str_nbr);
	return (returned_number);
}
