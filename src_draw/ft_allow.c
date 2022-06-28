#include <ft_draw.h>

t_allow ft_allow_init(t_allow *c_allow, t_dot position_dot, t_dot next_dot)
{
    c_allow->x = -ft_sign(position_dot.x - next_dot.x);
    c_allow->y = -ft_sign(position_dot.y - next_dot.y);
    c_allow->z = -ft_sign(position_dot.z - next_dot.z);
	
	return (*c_allow);
}