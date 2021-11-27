# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/12 12:52:35 by elisa             #+#    #+#              #
#    Updated: 2021/11/09 15:34:53 by ejahan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

INCS	=	push_swap.h

SRCS	=	./SRCS/main.c ./SRCS/list.c ./SRCS/parsing.c ./SRCS/utils.c \
		./SRCS/swap.c ./SRCS/rotate.c ./SRCS/algo.c ./SRCS/algo_utils.c \
		./SRCS/median.c ./SRCS/max.c ./SRCS/op.c ./SRCS/print.c

OBJS	=	${SRCS:.c=.o}

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror #-g3 #-fsanitize=address

RM		=	rm -rf

all:		${NAME}

${NAME}:	${OBJS}
			$(CC) ${CFLAGS} $(OBJS) -I $(INCS) -o $(NAME) libft/libft.a

.c.o:
			$(MAKE) -C libft
			${CC} ${CFLAGS} -c $< -o $@ -I ${INCS}

clean:
			$(MAKE) -C libft clean
			${RM} ${OBJS}

fclean:		clean
			$(MAKE) -C libft fclean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
