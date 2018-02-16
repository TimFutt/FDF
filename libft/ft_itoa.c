/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:19:35 by tifuret           #+#    #+#             */
/*   Updated: 2017/11/23 12:40:12 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		ft_digitnb(int n)
{
	long	size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size++);
}

static int		ft_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char			*ft_itoa(int n)
{
	long	n_long;
	long	len;
	char	*nbr;

	n_long = n;
	len = ft_digitnb(n_long);
	nbr = (char *)malloc((len + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	nbr[len] = '\0';
	len--;
	if (n_long < 0)
		n_long = -n_long;
	while (len >= 0)
	{
		nbr[len] = (n_long % 10) + '0';
		len--;
		n_long /= 10;
	}
	if (ft_sign(n))
		nbr[0] = '-';
	return (nbr);
}
