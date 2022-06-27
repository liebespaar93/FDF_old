
#ifndef MLX_TYPE_H
# define MLX_TYPE_H

#define WIN_WIDTH   500
#define WIN_HEIGHT  500

#define ZOOM 1
#define LINE_SIZE 30
#define SKETCH_START_Y 10
typedef struct s_mouse
{
	int	mouse_keycode;

	int x;				// x값
	int y;				// y값

	int draw_x;			// x값
	int draw_y;			// y값
}	t_mouse;

typedef	struct s_param
{
  void	*mlx_ptr;
  void	*win_ptr;

	t_mouse	mouse;

	int x;
	int y;
	int z;
} t_param;

# endif