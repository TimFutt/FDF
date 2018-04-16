/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 12:36:38 by tifuret           #+#    #+#             */
/*   Updated: 2018/04/06 12:37:35 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int		main(int ac, char **av)
{
	t_fdf	main;

	if (ac == 2)
	{
		main.name = av[1];
		main.fd = open(main.name, O_RDONLY);
		if (ft_parser(&main) == FAILURE)
		{
			ft_putendl("Error");
			return (0);
		}
		ft_mlx(&main);
	}
	else
		ft_putendl("usage: ./fdf file");
	return (0);
}
