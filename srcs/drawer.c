#include "../header/fdf.h"

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

void	ft_check_draw(t_fdf *draw)
{
	if (draw->check == 0)
	{
		draw->z = -5;
		draw->dx = WIDTH * 0.4;
		draw->dy = 20;
		draw->sx = (WIDTH * 0.7) / (draw->chars - 1);
		draw->sy = (HEIGHT * 0.5) / (draw->lines - 1);
		draw->color = 0x00FFFFFF;
	}
	draw->check++;
}

void	ft_put_lines(t_fdf *draw)
{

	draw->tabxy[0] = draw->dx + (draw->x0 - draw->y0);
	draw->tabxy[1] = draw->dy + draw->map[draw->y0 / draw->sy][draw->x0 / draw->sx] * draw->z + draw->x0 + draw->y0;
	if (draw->x0 / draw->sx < draw->chars - 1 && draw->y0 / draw->sy < draw->lines)
  {
		ft_draw_line(draw , draw->dx + ((draw->x0 + draw->sx) - draw->y0), draw->dy + draw->map[draw->y0 / draw->sy][draw->x0 / draw->sx + 1] * draw->z + draw->x0 + draw->sx + draw->y0);
  }
	if (draw->y0 / draw->sy < draw->lines - 1 && draw->x0 / draw->sx < draw->chars)
  {
		ft_draw_line(draw, draw->dx + (draw->x0 - (draw->y0 + draw->sy)), draw->dy + draw->map[draw->y0 / draw->sy + 1][draw->x0 / draw->sx] * draw->z + draw->x0 + draw->y0 + draw->sy);
  }
}

void	ft_draw(t_fdf *draw)
{
	draw->x0 = 0;
	draw->y0 = 0;
	ft_check_draw(draw);
	while (draw->x0 / draw->sx < draw->chars || draw->y0 / draw->sy < draw->lines - 1)
	{
		if (draw->x0 / draw->sx == draw->chars)
		{
			draw->x0 = 0;
			draw->y0 += draw->sy;
		}
		ft_put_lines(draw);
		draw->x0 += draw->sx;
	}
}
