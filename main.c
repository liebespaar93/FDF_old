
#define NOT_USE 0     // 안씀

#include <mlx.h>
#include <mlx_type.h>

#include <stdio.h>

#include <ft_dot.h>
#include "src_dot/ft_dot.c"
#include "src_dot/ft_dot_add.c"
#include "src_dot/ft_dot_make_line.c"
#include "src_dot/ft_dot_new.c"

#include <get_next_line.h>
#include "src_get_next_line/get_next_line.c"

#include <ft_layer.h>
#include "src_layer/ft_layer_1D.c"
#include "src_layer/ft_layer_2D.c"
#include "src_layer/ft_layer.c"

#include <ft_mac_keyboard.h>
#include "src_mlx_keyboard/ft_mac_keyboard.c"

#include <ft_mac_mousecode.h>
#include "src_mlx_mouse/ft_mac_mouse.c"
#include "src_mlx_mouse/ft_mouse_event_down.c"
#include "src_mlx_mouse/ft_mouse_event_up.c"
#include "src_mlx_mouse/ft_mouse_event_draw.c"

#include <ft_readfile.h>
#include "src_read_file/ft_readfile.c"
#include <ft_oneline.h>
#include "src_read_file/ft_oneline.c"

#include <ft_draw.h>
#include "src_draw/ft_draw_color.c"
#include "src_draw/ft_draw_dot.c"
#include "src_draw/ft_draw.c"
#include "src_draw/ft_ratio_init.c"

int main(int ac, char **av)
{
	t_param *param;
    t_dot   *head_dot;
	
	head_dot = makedot("test.fdf");
	if (!head_dot)
		return (-1);
    t_dot   *tmp_dot;

	param = (t_param *)malloc(sizeof(t_param));
	if (!param)
		return (-1);
	ft_memset(param, 0, sizeof(t_param));
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr , WIN_WIDTH, WIN_HEIGHT, "Hello, World!");

	mlx_clear_window(param->mlx_ptr, param->win_ptr);

	printf("===== key setting ====\n");
	mlx_key_hook(param->win_ptr, &key_press, param);
	mlx_mouse_hook(param->win_ptr, &mouse_event_down, param);
	mlx_hook(param->win_ptr, 5, NOT_USE, &mouse_event_up, param);
	mlx_hook(param->win_ptr, 6, NOT_USE, &mouse_event_draw, param);
	
	printf("===== draw setting ===\n");
	ft_draw_dot_auto(param, head_dot);
	mlx_loop(param->win_ptr);
	return (0);
}

