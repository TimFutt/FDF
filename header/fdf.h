/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 12:13:59 by tifuret           #+#    #+#             */
/*   Updated: 2018/04/06 12:17:21 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# define WIDTH 1920
# define HEIGHT 1080
# define FAILURE -1
# define SUCCESS 0

typedef struct		s_fdf
{
	int				fd;
	char			*name;
	void			*mlx;
	void			*win;
	char			**map;
	int				tabxy[2];
	int				lines;
	int				check;
	int				values;
	int				z;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				x;
	int				y;
	int				x1;
	int				y1;
	int				e2;
	int				err;
	unsigned long	color;
}					t_fdf;

void				ft_draw(t_fdf *draw);
void				ft_check_draw(t_fdf *draw);
void				ft_put_lines(t_fdf *draw);
void				ft_draw_line(t_fdf *draw, int x, int y);
void				ft_mlx(t_fdf *key);
int					ft_keyboard(int keycode, t_fdf *key);
void				ft_moove(int keycode, t_fdf *key);
void				ft_exit();
void				ft_zoom(int keycode, t_fdf *key);
void				ft_fdf(t_fdf *parse);
int					ft_parser(t_fdf *parse);
int					ft_alloc_tab(t_fdf *parse);
int					ft_helper_tab(t_fdf *parse, char *line);
int					get_next_line(const int fd, char **line);

#endif
