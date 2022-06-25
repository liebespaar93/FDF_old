
#ifndef FT_LAYER_H
# define FT_LAYER_H

#include <stdlib.h>
#include <ft_oneline.h>

typedef	struct s_layer_len
{
  int   x;
  int   y;
} t_layer_len;

/* ft_layer */
int **ft_make_layer(char *file_name);

/* ft_layer_1D */
int ft_int_layer_x_len(t_oneline *head_oneline);
int *ft_make_layer_1D(t_oneline *head_oneline, int *x_len);

/* ft_layer_2D */
int ft_int_layer_y_len(t_oneline *head_oneline);
int **ft_make_layer_2D(t_oneline *head_oneline);
void ft_print_layer_2D(int **layer_2D, t_layer_len c_layer_len);

#endif