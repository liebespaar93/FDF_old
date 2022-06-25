#include <ft_dot.h>

t_dot *ft_new_dot(int value, t_xyz *position)
{
    t_dot *new_dot;

    new_dot = (t_dot *)malloc(sizeof(t_dot));
    if (!new_dot)
        return (NULL);
    ft_memset(new_dot, 0, sizeof(t_dot));
    new_dot->x = position->x++;
    new_dot->y = position->y;
    new_dot->z = value;
    return (new_dot);
}