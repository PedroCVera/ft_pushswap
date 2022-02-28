# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 14:45:42 by pcoimbra          #+#    #+#              #
#    Updated: 2022/02/28 14:45:43 by pcoimbra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS =	algo.c \
		algo100.c \
		algo500.c \
		AtoBgeral.c \
		ft_chun.c \
		ft_cmdpapb.c \
		ft_cmdra.c \
		ft_cmdrra.c \
		ft_cmdsa.c \
		ft_errors_atoi.c \
		ft_errors.c \
		ft_orderchecker.c \
		ft_sort_five.c \
		ft_sort_four.c \
		ft_sort_three.c \
		ft_sort_two.c \
		ft_sorting.c \
		ft_pushswap.c

OBJS = ${SRCS:.c=.o}

NAME = push_swap

HEAD = includes

CC = gcc

LIBFT = -lft -L libft

Rm = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEAD}

${NAME}: ${OBJS}
	make bonus -C libft/
	${CC} ${CFLAGS} -lft $^ -I ${HEAD} -o $@ -L ./libft

all: ${NAME}

clean:
	${RM} ${OBJS}
	make clean -C libft/

fclean: clean
	${RM} ${NAME}
	make fclean -C libft/

re:	fclean all

.PHONY: all fclean clean re