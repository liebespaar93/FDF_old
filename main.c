
#define NOT_USE 0     // 안씀
#define WIN_WIDTH   500
#define WIN_HEIGHT  500

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

int main(int ac, char **av)
{
	t_param *param;
    t_dot   *head_dot;
    t_dot   *tmp_dot;
    t_dot   *free_dot;
	
	head_dot = makedot("test.fdf");
	if (!head_dot)
		return (0);
	while (head_dot)
	{
		tmp_dot = head_dot;
		head_dot = head_dot->y_m;
		while (tmp_dot)
		{
			free_dot = tmp_dot;
			printf("%d\t", tmp_dot->z);
			tmp_dot = tmp_dot->x_p;
			free(free_dot);
		}
		printf("\n");
	}
	system("leaks out");

	return 0;
}

