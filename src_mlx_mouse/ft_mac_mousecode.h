

#ifndef FT_MAC_MOUSECODE_H
# define FT_MAC_MOUSECODE_H

#include <mlx_type.h>
#include <mac_mousecode.h>

/* ft_mouse_event_down.c */
int mouse_event_down(int keycode, int x, int y, t_param *param);

/* ft_mouse_event_up.c */
int mouse_event_up(int keycode, int x, int y, t_param *param);

/* ft_mouse_event_draw.c */
int mouse_event_draw(int x, int y, t_param *param);


#endif