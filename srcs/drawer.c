/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:40:39 by tifuret           #+#    #+#             */
/*   Updated: 2018/04/11 15:21:56 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

/*
** Fonction qui trace une ligne
** Suit la formule de l'algo de Brasenham
*/

void	ft_draw_line(t_fdf *draw, int x, int y)
{
	int		tabx[2];
	int		taby[2];
	int		x0;
	int		y0;

	x0 = draw->tabxy[0];
	y0 = draw->tabxy[1];
	tabx[0] = abs(x - x0);
	tabx[1] = x0 < x ? 1 : -1;
	taby[0] = abs(y - y0);
	taby[1] = y0 < y ? 1 : -1;
	draw->err = (tabx[0] > taby[0] ? tabx[0] : -taby[0]) / 2;
	while (x0 != x || y0 != y)
	{
		mlx_pixel_put(draw->mlx, draw->win, x0, y0, draw->color);
		draw->e2 = draw->err;
		draw->e2 > -tabx[0] ? draw->err -= taby[0] : 1;
		draw->e2 > -tabx[0] ? x0 += tabx[1] : 1;
		draw->e2 < taby[0] ? draw->err += tabx[0] : 1;
		draw->e2 < taby[0] ? y0 += taby[1] : 1;
	}
}

/*
** Check si on peut draw
** Ex = Si la map sort trop de la fenetre
*/

void	ft_check_draw(t_fdf *draw)
{
	if (draw->check == 0)
	{
		draw->z = -5;
		draw->dx = WIDTH * 0.4;
		draw->dy = 20;
		draw->sx = (WIDTH * 0.7) / (draw->values - 1);
		draw->sy = (HEIGHT * 0.5) / (draw->lines - 1);
		draw->color = 0x00FFFFFF;
	}
	draw->check++;
}

/*
** Affichage des lignes en quadrillage
*/

void	ft_put_lines(t_fdf *draw)
{
	draw->tabxy[0] = draw->dx + (draw->x - draw->y);
	draw->tabxy[1] = draw->dy + draw->map[draw->y / draw->sy][draw->x
		/ draw->sx] * draw->z + draw->x + draw->y;
	if (draw->x / draw->sx < draw->values - 1 && draw->y
			/ draw->sy < draw->lines)
	{
		ft_draw_line(draw, draw->dx + ((draw->x + draw->sx) - draw->y), draw->dy
				+ draw->map[draw->y / draw->sy][draw->x / draw->sx + 1]
				* draw->z + draw->x + draw->sx + draw->y);
	}
	if (draw->y / draw->sy < draw->lines - 1 && draw->x
			/ draw->sx < draw->values)
	{
		ft_draw_line(draw, draw->dx + (draw->x - (draw->y + draw->sy)), draw->dy
				+ draw->map[draw->y / draw->sy + 1][draw->x / draw->sx]
				* draw->z + draw->x + draw->y + draw->sy);
	}
}

/*
** Fonction mere
** Initialisation des fonctions de draw
*/

void	ft_draw(t_fdf *draw)
{
	draw->x = 0;
	draw->y = 0;
	ft_check_draw(draw);
	while (draw->x / draw->sx < draw->values || draw->y / draw->sy
			< draw->lines - 1)
	{
		if (draw->x / draw->sx == draw->values)
		{
			draw->x = 0;
			draw->y += draw->sy;
		}
		ft_put_lines(draw);
		draw->x += draw->sx;
	}
}
