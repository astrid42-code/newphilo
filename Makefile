# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/19 15:27:57 by asgaulti          #+#    #+#              #
#    Updated: 2021/11/30 12:37:34 by asgaulti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRCS	=	main.c ft_print.c ft_utils.c ft_check.c ft_init.c \
			ft_exit.c ft_routine.c ft_utils_time.c 

PATH_SRCS = srcs/

OBJS	=	${addprefix ${PATH_SRCS}, ${SRCS:.c=.o}}

CC		=	clang 
#clang-9 
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra
#CFLAGS	+= -g3 -fsanitize=address
CFLAGS	+= -g3 -fsanitize=thread

INCL	=	include

.c.o:
			${CC} ${CFLAGS} -I${INCL} -g -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${CC} ${CFLAGS} ${LFLAGS} ${OBJS} -o ${NAME} -pthread
#attention : proble avec .h?
all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}
					
re:			fclean all

.PHONY:		all clean fclean re