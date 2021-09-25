# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keddib <keddib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/25 14:24:46 by keddib            #+#    #+#              #
#    Updated: 2021/09/25 17:31:34 by keddib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= 	philo

SRCS 		=	main.c \
				check_args.c \
				philosopher.c

OBJ			=	main.o \
				check_args.o \
				philosopher.o

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
