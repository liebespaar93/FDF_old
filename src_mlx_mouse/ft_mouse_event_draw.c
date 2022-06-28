#include <ft_mac_mousecode.h>

int mouse_event_draw(int x, int y, t_param *param)
{
	param->xyz.x += x - param->mouse.draw_x;
	param->xyz.y += y - param->mouse.draw_y;
	param->mouse.draw_x = x;
	param->mouse.draw_y = y;

	printf("DRAW_");
	printf("key_code : \n");
	printf("%d %d %p\n", x, y, param);
	printf("parm -> %f %f\n", param->xyz.x, param->xyz.y);
    return (0);
}