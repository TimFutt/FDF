#include "fdf.h"
int         val_return(int y, int nb, int save)
{
    if (y == 0)
        return (nb);
    else if (save == nb)
        return (save);
    else
        return (-1);
}
int         check_line(char *str, int y, int save)
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
                return (-1);
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
    return (val_return(y, nb, save));
}
int         helper_all_tab(t_fdf *parse, char *line)
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
            return (-1);
    }
    free(line);
    free(tab);
    parse->lines++;
    return (0);
}
int         alloc_tab(t_fdf *parse)
{
    char    *line;
    int     ret;
    line = NULL;
    parse->lines = 0;
    parse->chars = 0;
    while ((ret = get_next_line(parse->fd, &line)) > 0)
    {
        if (helper_all_tab(parse, line) == -1)
            return (-1);
    }
    parse->map = ft_memalloc(sizeof(int*) * parse->lines);
    close(parse->fd);
    parse->fd = open(parse->name, O_RDONLY);
    return (0);
}
int         parser(t_fdf *parse)
{
    char    *line;
    char    **tab;
    int     xytab[3];
    xytab[1] = 0;
    if (alloc_tab(parse) == -1)
        return (-1);
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
    return ((xytab[2] == -1) ? -1 : 0);
}
