#include <ft_mac_mousecode.h>

int mouse_event_draw(int x, int y, t_param *param)
{             
	printf("DRAW_");
	printf("key_code : \n");
	printf("%d %d %p\n", x, y, param);
    return (0);
}