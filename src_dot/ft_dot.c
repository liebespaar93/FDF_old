#include <ft_dot.h>

t_dot	*ft_make_dot_while(t_oneline *head_oneline, t_xyz *position)
{
    t_dot   *head_dot;
    int     *layer_1D;
	int		x_len;
	int		y_len;

	head_dot = NULL;
	y_len = 0;
	x_len = 0;
	while (head_oneline)
	{
		layer_1D = ft_make_layer_1D(head_oneline, &x_len);
		head_dot = ft_dot_make_line(head_dot, *position, layer_1D, x_len);
		free(layer_1D);
		head_oneline = head_oneline->next;
		position->y++;
		y_len++;
	}
	while (--y_len && head_dot)
		head_dot = head_dot->y_m;
	return (head_dot);
}

t_dot *makedot(char *file_name)
{
    t_dot   *head_dot;
    t_oneline   *head_oneline;
	t_xyz	position;
    int     *layer_1D;
	
	ft_memset(&position, 0, sizeof(position));
    head_oneline = readfile(file_name);
	head_dot = NULL;
	if (!head_oneline)
		return (NULL);
	head_dot = ft_make_dot_while(head_oneline, &position);
	ft_free_oneline(&head_oneline);
	return (head_dot);
}
