#include "../header/fdf.h"
int         ft_val_return(int y, int nb, int save)
{
    if (y == 0)
        return (nb);
    else if (save == nb)
        return (save);
    else
        return (FAILURE);
}
int         ft_checker(char *str, int y, int save)
{
    int     i;
    int     k;
    int     nb;
    i = 0;
    k = 0;
    nb = 0;
    while (str[i])
    {
        if (ft_isdigit(str[i]) == 0)
        {
            if (str[i] != ' ')
                return (FAILURE);
            k = 0;
        }
        else
        {
            if (k == 0)
                nb++;
            k++;
        }
        i++;
    }
    return (ft_val_return(y, nb, save));
}
int         ft_helper_tab(t_fdf *parse, char *line)
{
    int     x;
    char    **tab;
    x = 0;
    tab = ft_strsplit(line, ' ');
    while (tab[x])
    {
        free(tab[x]);
        x++;
    }
    if (parse->lines == 0)
        parse->chars = x;
    else
    {
        if (x != parse->chars)
            return (FAILURE);
    }
    free(line);
    free(tab);
    parse->lines++;
    return (SUCCESS);
}
int         ft_alloc_tab(t_fdf *parse)
{
    char    *line;
    int     ret;
    line = NULL;
    parse->lines = 0;
    parse->chars = 0;
    while ((ret = get_next_line(parse->fd, &line)) > 0)
    {
        if (ft_helper_tab(parse, line) == FAILURE)
            return (FAILURE);
    }
    parse->map = ft_memalloc(sizeof(int*) * parse->lines);
    close(parse->fd);
    parse->fd = open(parse->name, O_RDONLY);
    return (SUCCESS);
}
int         ft_parser(t_fdf *parse)
{
    char    *line;
    char    **tab;
    int     xytab[3];
    xytab[1] = 0;
    if (ft_alloc_tab(parse) == FAILURE)
        return (FAILURE);
    while ((xytab[2] = get_next_line(parse->fd, &line)) > 0)
    {
        xytab[0] = 0;
        tab = ft_strsplit(line, ' ');
        parse->map[xytab[1]] = ft_memalloc(sizeof(int) * parse->chars);
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
