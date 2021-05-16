#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct container_c {
	int fd;
	char **text;
} container_t;

typedef struct s_list
{
	container_t		*content;
	struct s_list	*next;
}	t_list;

int			get_next_line(int fd, char **line);
int			has_line(char **str);
char 		**get_text(t_list **list, int fd);
char		*get_line(char **str_address);
int 		gnl_reader(char **text_adress, int fd, char *buff, int buff_size);

size_t		ft_strlen(const char *s);
void 		ft_strjoin(char **s1, const char *s2);

t_list	*ft_lstnew(container_t *content);
void	ft_lstadd_back(t_list **lst, t_list *new);

#endif
