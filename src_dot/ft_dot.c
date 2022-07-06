#include <ft_dot.h>
#include <ft_readfile.h>

t_dot_header *ft_dot_init(t_dot_header **head_dot_ptr, t_oneline *head_oneline)
{
	t_xyz			position;

	*head_dot_ptr = NULL;
	ft_dot_connect(head_dot_ptr, head_oneline);
	ft_free_oneline(&head_oneline);
	return (*head_dot_ptr);
}

t_dot_header	*ft_dot_free(t_dot_header **head_dot_ptr)
{
	t_dot	*dot_x;
	t_dot	*dot_y;
	t_dot	*dot_z;
	t_dot	*free_dot;
	
	dot_z = (*head_dot_ptr)->dot;
	while (dot_z)
	{
		dot_y = dot_z;
		dot_z = dot_z->z_p;
		while (dot_y)
		{
			dot_x = dot_y;
			dot_y = dot_y->y_p;
			while(dot_x)
			{
				free_dot = dot_x;
				dot_x = dot_x->x_p;
				free(free_dot);
			}
		}
	}
	free(*head_dot_ptr);
	*head_dot_ptr = NULL;
	return (*head_dot_ptr);
}