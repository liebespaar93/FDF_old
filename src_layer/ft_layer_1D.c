#include <ft_layer.h>

int ft_int_layer_x_len(t_oneline *head_oneline)
{
    int     x_len;
    int     flag;
    char    *str;

    x_len = 0;
    flag = 1;
    str = head_oneline->data;
    while (*str)
    {
        if ((0x09 <= *str && *str <= 0x0D) || *str == 0x20)
            flag = 1;
        else if ((0x30 <= *str && *str <= 0x39) || *str == '-' || *str == '+')
        {
            if (flag && flag--)
                x_len++;
        }
        else 
            return (0);
        str++;
    }
    return (x_len);
}

int *ft_make_layer_1D(t_oneline *head_oneline, int *x_len)
{
    int     *layer_1D;
    int     index;
    char    *str;

    index = 0;
    str = head_oneline->data;
    *x_len = ft_int_layer_x_len(head_oneline);
    layer_1D = (int *)malloc(sizeof(int) * (*x_len));
    if (!layer_1D)
        return (NULL);
    while (*str)
        layer_1D[index++] = ft_atoi_move(&str);
    return (layer_1D);
}