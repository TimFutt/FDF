/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:15:45 by tifuret           #+#    #+#             */
/*   Updated: 2017/11/22 16:04:05 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*map;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	map = ft_strdup((char *)s);
	if (!map || !f)
		return (NULL);
	while (map[i])
	{
		map[i] = f(map[i]);
		i++;
	}
	return (map);
}
