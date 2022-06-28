
#ifndef MLX_TYPE_H
# define MLX_TYPE_H

#define WIN_WIDTH   1000
#define WIN_HEIGHT  700


#include <ft_dot.h>


typedef struct s_mouse
{
	int	mouse_keycode;

	int x;
	int y;

	int draw_x;
	int draw_y;
}	t_mouse;

typedef	struct s_param
{
	void	*mlx_ptr;
	void	*win_ptr;
	
	t_dot	*head_dot;
	t_mouse	mouse;
	t_xyz	xyz;

	int zoom;
} t_param;

# endif