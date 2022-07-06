
#ifndef FT_DOT_H
# define FT_DOT_H

#include <stdlib.h>
#include <ft_readfile.h>

typedef	struct s_dot
{
  char    life;
  float   x;
  float   y;
  float   z;
  void    *data;

  struct s_dot  *x_p;
  struct s_dot  *x_m;
  struct s_dot  *y_p;
  struct s_dot  *y_m;
  struct s_dot  *z_p;
  struct s_dot  *z_m;
} t_dot;

typedef struct s_dot_header
{
  t_dot *dot;

  int max_len_x;
  int max_len_y;
  int max_len_z;
} t_dot_header;



/* ft_dot.c */
t_dot_header *ft_dot_init(t_dot_header **head_dot_ptr, t_oneline *head_oneline);
t_dot_header	*ft_dot_free(t_dot_header **head_dot_ptr);

/* ft_dot_connect.c */
t_dot *ft_new_dot(void *value, t_xyz position);
t_dot *ft_dot_init_1D(t_dot_header *head_dot_ptr, t_dot *line_dot, t_xyz position, t_oneline *head_oneline);
t_dot	*ft_dot_init_2D(t_dot_header *head_dot_ptr, t_oneline *head_oneline, t_xyz	position);
t_dot_header *ft_dot_connect(t_dot_header **head_dot_ptr, t_oneline *head_oneline);

/* ft_dot_add.c */
t_dot *ft_dot_add_x(t_dot **dot_ptr, t_dot *new_dot, int sign);
t_dot *ft_dot_add_y(t_dot **dot_ptr, t_dot *new_dot, int sign);
t_dot *ft_dot_add_z(t_dot **dot_ptr, t_dot *new_dot, int sign);

#endif