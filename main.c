#include "fdf.h"
#include <fcntl.h>
void    fdf(t_fdf *parse)
{
    if (parser(parse) == -1)
    {
        ft_putendl("Error");
        return ;
    }
    mlx(parse);
}
int     main(int ac, char **av)
{
    t_fdf   mine;
    if (ac == 2)
    {
        mine.name = av[1];
        mine.fd = open(mine.name, O_RDONLY);
        fdf(&mine);
    }
    else
        ft_putendl("usage: ./fdf file");
    return (0);
}
