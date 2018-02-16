/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:53:32 by tifuret           #+#    #+#             */
/*   Updated: 2017/11/23 12:19:47 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (to_find[i])
		i++;
	if (i == 0)
		return ((char *)str);
	while (str[k])
	{
		while (to_find[j] == str[k + j])
		{
			if (j == i - 1)
				return ((char *)(str + k));
			j++;
		}
		j = 0;
		k++;
	}
	return (0);
}
