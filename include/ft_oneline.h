
#ifndef FT_ONELINE_H
# define FT_ONELINE_H

#include <stdlib.h>

typedef struct  s_oneline
{
  char    *data;
  size_t  data_size;
  void    *next;
} t_oneline;


/* ft_oneline */
t_oneline	*ft_new_oneline(char const *data);
t_oneline	*ft_oneline_add(t_oneline **oneline_ptr, char const *data);

#endif