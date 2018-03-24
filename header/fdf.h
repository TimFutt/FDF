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
	int				**map;
	int				tabxy[2];
	int				lines;
	int				check;
	int				chars;
	int				z;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				e2;
	int 			err;
	unsigned long	color;
}					t_fdf;

void	ft_draw(t_fdf *draw);
void	ft_check_draw(t_fdf *draw);
void	ft_put_lines(t_fdf *draw);
void	ft_draw_line(t_fdf *draw, int x, int y);
void	ft_mlx(t_fdf *key);
int	  ft_keyboard(int keycode, t_fdf *key);
void	ft_moove(int keycode, t_fdf *key);
void	ft_exit();
void	ft_zoom(int keycode, t_fdf *key);
void	ft_fdf(t_fdf *parse);
int		ft_parser(t_fdf *parse);
int		ft_alloc_tab(t_fdf *parse);
int		ft_helper_tab(t_fdf *parse, char *line);
int		ft_checker(char *str, int y, int save);
int		ft_val_return(int y, int nb, int save);
int		get_next_line(const int fd, char **line);

#endif
