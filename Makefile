# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omansour <omansour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 10:36:11 by omansour          #+#    #+#              #
#    Updated: 2023/02/16 22:12:55 by omansour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	push_swap.c\
				for_sorting/is_sorted.c for_sorting/sort_ffive.c for_sorting/sort_three.c for_sorting/sort_x.c\
				operations/push.c operations/rotate.c operations/rrotate.c operations/swap.c\
				parsing_args/initialize.c parsing_args/valid_args.c\
				utils/lst_utils.c utils/re_atoi.c utils/show_error.c

SRC_B		=	bonus/checker.c\
				bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c\
				bonus/operations/push.c bonus/operations/rotate.c bonus/operations/rrotate.c bonus/operations/swap.c\
				bonus/parsing_args/initialize.c bonus/parsing_args/valid_args.c\
				bonus/utils/lst_utils.c bonus/utils/utils.c

LIBFT		=	libft/libft.a

CFLAGS		=	-Wall -Werror -Wextra

OBJS		=	${SRC:.c=.o}

OBJS_B		=	${SRC_B:.c=.o}

NAME		=	push_swap

NAME_B		=	checker

CC			=	cc

RM			=	rm -rf

all : ${NAME}

${LIBFT} :
	make -C libft

${NAME} : ${LIBFT} ${OBJS}
	${CC} ${CFLAGS} ${LIBFT} ${OBJS} -o ${NAME}

bonus : ${LIBFT} ${OBJS_B}
	${CC} ${CFLAGS} ${LIBFT} ${OBJS_B} -o ${NAME_B}

clean :
	make clean -C libft
	${RM} ${OBJS} ${OBJS_B}

fclean : clean
	${RM} ${NAME} ${NAME_B} ${LIBFT}

re : fclean all
