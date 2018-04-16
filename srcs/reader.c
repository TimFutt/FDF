/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 12:28:46 by tifuret           #+#    #+#             */
/*   Updated: 2018/04/06 12:36:22 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

/*
** Check de la map
** 1- Strsplit de la map et stocker chaque valeur dans le tab
** 2- Check de la longueur de la 1er ligne
** 3- Incremente de ligne en ligne
** 4- Si lignes suivantes pas la meme taille que la 1ere ligne alors failed
*/

int		ft_helper_tab(t_fdf *parse, char *line)
{
	int		x;
	char	**tab;

	x = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[x])
	{
		free(tab[x]);
		x++;
	}
	if (parse->lines == 0)
		parse->values = x;
	else
	{
		if (x != parse->values)
			return (FAILURE);
	}
	free(line);
	free(tab);
	parse->lines++;
	return (SUCCESS);
}

/*
** Allocation memoire
** Placement de chaque lignes dans la liste
*/

int		ft_alloc_tab(t_fdf *parse)
{
	char	*line;
	int		ret;

	line = NULL;
	parse->lines = 0;
	parse->values = 0;
	while ((ret = get_next_line(parse->fd, &line)) > 0)
	{
		if (ft_helper_tab(parse, line) == FAILURE)
			return (FAILURE);
	}
	parse->map = ft_memalloc(sizeof(char*) * parse->lines);
	parse->fd = open(parse->name, O_RDONLY);
	return (SUCCESS);
}

/*
** Parsing classique
** 1- Mise en place de la map dans un char**
** 2- strsplit pour separer chaque ligne
**  - memalloc pour clean xytab[1] a chaque ligne
** 3- Atoi de chaque valeur contenu dans le tableau
**    pour qu'elles puissent etre lu
** 3- Si lecture fail alors return fail sinon success -> go back to the main
*/

int		ft_parser(t_fdf *parse)
{
	char	*line;
	char	**tab;
	int		xytab[3];

	xytab[1] = 0;
	if (ft_alloc_tab(parse) == FAILURE)
		return (FAILURE);
	while ((xytab[2] = get_next_line(parse->fd, &line)) > 0)
	{
		xytab[0] = 0;
		tab = ft_strsplit(line, ' ');
		parse->map[xytab[1]] = ft_memalloc(sizeof(char) * parse->values);
		while (tab[xytab[0]] != NULL)
		{
			parse->map[xytab[1]][xytab[0]] = ft_atoi(tab[xytab[0]]);
			free(tab[xytab[0]]);
			xytab[0]++;
		}
		free(tab);
		xytab[1]++;
	}
	return ((xytab[2] == FAILURE) ? FAILURE : SUCCESS);
}
