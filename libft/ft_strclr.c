/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:59:45 by tifuret           #+#    #+#             */
/*   Updated: 2017/11/23 12:24:15 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int		len;

	if (!s)
		return ;
	len = ft_strlen(s);
	while (len >= 0)
	{
		s[len] = '\0';
		len--;
	}
}
