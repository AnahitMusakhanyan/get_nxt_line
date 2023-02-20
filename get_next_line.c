#include"get_next_line.h"


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

int main()
{
	int fd = open("tester/files/nl", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
}



// char	*ft_left_str(char *all)
// {
// 	int		i;
// 	char	*left;
// 	int j = 0;
// 	int tmp;

// 	i = 0;
// 	while (all[i] != '\n' && all[i] != '\0')
// 		i++;
// 	tmp = i + 1;
// 	while (all[++i] != '\0')
// 		j++;
// 	left = malloc(sizeof(char) * (j + 1));
// 	if (!left)
// 		return (0);
// 	j = 0;
// 	i = tmp;
// 	while (all[i])
// 	{
// 		left[j] = all[i];
// 		i++;
// 		j++;
// 	}
// 	left[j] = '\0';
// 	return (left);
// }









// char	*ft_right_str(char *all)
// {
// 	char	*right;
// 	int		i;
// 	int		len;

// 	i = 0;
// 	if (!all)
// 		return (0);
// 	while(all[i] != '\n' && all[i] != '\0')
// 		i++;
// 	if (!all[i])
// 	{
// 		free(all);
// 		return (0);
// 	}
// 	len = ft_strlen(all) - i + 1;
// 	right = ft_substr(all, i, len);
// 	// while(all[i] != '\n' && all[i] != '\0')
// 	// {
// 	// 	right[j] = all[i];
// 	// 	i++;
// 	// 	j++;
// 	// }
// 	// right[j] = '\0';
// 	free(all);
// 	return (right);
// }

// char	*ft_left_str(char *all)
// {
// 	char	*left;
// 	int		i;

// 	i = 0;
// 	if (!all)
// 		return (0);
// 	while(all[i] != '\n' && all[i] != '\0')
// 		i++;
// 	if (all[i] == '\0')
// 	{
// 		free(all);
// 		return (0);
// 	}
// 	left = ft_substr(all, 0, i);
// 	// left = malloc(sizeof(char) * (i + 2));
// 	// if (!left)
// 	// 	return (0);
// 	// i = 0;
// 	// while (all[i] != '\n' && all[i] != '\0')
// 	// {
// 	// 	left[i] = all[i];
// 	// 	i++;
// 	// }
// 	// if (all[i] == '\n')
// 	// {
// 	// 	left [i] = '\n';
// 	// 	i++;
// 	// }
// 	// left[i] = '\0';
// 	return (left);
// }

// char	*ft_read_nl(int fd, char *str)
// {
// 	char	*buf;
// 	int		len;

// 	len = 1;
// 	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buf)
// 		return (0);
// 	while (ft_strchr(str, '\n') && len != 0)
// 	{
// 		len = read(fd, buf, BUFFER_SIZE);
// 		if (len == -1)
// 		{
// 			free(buf);
// 			return (0);
// 		}
// 		buf[len] = '\0';
// 		str = ft_strjoin(str, buf);
// 	}
// 	free (buf);
// 	return (str);
// }

// char *get_next_line(int fd)
// {
// 	static char	*all;
// 	char		*line;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (0);
// 	all = ft_read_nl(fd, all);
// 	if (!all)
// 		return (0);
// 	line = ft_left_str(all);
// 	all = ft_right_str(all);
// 	return (line);
// }




























