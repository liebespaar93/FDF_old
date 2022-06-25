
#include <ft_mac_mousecode.h>

int mouse_event_down(int keycode, int x, int y, t_param *param)
{             
	printf("DOWN_");
    if (keycode == MOUSE_LEFT_BUTTON) 
        printf("MOUSE_LEFT_BUTTON\n");
    else if (keycode == MOUSE_RIGHT_BUTTON)
        printf("MOUSE_RIGHT_BUTTON\n");
    else if (keycode == MOUSE_SCROLL_BUTTON)
        printf("MOUSE_SCROLL_BUTTON\n");
    else if (keycode == MOUSE_SCROLL_UP)
	{
        printf("MOUSE_SCROLL_UP\n");
		param->z++;
	}
    else if (keycode == MOUSE_SCROLL_DOWN)
	{
        printf("MOUSE_SCROLL_DOWN\n");
		param->z--;
	}
	printf("%d %d %d\n", x, y, param->z);
    return (0);
}