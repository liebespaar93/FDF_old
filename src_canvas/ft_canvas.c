#include <ft_canvas.h>
#include <stdio.h>
t_dot   ft_symtax_pixel(t_param param, t_dot dot)
{
    dot.x *= param.zoom;
    dot.y *= param.zoom;
    dot.z *= param.zoom;
    dot.x += param.xyz.x + CANVAS_X;
    dot.y += param.xyz.y + CANVAS_Y;
    /* 회전  */
    // x 
    dot.y = ft_cos(param.angle.x) * dot.y - ft_sin(param.angle.x) * dot.z;
    dot.z = ft_sin(param.angle.x) * dot.y + ft_cos(param.angle.x) * dot.z;
    // y
    dot.x = ft_cos(param.angle.y) * dot.x + ft_sin(param.angle.y) * dot.z;
    dot.z = -ft_sin(param.angle.y) * dot.x + ft_cos(param.angle.y) * dot.z;
    // z
    dot.x = ft_cos(param.angle.z) * dot.x - ft_sin(param.angle.z) * dot.y;
    dot.y = ft_sin(param.angle.z) * dot.x + ft_cos(param.angle.z) * dot.y;
    return (dot);
}

void	ft_canvas_line(t_param *param)
{
    t_dot   tmp_dot;
    t_dot   head_dot;
    
    if (!param->head_dot->dot)
        return ;
    head_dot = *(param->head_dot->dot);
    while (head_dot.life)
    {
        tmp_dot = head_dot;
        while (tmp_dot.life)
        {
			tmp_dot = ft_symtax_pixel(*param, tmp_dot);
            if (tmp_dot.x_p)
                ft_sketch_line(param, tmp_dot, ft_symtax_pixel(*param, *tmp_dot.x_p));
            if (tmp_dot.y_p)
                ft_sketch_line(param, tmp_dot, ft_symtax_pixel(*param, *tmp_dot.y_p));
            if (tmp_dot.x_m)
                ft_sketch_line(param, tmp_dot, ft_symtax_pixel(*param, *tmp_dot.x_m));
            if (tmp_dot.y_m)
                ft_sketch_line(param, tmp_dot, ft_symtax_pixel(*param, *tmp_dot.y_m));
            if (!tmp_dot.x_p)
                break;
            tmp_dot = *tmp_dot.x_p;
        }
        if (!head_dot.y_p)
            break;
        head_dot = *head_dot.y_p;
    }
}

char *ft_canvas (t_param *param)
{
	ft_canvas_line(param);
	return (param->img_info.buffer);
}