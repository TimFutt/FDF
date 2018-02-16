#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# define WIDTH 1560
# define HEIGHT 1300

typedef struct		s_fdf
{
	int				fd;
	char			*name;
	void			*mlx;
	void			*win;
	int				**map;
	int				lines;
	int				check;
	int				chars;
	int				z;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	unsigned long	color;
}					t_fdf;

void	draw(t_fdf *draw);
void	draw_lines(t_fdf *draw, int x, int y);
void	check_env(t_fdf *draw);
void	draw_line(t_fdf *draw, int *tabxy, int x, int y);
void	mlx(t_fdf *key);
int		keyboard(int keycode, t_fdf *key);
void	decal(int keycode, t_fdf *key);
int		cross(void);
void	zoom(int keycode, t_fdf *key);
void	fdf(t_fdf *parse);
int		parser(t_fdf *parse);
int		alloc_tab(t_fdf *parse);
int		helper_all_tab(t_fdf *parse, char *line);
int		check_line(char *str, int y, int save);
int		val_return(int y, int nb, int save);
int		get_next_line(const int fd, char **line);

#endif
