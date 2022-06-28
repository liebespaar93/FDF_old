
#include <ft_mac_mousecode.h>

int mouse_event_down(int keycode, int x, int y, t_param *param)
{             
	printf("DOWN_");
    if (keycode == MOUSE_LEFT_BUTTON) 
    {
	    param->mouse.draw_x = x;
	    param->mouse.draw_y = y;
        printf("MOUSE_LEFT_BUTTON\n");
    }
    else if (keycode == MOUSE_RIGHT_BUTTON)
        printf("MOUSE_RIGHT_BUTTON\n");
    else if (keycode == MOUSE_SCROLL_BUTTON)
        printf("MOUSE_SCROLL_BUTTON\n");
    else if (keycode == MOUSE_SCROLL_UP)
	{
        printf("MOUSE_SCROLL_UP\n");
		param->xyz.z++;
	}
    else if (keycode == MOUSE_SCROLL_DOWN)
	{
        printf("MOUSE_SCROLL_DOWN\n");
		param->xyz.z--;
	}
	printf("%d %d %f\n", x, y, param->xyz.z);
    return (0);
}