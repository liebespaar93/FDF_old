#include <ft_dot.h>

t_dot *ft_dot_make_line(t_dot *dot_ptr, t_xyz position, int *layer_1D, int x_len)
{
	t_dot	*new_dot_ptr;
	int	index;

	index = 0;
	new_dot_ptr = NULL;
	if (!dot_ptr)
		while (index++ < x_len)
			new_dot_ptr = ft_dot_add_x(&new_dot_ptr, ft_new_dot(*layer_1D++, &position), 1);
	else
	{
		while (index++ < x_len)
		{
			new_dot_ptr = ft_dot_add_x(&new_dot_ptr, ft_new_dot(*layer_1D++, &position), 1);
			ft_dot_add_y(&dot_ptr, new_dot_ptr, -1);
			dot_ptr = dot_ptr->x_p;
		}
	}
	while (--index && new_dot_ptr->x_m)
		new_dot_ptr = new_dot_ptr->x_m;
	return (new_dot_ptr);
}