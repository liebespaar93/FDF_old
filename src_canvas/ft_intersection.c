#include <ft_canvas.h>

t_line *ft_intersectionpoint_canvar(t_dot dot1, t_dot dot2, t_line *c_line_ptr)
{
	t_line	c_line;

	if (dot1.y <= CANVAS_Y && dot2.x - dot1.x)
		c_line.dot1.x = (dot1.x - dot2.x) / (dot1.y - dot2.y) * (CANVAS_Y - dot1.y) + dot1.x;
	else if (CANVAS_HEIGHT <= dot1.y && dot2.x - dot1.x)
		c_line.dot1.x = (dot1.x - dot2.x) / (dot1.y - dot2.y) * (CANVAS_HEIGHT - dot1.y) + dot1.x;
	else
		c_line.dot1.x = ft_max_f(CANVAS_X, ft_min_f(dot1.x, CANVAS_WIDTH));

	if (dot2.y <= CANVAS_Y && dot2.x - dot1.x)
		c_line.dot2.x = (dot2.x - dot1.x) / (dot2.y - dot1.y) * (CANVAS_Y - dot2.y) + dot2.x;
	else if (CANVAS_HEIGHT <= dot2.y && dot2.x - dot1.x)
		c_line.dot2.x = (dot2.x - dot1.x) / (dot2.y - dot1.y) * (CANVAS_HEIGHT - dot2.y) + dot2.x;
	else
		c_line.dot2.x = ft_max_f(CANVAS_X, ft_min_f(dot2.x, CANVAS_WIDTH));

	if (dot1.x <= CANVAS_X && dot2.y - dot1.y)
		c_line.dot1.y = (dot1.y - dot2.y) / (dot1.x - dot2.x) * (CANVAS_X - dot1.x) + dot1.y;
	else if (CANVAS_WIDTH <= dot1.x && dot2.y - dot1.y)
		c_line.dot1.y = (dot1.y - dot2.y) / (dot1.x - dot2.x) * (CANVAS_WIDTH - dot1.x) + dot1.y;
	else
		c_line.dot1.y = ft_max_f(CANVAS_Y, ft_min_f(dot1.y , CANVAS_HEIGHT));

	if (dot2.x <= CANVAS_X && dot2.y - dot1.y)
		c_line.dot2.y = (dot2.y - dot1.y) / (dot2.x - dot1.x) * (CANVAS_X - dot2.x) + dot2.y;
	else if (CANVAS_WIDTH <= dot2.x && dot2.y - dot1.y)
		c_line.dot2.y = (dot2.y - dot1.y) / (dot2.x - dot1.x) * (CANVAS_WIDTH - dot2.x) + dot2.y;
	else
		c_line.dot2.y = ft_max_f(CANVAS_Y, ft_min_f(dot2.y , CANVAS_HEIGHT));
		
	*c_line_ptr = c_line;
	return (c_line_ptr);
}
