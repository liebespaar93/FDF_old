#include <ft_param.h>

t_param	*ft_param_init(t_param **param_ptr, t_dot_header *head_dot_ptr)
{
	t_param *param;

	*param_ptr = (t_param *)malloc(sizeof(t_param));
	if (!*param_ptr)
		return (NULL);
	param = *param_ptr;
	ft_memset(param, 0, sizeof(t_param));
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr , WIN_WIDTH, WIN_HEIGHT, "FDF for kyoulee");
	param->head_dot = head_dot_ptr;
	param->zoom = 10;
	param->contour_line = 255 * 3 / head_dot_ptr->max_len_z;
	
	return (param);
}