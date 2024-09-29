#!/bin/sh
gcc -g -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o ex_ft_get_next_line
