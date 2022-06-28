
#include <ft_loop_event.h>

int	ft_loop_event(t_param *param)
{
	ft_draw_dot_auto(param, param->head_dot);
	return (0);
}

int expose_win(t_param *param)
{
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	ft_draw_dot_auto(param, param->head_dot);
	return (0);
}