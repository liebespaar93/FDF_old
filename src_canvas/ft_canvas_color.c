#include <ft_canvas.h>

t_color ft_color_red(int num, t_color *c_color_ptr)
{
    t_color c_color;

    c_color.num = 0x0000FF00;
    if (num <= 0xFF)
        c_color.s_bit.r = num;
    else if (0 < num)
    {
        c_color.s_bit.r = 0xFF;
        num -= 0xFF;
    }
    if (num <= 0xFF)
        c_color.s_bit.g -= num;
    else if (0 < num)
    {
        c_color.s_bit.g = 0x00;
        num -= 0xFF;
    }
    if (num <= 0xFF)
    {
        c_color.s_bit.b = num;
        c_color.s_bit.g = num;
    }
    else if (0 < num)
    {
        c_color.s_bit.b = 0xFF;
        c_color.s_bit.g = 0xFF;
    }
    *c_color_ptr = c_color;
    return (c_color);
}

t_color ft_color_blue(int num, t_color *c_color_ptr)
{
    t_color c_color;

    c_color.num = 0x0000FF00;
    if (num <= 0xFF)
        c_color.s_bit.b = num;
    else if (0 < num)
    {
        c_color.s_bit.b = 0xFF;
        num -= 0xFF;
    }
    if (num <= 0xFF)
        c_color.s_bit.g -= num;
    else if (0 < num)
    {
        c_color.s_bit.g = 0x00;
        num -= 0xFF;
    }
    if (num <= 0xFF)
        c_color.s_bit.b -= num;
    else if (0 < num)
        c_color.s_bit.b = 0x00;
    *c_color_ptr = c_color;
    return (c_color);
}

t_color ft_canvas_color(int num)
{
    t_color c_color;
    int     flag;

    flag = 1;
    c_color.num = 0x0000FF00;
    if (num > 0)
        ft_color_red(num, &c_color);
    else
        ft_color_blue(-num, &c_color);
    return (c_color);
}
