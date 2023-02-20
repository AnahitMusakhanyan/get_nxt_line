#ifndef GET_NEXT_LINE_BONUS
# define GET_NEXT_LINE_BONUS

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

char	*ft_left_str(char *all);
char	*ft_read(int fd, char *str);
char	*get_next_line(int fd);
char	*ft_right_str(char *all);



char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, size_t start, size_t len);



#endif