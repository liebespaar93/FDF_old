
#ifndef FT_CANVAS_TYPE_H
# define FT_CANVAS_TYPE_H

#define CANVAS_X		0
#define CANVAS_Y		0
#define CANVAS_WIDTH	WIN_WIDTH
#define CANVAS_HEIGHT	WIN_HEIGHT

#include <libft.h>

typedef struct s_line
{
	t_xyz	dot1;
	t_xyz	dot2;
}	t_line;

typedef	struct s_img_info
{
	char	*buffer;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
} t_img_info;

typedef union u_color
{
    int num;
    
	struct
	{
		unsigned char	b :8 ;
		unsigned char   g :8 ;
		unsigned char	r :8 ;
		unsigned char	a :8 ;
	}	s_bit;
}   t_color;

#endif