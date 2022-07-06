#include <ft_dot.h>

t_dot *ft_new_dot(void *data, t_xyz position)
{
    t_dot *new_dot;

    new_dot = (t_dot *)malloc(sizeof(t_dot));
    if (!new_dot)
        return (NULL);
    ft_memset(new_dot, 0, sizeof(t_dot));
	new_dot->life = 1;
    new_dot->x = position.x;
    new_dot->y = position.y;
    new_dot->z = position.z;
	new_dot->data = data;
    return (new_dot);
}

t_dot *ft_dot_init_1D(t_dot_header *head_dot_ptr, t_dot *line_dot, t_xyz position, t_oneline *head_oneline)
{
	t_dot	*head_dot;
	t_dot	*new_dot;
	char	*str;
	int		len;
	
	new_dot = NULL;
	head_dot = NULL;
	str = head_oneline->data;
	len = ft_atoi_len(str);
	if (head_dot_ptr->max_len_x < len)
		head_dot_ptr->max_len_x = len;
	while (len--)
	{
		position.z = ft_atoi_move(&str); // for FDF
		new_dot = ft_dot_add_x(&new_dot, ft_new_dot(NULL, position), 1);
		if (!head_dot)
			head_dot = new_dot;
		if (line_dot && ft_dot_add_y(&line_dot, new_dot, 1))
			line_dot = line_dot->x_p;
		position.x++;
		if (head_dot_ptr->max_len_z < ft_abs(new_dot->z)) // for FDF
			head_dot_ptr->max_len_z = ft_abs(new_dot->z); // for FDF
	}
	return (head_dot);
}

t_dot	*ft_dot_init_2D(t_dot_header *head_dot_ptr, t_oneline *head_oneline, t_xyz	position)
{
    t_dot   *line_dot;\

	line_dot = NULL;
	while (head_oneline)
	{
		line_dot = ft_dot_init_1D(head_dot_ptr, line_dot, position, head_oneline);
		head_oneline = head_oneline->next;
		position.y++;
	}
	if (head_dot_ptr->max_len_y < position.y)
		head_dot_ptr->max_len_y = position.y;
	while (line_dot->y_m)
		line_dot = line_dot->y_m;
	return (line_dot);
}

t_dot_header *ft_dot_connect(t_dot_header **head_dot_ptr, t_oneline *head_oneline)
{
	t_dot_header	*head_dot;
	t_xyz			position;

	if (!head_oneline)
		return (NULL);
	*head_dot_ptr = (t_dot_header *)malloc(sizeof(t_dot_header));
	if (!*head_dot_ptr)
		return (NULL);
	head_dot = *head_dot_ptr;
	ft_memset(&position, 0, sizeof(t_xyz));
	head_dot->dot = ft_dot_init_2D(head_dot, head_oneline, position);
	return (head_dot);
}