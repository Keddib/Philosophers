# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keddib <keddib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/25 14:24:46 by keddib            #+#    #+#              #
#    Updated: 2021/09/27 12:23:46 by keddib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= 	philo

SRCS 		=	main.c \
				check_args.c \
				philo_utils.c \
				philosopher.c \
				supervisor.c

OBJ			=	main.o \
				check_args.o \
				philo_utils.o \
				philosopher.o \
				supervisor.o

GO			=	gcc -Wall -Wextra -Werror -pthread -fsanitize=address -g3

all:	$(NAME)

$(NAME): $(SRCS)
		@$(GO) -c $(SRCS)
		@$(GO) -o $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
