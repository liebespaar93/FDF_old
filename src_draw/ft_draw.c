#include <ft_draw.h>

void    ft_auto_pixel_put(t_param *param, t_dot position_dot, int color)
{
    if (-WIN_WIDTH/2 < position_dot.x && position_dot.x < WIN_WIDTH/2 && -WIN_HEIGHT/2 < position_dot.y && position_dot.y < WIN_HEIGHT/2)
    {
        mlx_pixel_put(param->mlx_ptr, \
        param->win_ptr, \
        position_dot.x + WIN_WIDTH/2 + param->x, \
        position_dot.y + WIN_HEIGHT/2 + param->y, \
        color);
    }
}

void    ft_auto_ratio_draw(t_param *param, t_dot *position_dot, t_allow c_allow, t_ratio c_ratio)
{
    ft_auto_pixel_put(param, *position_dot, ft_draw_color(position_dot->z * 10));
    position_dot->x += c_allow.x * c_ratio.x;
    position_dot->y += c_allow.y * c_ratio.y;
    position_dot->z += c_allow.z * c_ratio.z;
}

void    ft_auto_line_draw(t_param *param, t_dot position_dot, t_dot next_dot)
{
    t_ratio c_ratio;
    t_allow c_allow;

    ft_ratio_init(&c_ratio, position_dot, next_dot);
    ft_allow_init(&c_allow, position_dot, next_dot);

    if (c_ratio.x == 1)
        while (ft_abs(position_dot.x) <= ft_abs(next_dot.x))
            ft_auto_ratio_draw(param, &position_dot, c_allow, c_ratio);
    else if (c_ratio.y == 1)
        while (ft_abs(position_dot.y) <= ft_abs(next_dot.y))
            ft_auto_ratio_draw(param, &position_dot, c_allow, c_ratio);
    else if (c_ratio.z == 1)
        while (ft_abs(position_dot.z) <= ft_abs(next_dot.z))
            ft_auto_ratio_draw(param, &position_dot, c_allow, c_ratio);
    
}