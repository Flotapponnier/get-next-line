#include "get_next_line.h"

char	*clean_line_after(char *str)
{
	char	*result_clean_line;
	size_t	i;

	if (!str || *str == '\0')
		return (NULL);

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	if (str[i] == '\n')
		i++;
	result_clean_line = ft_substr(str, 0, i);
	if (!result_clean_line)
		return (NULL);

	return (result_clean_line);
}

char	*clean_line_before(char *str)
{
	char	*result_clean_line;
	size_t	i;

	if (!str || *str == '\0')
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	i++;
	result_clean_line = ft_substr(str, i, ft_strlen(str) - i);
	if (!result_clean_line)
	{
		free(str);
		return (NULL);
	}
	free(str);
	return (result_clean_line);
}

void	init_buffer_and_str(char **buffer, char **str)
{
	*buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (*str == NULL)
		*str = ft_strdup("");
	if (*buffer == NULL)
		return ;
}

char	*read_line(int fd, char *str)
{
	char	*buffer;
	ssize_t	readed;
	char	*tmp;

	readed = 1;
	init_buffer_and_str(&buffer, &str);
	if (!buffer)
		return (NULL);
	while (readed > 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
			return (NULL);
		if (readed == 0)
			break ;
		buffer[readed] = '\0';
		tmp = ft_strjoin(str, buffer);
		free(str);
		str = tmp;
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*overflow_line = NULL;
	char		*result_line;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	result_line = read_line(fd, overflow_line);
	if (!result_line)
		return (NULL);
	result = clean_line_after(result_line);
	if (!result)
	{
		free(result_line);
		return (NULL);
	}
	overflow_line = clean_line_before(result_line);
	return (result);
}

/*
int main(void)
{
	int fd;
	char *result;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((result = get_next_line(fd)) != NULL)
	{
		printf("%s", result);
		free(result);
	}
	close(fd);
	return (0);
}
*/
