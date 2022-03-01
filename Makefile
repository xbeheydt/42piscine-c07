# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 15:30:27 by xbeheydt          #+#    #+#              #
#    Updated: 2021/11/29 06:44:35 by xbeheydt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean

SRCS		= test_main.c \
			  test_ft_strdup.c \
			  test_ft_range.c \
			  test_ft_ultimate_range.c \
			  test_ft_strjoin.c
INCLUDES	= deps/cunits42/build/include \
			  c07 \
			  .
LINKS		= deps/cunits42/build/lib c07
LIBS		= cunits42 c07

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g3
IFLAGS		= $(addprefix -I, ${INCLUDES})
LDFLAGS		= $(addprefix -L, ${LINKS})
LFLAGS		= $(addprefix -l, ${LIBS})

RM			= rm -rf

all: mandatory

re: fclean all

clean:
	$(MAKE) -C c07 clean
	$(MAKE) -C deps/cunits42 clean

fclean:
	$(MAKE) -C c07 fclean
	$(MAKE) -C deps/cunits42 fclean
	$(RM) a.out

mandatory:
	$(MAKE) -C deps/cunits42 all
	$(MAKE) -C c07
	$(CC) ${CFLAGS} ${IFLAGS} ${LDFLAGS} -o a.out $(addprefix tests/, ${SRCS})\
		${LFLAGS}
