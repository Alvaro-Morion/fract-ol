# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorion- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/19 14:27:29 by amorion-          #+#    #+#              #
#    Updated: 2021/09/19 14:27:31 by amorion-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = main.c utils.c julia.c mandelbrot.c keys.c

OBJS = ${SRCS:.c=.o}

NAME = fract-ol
.c.o:
	@gcc -Wall -Werror -Wextra -c $< -o ${<:.c=.o}
all: ${NAME}

${NAME}: ${OBJS}
	@echo "binary generated"
	@gcc -Wall -Werror -Wextra  -lmlx -framework OpenGL -framework AppKit ${OBJS} -o ${NAME}
clean:
	@echo "o files deleted"
	@rm -rf ${OBJS}
fclean: clean
	@echo "fract-ol deleted"
	@rm -rf ${NAME}
re: fclean all