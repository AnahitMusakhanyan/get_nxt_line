#include"get_next_line_bonus.h"


char	*ft_right_str(char *all)
{
	char	*right;
	int		i;
	int		len;

	i = 0;
	if (!all)
		return (0);
	while(all[i] != '\n' && all[i] != '\0')
		i++;
	if (!all[i])
	{
		free(all);
		return (0);
	}
	i++;
	len = ft_strlen(all) - i;
	right = ft_substr(all, i, len);
	free(all);
	return (right);
}

char	*ft_left_str(char *all)
{
	char	*left;
	size_t	i;

	i = 0;
	if (!all)
		return (0);
	while(all[i] != '\n' && all[i] != '\0')
		i++;
	left = ft_substr(all, 0, i);
	return (left);
}


char	*ft_read(int fd, char *str)
{
	char	buf[BUFFER_SIZE + 1];
	int		len;

	len = 1;
	while (1)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == 0 || len == -1)
			break ;
		buf[len] = '\0';
		if (!str)
			str = ft_strdup(buf);
		else
			str = ft_strjoin(str, buf);
		if (ft_strchr(str, '\n') != 0) 
			break ;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*all;
	char		*line;
	int			i;

	i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	all = ft_read(fd, all);
	line = ft_left_str(all);
	if (line == NULL)
		return (0);
	all = ft_right_str(all);
	return (line);
}