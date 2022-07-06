#ifndef FT_PARAM_H
# define FT_PARAM_H

#define WIN_WIDTH   1000
#define WIN_HEIGHT  1000

#include <ft_dot.h>
#include <libft.h>
#include <ft_canvas_type.h>
#include <ft_mac_mouse_type.h>
#include <ft_mac_keyboard_type.h>

typedef	struct s_param
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;

	t_img_info		img_info;
	t_dot_header	*head_dot;
	t_mouse		mouse;
	t_keyboard	keyboard;
	t_xyz	xyz;
	t_xyz	angle;
	float	zoom;
	float	contour_line;

	__int128 time;

} t_param;

/* ft_param.c */
t_param	*ft_param_init(t_param **param_ptr, t_dot_header *head_dot_ptr);

#endif