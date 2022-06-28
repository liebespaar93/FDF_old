#include <ft_mac_keyboard.h>
#include <ft_draw.h>

int ft_keyboard_zoom(int keycode, t_param *param)
{
	if (keycode == KEY_PLUS || keycode == KEY_P_PLUS)
	{
		param->zoom++;
		return (1);
	}
	else if (keycode == KEY_MINUS || keycode == KEY_P_MINUS)
	{
		return (1);
	}
	return (0);
}

int ft_keyboard_move(int keycode, t_param *param)
{
	if (keycode == KEY_ARROW_U || keycode == KEY_W)
	{
		param->xyz.y++;
		return (1);
	}
	if (keycode == KEY_ARROW_D || keycode == KEY_S)
	{
		param->xyz.y--;
		return (1);
	}
	if (keycode == KEY_ARROW_R || keycode == KEY_D)
	{
		param->xyz.x++;
		return (1);
	}
	if (keycode == KEY_ARROW_L || keycode == KEY_A)
	{
		param->xyz.x--;
		return (1);
	}
	return (0);
}
/*
int	key_map_change(int keycode, t_param *param)
{
	if (keycode == KEY_R_A_BRAKET)
	{
		ft_map_next();
	}
	if (keycode == KEY_L_A_BRAKET)
	{
		ft_map_pres();
	}
}
*/
int key_press(int keycode, t_param *param)
{
	if (ft_keyboard_zoom(keycode, param))
		return (0);
	if (ft_keyboard_move(keycode, param))
		return (0);
	else if (keycode == KEY_ESC)
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	return (0);
}
