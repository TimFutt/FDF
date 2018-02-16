/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:59:05 by tifuret           #+#    #+#             */
/*   Updated: 2017/11/23 12:40:03 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		start;
	char	**str;

	if (!s)
		return (NULL);
	j = 0;
	j = ft_wordcount(s, c);
	if ((str = (char **)malloc(sizeof(*str) * j + 1)) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		(i > start) ? str[j++] = ft_strsub(s, start, i - start) : 0;
	}
	str[j] = NULL;
	return (str);
}
