
#define NOT_USE 0     // 안씀

#include <mlx.h>
#include <mlx_type.h>

#include <stdio.h>

#include <ft_dot.h>
#include "src_dot/ft_dot.c"
#include "src_dot/ft_dot_add.c"

#include <get_next_line.h>
#include "src_get_next_line/get_next_line.c"

#include <ft_mac_keyboard.h>
#include "src_mlx_keyboard/ft_mac_keyboard.c"

#include <ft_mac_mousecode.h>
#include "src_mlx_mouse/ft_mac_mouse.c"
#include "src_mlx_mouse/ft_mouse_event_down.c"
#include "src_mlx_mouse/ft_mouse_event_up.c"
#include "src_mlx_mouse/ft_mouse_event_draw.c"

#include <ft_readfile.h>
#include "src_read_file/ft_readfile.c"
#include "src_read_file/ft_oneline.c"

/*
#include <ft_draw.h>
#include "src_draw/ft_draw_color.c"
#include "src_draw/ft_draw_dot.c"
#include "src_draw/ft_draw.c"
#include "src_draw/ft_ratio.c"
#include "src_draw/ft_allow.c"
#include "src_mlx_loop/ft_loop_event.c"
*/

t_param	*param_init(t_param **param_ptr, t_dot_header *head_dot_ptr)
{
	t_param *param;

	*param_ptr = (t_param *)malloc(sizeof(t_param));
	if (!*param_ptr)
		return (NULL);
	param = *param_ptr;

	ft_memset(param, 0, sizeof(t_param));
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr , WIN_WIDTH, WIN_HEIGHT, "Hello, World!");

	param->head_dot = head_dot_ptr->head_dot;

	param->zoom = 10;

	return (param);
}

int main(int ac, char **av)
{
	t_param *param;
    t_dot_header   *header_dot;
	

	printf("ss");
	if (!dot_init(&header_dot, readfile("test.fdf")))
		return (-1);
	printf("ss");
	if (!param_init(&param, header_dot))
		return (-1);
	printf("ss");

    t_dot   *head_dot;
    t_dot   *tmp_dot;
    t_dot   *free_dot;
	head_dot = header_dot->head_dot;
	while (head_dot)
	{
		tmp_dot = head_dot;
		head_dot = head_dot->y_p;
		while (tmp_dot)
		{
			free_dot = tmp_dot;
			printf("%.0f\t", tmp_dot->value);
			tmp_dot = tmp_dot->x_p;
			free(free_dot);
		}
		printf("\n");
	}

	system("leaks out");
	return (0);
/*
	if (!head_dot)
		return (-1);
	param = (t_param *)malloc(sizeof(t_param));
	
	mlx_key_hook(param->win_ptr, &key_press, param);
	mlx_loop_hook(param->mlx_ptr, &ft_loop_event, param);
*/
/*
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	printf("===== key setting ====\n");
	mlx_key_hook(param->win_ptr, &key_press, param);
	mlx_mouse_hook(param->win_ptr, &mouse_event_down, param);
	mlx_hook(param->win_ptr, 5, NOT_USE, &mouse_event_up, param);
	mlx_hook(param->win_ptr, 6, NOT_USE, &mouse_event_draw, param);
	
	mlx_expose_hook(param->win_ptr, &expose_win, param);

	printf("===== draw setting ===\n");

	printf("===== draw setting ===\n");
	ft_draw_dot_auto(param, head_dot);

	printf("===== loop setting ===\n");
	mlx_loop_hook(param->mlx_ptr, &ft_loop_event, param);
*/
	mlx_loop(param->win_ptr);
	return (0);
}

