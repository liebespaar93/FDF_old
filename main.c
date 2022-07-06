#include <mlx.h>

#include "src_dot/ft_dot.c"
#include "src_dot/ft_dot_connect.c"
#include "src_dot/ft_dot_add.c"

#include "src_readfile/ft_readfile.c"
#include "src_readfile/ft_oneline.c"
#include "modules/get_next_line/get_next_line.c"

#include "src_mlx_keyboard/ft_mac_keyboard.c"
#include "src_mlx_keyboard/ft_mac_key_up.c"
#include "src_mlx_keyboard/ft_mac_key_down.c"
#include "src_mlx_keyboard/ft_mac_key_hold.c"

#include "src_mlx_mouse/ft_mouse_up.c"
#include "src_mlx_mouse/ft_mouse_down.c"
#include "src_mlx_mouse/ft_mouse_drag.c"

#include "src_canvas/ft_canvas.c"
#include "src_canvas/ft_canvas_color.c"
#include "src_canvas/ft_intersection.c"
#include "src_canvas/ft_ratio.c"
#include "src_canvas/ft_sketch_line.c"

#include "src_loop/ft_loop_event.c"

#include "src_param/ft_param.c"

#include <math.h>
#include <stdio.h>
int main(int ac, char **av)
{
	t_param			*param;
    t_dot_header	*header_dot;

	if (!ft_dot_init(&header_dot, readfile("test2.fdf")))
		return (-1);
	//if (!ft_dot_init(&header_dot, readfile("test.fdf")))
	// 	return (-1);
	param = ft_param_init( &param, header_dot);
	param->img_ptr = mlx_new_image(param->mlx_ptr, CANVAS_WIDTH, CANVAS_HEIGHT);
	param->img_info.buffer = mlx_get_data_addr(param->img_ptr, &param->img_info.bits_per_pixel, &param->img_info.size_line, &param->img_info.endian);
	ft_canvas(param);
	/* keyboard set */
	mlx_hook(param->win_ptr, 2, 0, key_down, param);
	mlx_key_hook(param->win_ptr, key_up, param);
	/* mouse set */
	mlx_mouse_hook(param->win_ptr, ft_mouse_down, param);
	mlx_hook(param->win_ptr, 5, 0, ft_mouse_up, param);
	mlx_hook(param->win_ptr, 6, 0, ft_mouse_drag, param);

	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr ,CANVAS_X,CANVAS_Y);
	mlx_loop_hook(param->mlx_ptr, ft_loop_event, param);
	mlx_loop(param->mlx_ptr);

	return (0);
}

