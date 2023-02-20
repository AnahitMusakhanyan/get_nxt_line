#include"get_next_line.h"

char	*ft_strdup(char *s1)
{
	char	*s2;
	size_t		i;

	if (!s1)
		return (0);
	i = -1;
	s2 = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (0);
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = -1;
	if(!s)
		return (0);
	while (s[++i])
	{
		if ((char)c == s[i])
			return ((char *)(s + i));
	}
	if (c == 0 && s[i] == 0)
		return ((char *)(s + i));
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s)
		return (0);
	while (s1[i])
	{
		s[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		s[j] = s2[i];
		i++;
		j++;
	}
	s[j] = '\0';
	if(s1)
		free(s1);
	return (s);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	sub = malloc(sizeof(char) * len + 1);
	if (!sub)
		return (0);
	while (i < len && s[start])
		sub[i++] = s[start++];
	if (s[start] == '\n')
	{
		sub[i] = '\n';
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

