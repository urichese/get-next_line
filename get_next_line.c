#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	static t_list 		**list;
	char				*buff;
	int 				reader;
	char				**text_adress;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buff = (char *) malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	reader = 1;
	text_adress = get_text(list, fd);
	reader = gnl_reader(text_adress, fd, buff, BUFFER_SIZE);
	free(buff);
	if (reader == -1)
		return (-1);
	*line = get_line(text_adress);
	if (reader == 0)
		return (0);
	return (1);
}
