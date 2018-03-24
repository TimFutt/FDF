#include "../header/fdf.h"
void        ft_zoom(int keycode, t_fdf *key)
{
    if (keycode == 13 && key->sx * 2 <= 500 && key->sy * 2 <= 500)
    {
        mlx_clear_window(key->mlx, key->win);
        key->sx *= 2;
        key->sy *= 2;
        key->z *= 2;
        ft_draw(key);
    }
    if (keycode == 1 && key->sx * 0.5 >= 1 && key->sy * 0.5 >= 1 &&
        (-key->z * 0.5 >= 1 || key->z * 0.5 >= 1))
    {
        mlx_clear_window(key->mlx, key->win);
        key->sx *= 0.5;
        key->sy *= 0.5;
        key->z *= 0.5;
        ft_draw(key);
    }
}

void ft_exit()
{
    exit(0);
}

void        ft_moove(int keycode, t_fdf *key)
{
    if ((keycode >= 123 && keycode <= 126) || keycode == 15)
    {
        mlx_clear_window(key->mlx, key->win);
        if (keycode == 123)
            key->dx -= 10;
        if (keycode == 126)
            key->dy -= 10;
        if (keycode == 124)
            key->dx += 10;
        if (keycode == 125)
            key->dy += 10;
        if (keycode == 15)
            key->check = 0;
        ft_draw(key);
    }
}
int ft_keyboard(int keycode, t_fdf *key)
{
    if (keycode == 53)
        ft_exit();
    if (keycode == 12)
    {
        mlx_clear_window(key->mlx, key->win);
        key->z++;
        ft_draw(key);
    }
    if (keycode == 14)
    {
        mlx_clear_window(key->mlx, key->win);
        key->z--;
        ft_draw(key);
    }
    if (keycode == 8)
    {
        mlx_clear_window(key->mlx, key->win);
        if (key->check % 11 == 0)
          key->color = 0xFF000000;
        key->color = key->color >> 2;
        ft_draw(key);
    }
    ft_zoom(keycode, key);
    ft_moove(keycode, key);
    return (0);
}
void        ft_mlx(t_fdf *key)
{
    key->check = 0;
    key->mlx = mlx_init();
    key->win = mlx_new_window(key->mlx, WIDTH, HEIGHT, "FDF");
    ft_draw(key);
    mlx_key_hook(key->win, ft_keyboard, key);
    mlx_loop(key->mlx);
}
