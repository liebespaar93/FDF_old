
#ifndef FT_CANVAS_H
# define FT_CANVAS_H

#include <stdlib.h>
#include <ft_canvas_type.h>
#include <ft_param.h>
#include <ft_dot.h>

/* ft_canvas.c */
char	*ft_canvas (t_param *param);
void	ft_canvas_line(t_param *param);

/* ft_sketch_line.c */
void	*ft_check_sketch(t_dot position_dot, t_dot next_dot, t_line *c_line_ptr);
int		ft_canvas_draw(t_param *param, t_xyz *dot, t_xyz c_allow, t_xyz c_ratio);
void	ft_sketch_line(t_param *param, t_dot position_dot, t_dot next_dot);

/* ft_ratio.c */
t_xyz	ft_ratio_init(t_xyz *c_ratio, t_line c_line);
t_xyz	ft_allow_init(t_xyz *c_allow, t_line c_line);

/* ft_intersection.c */
t_line	*ft_intersectionpoint_canvar(t_dot dot1, t_dot dot2, t_line *c_line_ptr);

/* ft_canvas_color.c */
t_color	ft_canvas_color(int num);

#endif