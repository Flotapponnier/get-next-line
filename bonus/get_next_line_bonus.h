/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:37:47 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/04 11:44:03 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE <= 0
#  error "BUFFER_SIZE can't be <= 0"
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 50
# endif

char	*get_next_line(int fd);
char	*read_line(int fd, char *overflow_line);
char	*clean_overflow_line(char *overflow_line);
char	*clean_line(char *overflow_line);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_substr(char *str, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_free(char **str);

#endif
