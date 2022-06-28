#ifndef FT_DRAW_DOT_H
# define FT_DRAW_DOT_H


#include <stdlib.h>
#include <libft.h>
#include <ft_dot.h>
#include <mlx_type.h>
#include <mlx.h>

typedef struct s_ratio
{
    float   x;
    float   y;
    float   z;
}   t_ratio;

typedef struct s_allow
{
    float   x;
    float   y;
    float   z;
}   t_allow;


typedef union u_color
{
    int num;
    
	struct
	{
		unsigned char	b :8 ;
		unsigned char   g :8 ;
		unsigned char	r :8 ;
		unsigned char	a :8 ;
	}	s_bit;
}   t_color;


/* ft_draw_color */
int ft_draw_color(int num);

/* ft_draw_dot.c */
void ft_draw_dot_auto(t_param *param, t_dot *head_dot);

/* ft_draw.c */
void    ft_auto_pixel_put(t_param *param, t_dot head_dot, int color);
void    ft_auto_line_draw(t_param *param, t_dot position_dot, t_dot next_dot);

/* ft_ratio.c */
t_ratio    ft_ratio_init(t_ratio *c_ratio, t_dot position_dot, t_dot next_dot);

/* ft_allow.c */
t_allow ft_allow_init(t_allow *c_allow, t_dot position_dot, t_dot next_dot);

#endif