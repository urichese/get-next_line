#include "get_next_line.h"

int gnl_reader(char **text_adress, int fd, char *buff, int buff_size)
{
	int	reader;

	while (!has_line(text_adress))
	{
		reader = gnl_reader(text_adress, fd, buff, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buff);
			return (-1);
		}
		buff[reader] = '\0';
		ft_strjoin(text_adress, buff);
	}
	free(buff);
	return (reader);
}

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char *d;
	char *s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}

void 	ft_strjoin(char **s1_address, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	stot_len;
	char	*rtn;
	char 	*s1;

	if (!s1_address && !s2 ||!(*s1_address))
		return ;
	s1 = *s1_address;
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	stot_len = s1_len + s2_len + 1;
	rtn = malloc(sizeof(char) * stot_len);
	if (!rtn)
		return ;
	ft_memmove(rtn, s1, s1_len);
	ft_memmove(rtn + s1_len, s2, s2_len);
	rtn[stot_len - 1] = '\0';
	free((char *)s1);
	*s1_address = rtn;
}

int			has_line(char **str_address)
{
	int 	i;
	char	*str;

	if (!str_address || !(*str_address))
		return (0);
	str = *str_address;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
