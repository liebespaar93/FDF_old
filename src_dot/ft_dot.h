
#ifndef FT_DOT_H
# define FT_DOT_H

#include <stdlib.h>
#include <ft_readfile.h>
#include <libft.h>
#include <ft_layer.h>

typedef	struct s_xyz
{
  float   x;
  float   y;
  float   z;
} t_xyz;

typedef	struct s_dot
{
  float   x;
  float   y;
  float   z;

  struct s_dot  *x_p;
  struct s_dot  *x_m;
  struct s_dot  *y_p;
  struct s_dot  *y_m;
  struct s_dot  *z_p;
  struct s_dot  *z_m;

  void  *zoom_up;
  void  *zoom_down;
} t_dot;

/* ft_dot */
t_dot *makedot(char *file_name);

/* ft_dot_make_line */
t_dot *ft_dot_make_line(t_dot *dot_ptr, t_xyz position, int *layer_1D, int x_len);

/* ft_dot_new */
t_dot *ft_new_dot(int value, t_xyz *position);

/* ft_dot_add */
t_dot *ft_dot_add_x(t_dot **dot_ptr, t_dot *new_dot, int sign);
t_dot *ft_dot_add_y(t_dot **dot_ptr, t_dot *new_dot, int sign);
t_dot *ft_dot_add_z(t_dot **dot_ptr, t_dot *new_dot, int sign);

#endif