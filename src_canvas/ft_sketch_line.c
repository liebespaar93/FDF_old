#include <ft_canvas.h>
#include <stdio.h>
#include <libft.h>
void	*ft_check_sketch(t_dot position_dot, t_dot next_dot, t_line *c_line_ptr)
{
	t_line c_line;
	int	flag;

	flag = 0;
	ft_memset(&c_line, 0, sizeof(t_line));
	if (!ft_intersectionpoint_canvar(position_dot, next_dot, &c_line))
		return (NULL);
    
	*c_line_ptr = c_line;
	return (c_line_ptr);
}

int    ft_canvas_draw(t_param *param, t_xyz *dot, t_xyz c_allow, t_xyz c_ratio)
{
    t_color color;

    color = ft_canvas_color((dot->z / param->zoom * param->contour_line));


    if (CANVAS_Y < (int)(dot->y) && (int)(dot->y) < CANVAS_HEIGHT && CANVAS_X < (int)(dot->x) && (int)(dot->x) < CANVAS_WIDTH)
        *(int*)(param->img_info.buffer + param->img_info.size_line * (int)(dot->y) + (int)(dot->x) * 4) = color.num;

    dot->x += c_allow.x * c_ratio.x;
    dot->y += c_allow.y * c_ratio.y;
    dot->z += c_allow.z * c_ratio.z;
    return (1);
}

#include <stdio.h>

void    ft_sketch_line(t_param *param, t_dot position_dot, t_dot next_dot)
{
	t_line c_line;
    t_xyz c_ratio;
    t_xyz c_allow;



	if (!ft_check_sketch(position_dot, next_dot, &c_line))
		return ;
	
    ft_ratio_init(&c_ratio, c_line);
    ft_allow_init(&c_allow, c_line);
    /*
    printf("%+f %+f %+f\n" ,position_dot.x ,position_dot.y, position_dot.z );
    printf("%f %f %f\n" ,next_dot.x ,next_dot.y, next_dot.z );
    printf("%f %f %f\n" ,c_line.dot1.x ,c_line.dot1.y, c_line.dot1.z);
    printf("%f %f %f\n\n\n" ,c_line.dot2.x ,c_line.dot2.y, c_line.dot2.z);
    */
    if (c_ratio.x == 1)
    {
        while (ft_abs(c_line.dot1.x) <= ft_abs(c_line.dot2.x))
            ft_canvas_draw(param, &c_line.dot1, c_allow, c_ratio);
    }
    else if (c_ratio.y == 1)
    {
        while (ft_abs(c_line.dot1.y) <= ft_abs(c_line.dot2.y))
            ft_canvas_draw(param, &c_line.dot1, c_allow, c_ratio);
    }
    else if (c_ratio.z == 1)
    {
        while (ft_abs(c_line.dot1.z) <= ft_abs(c_line.dot2.z))
            ft_canvas_draw(param, &c_line.dot1, c_allow, c_ratio);
	}
}