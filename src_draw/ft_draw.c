#include <ft_draw.h>

void    ft_auto_pixel_put(t_param *param, t_dot position_dot, int color)
{
    mlx_pixel_put(param->mlx_ptr, param->win_ptr, position_dot.x, position_dot.y + 10, ft_draw_color(color));
}

void    ft_auto_line_draw(t_param *param, t_dot position_dot, t_dot next_dot)
{
    float   x_allow;
    float   y_allow;
    float   z_allow;
    t_ratio c_ratio;

    ft_ratio_init(&c_ratio, position_dot, next_dot);
    x_allow = -ft_sign(position_dot.x - next_dot.x);
    y_allow = -ft_sign(position_dot.y - next_dot.y);
    z_allow = -ft_sign(position_dot.z - next_dot.z);
    if (ft_abs(position_dot.x - next_dot.x) > ft_abs(position_dot.y - next_dot.y))
    {
        while (position_dot.x != next_dot.x)
        {
            ft_auto_pixel_put(param, position_dot, position_dot.z);
            position_dot.x += x_allow;
            position_dot.y += y_allow * c_ratio.y;
            position_dot.z += z_allow * c_ratio.z;
        }
    }
    else
    {
        while (position_dot.y != next_dot.y)
        {
            ft_auto_pixel_put(param, position_dot, position_dot.z);
            position_dot.y += y_allow;
            position_dot.x += x_allow * c_ratio.x;
            position_dot.z += z_allow * c_ratio.z;
        }
    }
}