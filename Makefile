# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorion- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/19 14:27:29 by amorion-          #+#    #+#              #
#    Updated: 2021/10/21 18:50:05 by amorion-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = julia.c keys.c main.c mandelbrot.c put_fractal.c utils.c

OBJS = ${SRCS:.c=.o}

NAME = fractol
.c.o:
	@gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}
all: ${NAME}

${NAME}: ${OBJS}
	@echo "binary generated"
	@gcc -Wall -Werror -Wextra -lmlx -framework OpenGL -framework AppKit ${OBJS} -o ${NAME}
clean:
	@echo "o files deleted"
	@rm -rf ${OBJS}
fclean: clean
	@echo "fract-ol deleted"
	@rm -rf ${NAME}
re: fclean all
