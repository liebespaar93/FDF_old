#include <ft_draw.h>


float    ft_ratio_max(t_ratio *c_distance, t_dot position_dot, t_dot next_dot)
{
    float max_distance;

    max_distance = 0;
    c_distance->x = ft_abs(position_dot.x - next_dot.x);
    c_distance->y = ft_abs(position_dot.y - next_dot.y);
    c_distance->z = ft_abs(position_dot.z - next_dot.z);
    max_distance = c_distance->x;
    if (max_distance < c_distance->y)
        max_distance = c_distance->y;
    if (max_distance < c_distance->z)
        max_distance = c_distance->z;
    return (max_distance);
}

t_ratio    ft_ratio_init(t_ratio *c_ratio, t_dot position_dot, t_dot next_dot)
{
    float max_distance;
    t_ratio c_distance;
    
    max_distance = ft_ratio_max(&c_distance , position_dot, next_dot);
    if (!max_distance)
    {
        c_ratio->x = 1;
        c_ratio->y = 1;
        c_ratio->z = 1;
        return (*c_ratio);
    }
    c_ratio->x = ft_ratio(c_distance.x, max_distance);
    c_ratio->y = ft_ratio(c_distance.y, max_distance);
    c_ratio->z = ft_ratio(c_distance.z, max_distance);

    return (*c_ratio);
}
