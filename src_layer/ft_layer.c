#include <ft_layer.h>

int **ft_make_layer(char *file_name)
{
    t_oneline   *head_oneline;
    int     **layer_2D;
    t_layer_len c_layer_len;



    head_oneline = readfile(file_name);
    if (!head_oneline)
        return (NULL);
    c_layer_len.x = ft_int_layer_x_len(head_oneline);
    c_layer_len.y = ft_int_layer_y_len(head_oneline);
    layer_2D = ft_make_layer_2D(head_oneline);
    ft_print_layer_2D(layer_2D, c_layer_len);
    return (layer_2D);
}