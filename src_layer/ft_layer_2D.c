#include <ft_layer.h>

int ft_int_layer_y_len(t_oneline *head_oneline)
{
    int y_len;

    y_len = 0;
    while (head_oneline)
    {
        head_oneline = head_oneline->next;
        y_len++;
    }
    return (y_len);
}

int **ft_make_layer_2D(t_oneline *head_oneline)
{
    int **layer_2D;
    int index;
    int x_len;
    int y_len;

    if (!head_oneline)
        return (NULL);
    index = 0;
    y_len = ft_int_layer_y_len(head_oneline);
    layer_2D = (int **)malloc(sizeof(int *) * (y_len));
    if (!layer_2D)
        return (NULL);
    while (head_oneline)
    {
        layer_2D[index++] = ft_make_layer_1D(head_oneline, &x_len);
        head_oneline = head_oneline->next;
    }
    return (layer_2D);
}

void ft_print_layer_2D(int **layer_2D, t_layer_len c_layer_len)
{
    int x = 0;
    int y = 0;
    while (y < c_layer_len.y)
    {
        x= 0;
        while (x < c_layer_len.x)
        {
            printf("%d\t", layer_2D[y][x]);
            x++;
        }
        printf("\n");
        y++;

    }
    printf("\n");
}