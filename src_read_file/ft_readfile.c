#include <ft_readfile.h>

t_oneline *readfile(char *file_name)
{
    t_oneline   *head_oneline;
    
    char  *line;
    int   fd1;

    head_oneline = NULL;
    fd1 = open(file_name, O_RDONLY);
    while (get_next_line(fd1, &line) > 0)
        ft_oneline_add(&head_oneline, line);
    return (head_oneline);
}
