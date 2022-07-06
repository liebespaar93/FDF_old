#include <ft_loop_event.h>

int	ft_loop_event (t_param *param)
{
	ft_key_hold(param);
	/*
	void *old_canvas;
	old_canvas = param->img_ptr;
	param->img_ptr = mlx_new_image(param->mlx_ptr,CANVAS_WIDTH,CANVAS_HEIGHT);
	*/
	param->img_info.buffer = mlx_get_data_addr(param->img_ptr, &param->img_info.bits_per_pixel, &param->img_info.size_line, &param->img_info.endian);
	
	ft_memset(param->img_info.buffer, 30,  param->img_info.size_line * (CANVAS_HEIGHT));
	ft_canvas(param);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr ,CANVAS_X,CANVAS_Y);
	char *a = ft_itoa(param->time);
	write(1, a, ft_strlen(a));
	write(1, "\n", 1);
	param->time++;
	return (0);
}