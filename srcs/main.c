#include "../header/fdf.h"

int     main(int ac, char **av)
{
    t_fdf     main;
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
