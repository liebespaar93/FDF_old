#include <ft_dot.h>

t_dot *makedot(char *file_name)
{
    t_dot   *head_dot;
    t_oneline   *head_oneline;
	t_xyz	position;
    int     *layer_1D;
	int		x_len;
	
	ft_memset(&position, 0, sizeof(position));
    head_oneline = readfile(file_name);
    if (!head_oneline)
        return (NULL);

	head_dot = NULL;
	while (head_oneline)
	{
		layer_1D = ft_make_layer_1D(head_oneline, &x_len);
		head_dot = ft_dot_make_line(head_dot, position, layer_1D, x_len);
		head_oneline = head_oneline->next;
		position.y++;
	}
	while (--position.y)
		head_dot = head_dot->y_p;
	return (head_dot);
}
