/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:37:37 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/22 17:42:53 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*clean_overflow_line(char *overflow_line)
{
	char	*new_overflow_line;
	char	*position;
	int		len;

	position = ft_strchr(overflow_line, '\n');
	if (!position)
		return (ft_free(&overflow_line));
	else
		len = (position - overflow_line) + 1;
	if (!overflow_line[len])
		return (ft_free(&overflow_line));
	new_overflow_line = ft_substr(overflow_line, len, ft_strlen(overflow_line)
			- len);
	ft_free(&overflow_line);
	if (!new_overflow_line)
		return (NULL);
	return (new_overflow_line);
}

char	*clean_line(char *overflow_line)
{
	char	*line;
	char	*position;
	int		len;

	position = ft_strchr(overflow_line, '\n');
	len = (position - overflow_line) + 1;
	line = ft_substr(overflow_line, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*read_line(int fd, char *overflow_line)
{
	int		readed;
	char	*buffer;

	readed = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&overflow_line));
	buffer[0] = '\0';
	while (readed > 0 && ft_strchr(buffer, '\n') == 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed > 0)
		{
			buffer[readed] = '\0';
			overflow_line = ft_strjoin(overflow_line, buffer);
		}
	}
	free(buffer);
	if (readed == -1)
		return (ft_free(&overflow_line));
	return (overflow_line);
}

char	*get_next_line(int fd)
{
	static char	*overflow_line = NULL;
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((overflow_line != 0 && !ft_strchr(overflow_line, '\n'))
		|| !overflow_line)
		overflow_line = read_line(fd, overflow_line);
	if (!overflow_line)
		return (NULL);
	line = clean_line(overflow_line);
	if (!line)
		return (ft_free(&overflow_line));
	overflow_line = clean_overflow_line(overflow_line);
	return (line);
}

/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/
