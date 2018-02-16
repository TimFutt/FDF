/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:05:42 by tifuret           #+#    #+#             */
/*   Updated: 2017/11/22 15:16:02 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;

	copy = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (copy == NULL)
		return (NULL);
	else
		copy = ft_strcpy(copy, s);
	return (copy);
}
