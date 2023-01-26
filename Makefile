NAME	= libftprintf.a

HEADER	= libftprintf.h

INCLUDE = -I./

SRCS	= ft_printf.c

OBJS	= ${SRCS:..c=.o}

DEPS	= $(addsufix .d, $(basename ${OBJS}))

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

%.o : %.c Makefile
	${CC} -MT $@ ${CFLAGS} -MMD -MP ${INCLUDE} -c $< -o $@

all:	${NAME}

${NAME}:	${OBJS}
	ar src ${NAME} ${OBJS}

-include	${DEPS}

clean: 
			rm -rf ${OBJS} ${DEPS}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
