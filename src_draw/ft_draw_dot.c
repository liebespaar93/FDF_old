#include <ft_draw.h>
#include <stdio.h>
#define COLOR_RATIO 5;
t_dot   ft_symtax_pixel(t_dot dot)
{
    dot.x *= LINE_SIZE;
    dot.y *= LINE_SIZE;
    dot.z *= COLOR_RATIO;
    return (dot);
}

void ft_draw_dot_auto(t_param *param, t_dot *head_dot)
{
    t_dot   *tmp_dot;

    while (head_dot)
    {
        tmp_dot = head_dot;
        while (tmp_dot)
        {
            if (tmp_dot->x_p)
                ft_auto_line_draw(param, ft_symtax_pixel(*tmp_dot), ft_symtax_pixel(*(tmp_dot->x_p)));
            if (tmp_dot->y_p)
                ft_auto_line_draw(param, ft_symtax_pixel(*tmp_dot), ft_symtax_pixel(*(tmp_dot->y_p)));
            tmp_dot = tmp_dot->x_p;
        }
        head_dot = head_dot->y_p;
    }
}