#include <ft_mac_mousecode.h>

int mouse_event_up(int keycode, int x, int y, t_param *param)
{             
	printf("UP_");
    if (keycode == MOUSE_LEFT_BUTTON) 
        printf("MOUSE_LEFT_BUTTON\n");
    else if (keycode == MOUSE_RIGHT_BUTTON)
        printf("MOUSE_RIGHT_BUTTON\n");
    else if (keycode == MOUSE_SCROLL_BUTTON)
        printf("MOUSE_SCROLL_BUTTON\n");
    else if (keycode == MOUSE_SCROLL_UP) // 아마 이건 작동 안할듯??
        printf("MOUSE_SCROLL_UP\n");
    else if (keycode == MOUSE_SCROLL_DOWN) // 아마 이건 작동안할듯??
        printf("MOUSE_SCROLL_DOWN\n");
	printf("%d %d %d\n", x, y, param->z);
    return (0);
}