#include <ft_canvas.h>

float    ft_ratio_max(t_xyz *c_distance, t_line c_line)
{
    float max_distance;

    max_distance = 0;
    c_distance->x = ft_abs(c_line.dot1.x - c_line.dot2.x);
    c_distance->y = ft_abs(c_line.dot1.y - c_line.dot2.y);
    c_distance->z = ft_abs(c_line.dot1.z - c_line.dot2.z);
    max_distance = c_distance->x;
    if (max_distance < c_distance->y)
        max_distance = c_distance->y;
    if (max_distance < c_distance->z)
        max_distance = c_distance->z;
    return (max_distance);
}

t_xyz    ft_ratio_init(t_xyz *c_ratio, t_line c_line)
{
    float max_distance;
    t_xyz c_distance;
    
    max_distance = ft_ratio_max(&c_distance, c_line);
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

t_xyz ft_allow_init(t_xyz *c_allow, t_line c_line)
{
    c_allow->x = -ft_sign(c_line.dot1.x - c_line.dot2.x);
    c_allow->y = -ft_sign(c_line.dot1.y - c_line.dot2.y);
    c_allow->z = -ft_sign(c_line.dot1.z - c_line.dot2.z);
	return (*c_allow);
}
