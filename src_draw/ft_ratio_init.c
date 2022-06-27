#include <ft_draw.h>

t_ratio    ft_ratio_init(t_ratio *c_ratio, t_dot position_dot, t_dot next_dot)
{
    c_ratio->x = ft_ratio(position_dot.x - next_dot.x, position_dot.y - next_dot.y);
    c_ratio->y = ft_ratio(position_dot.y - next_dot.y, position_dot.x - next_dot.x);
    if (ft_abs(position_dot.x - next_dot.x) > ft_abs(position_dot.y - next_dot.y))
        c_ratio->z = ft_ratio(position_dot.z - next_dot.z, position_dot.x - next_dot.x);
    else 
        c_ratio->z = ft_ratio(position_dot.z - next_dot.z, position_dot.y - next_dot.y);
    return (*c_ratio);
}