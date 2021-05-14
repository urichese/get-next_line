#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct container_c {
	int fd;
	char **text;
} container_t;
int			get_next_line(int fd, char **line);
int			has_line(char **str);
char 		*get_text(container_t container);
char		*get_line(char **str_address);
int 		gnl_reader(char **text_adress, int fd, char *buff, int buff_size);

size_t		ft_strlen(const char *s);
void 		ft_strjoin(char **s1, const char *s2);

#endif
