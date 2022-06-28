#include <ft_draw.h>
#include <stdio.h>

t_dot   ft_symtax_pixel(t_param *param, t_dot dot)
{
	mlx_clear_window(param->mlx_ptr, param->win_ptr); 
    dot.x *= param->zoom;
    dot.y *= param->zoom;
    dot.x = (dot.x - dot.y) * ft_cos(0.8);
    dot.y = (dot.x + dot.y) * ft_sin(0.8) - dot.z * 2;
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
                ft_auto_line_draw(param, ft_symtax_pixel(param, *tmp_dot), ft_symtax_pixel(param, *(tmp_dot->x_p)));
            if (tmp_dot->y_p)
                ft_auto_line_draw(param, ft_symtax_pixel(param, *tmp_dot), ft_symtax_pixel(param, *(tmp_dot->y_p)));
            if (tmp_dot->x_m)
                ft_auto_line_draw(param, ft_symtax_pixel(param, *tmp_dot), ft_symtax_pixel(param, *(tmp_dot->x_m)));
            if (tmp_dot->y_m)
                ft_auto_line_draw(param, ft_symtax_pixel(param, *tmp_dot), ft_symtax_pixel(param, *(tmp_dot->y_m)));
            tmp_dot = tmp_dot->x_p;
        }
        head_dot = head_dot->y_p;
    }
}