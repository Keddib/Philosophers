# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keddib <keddib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/25 14:24:46 by keddib            #+#    #+#              #
#    Updated: 2021/09/25 15:04:43 by keddib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= 	philo

SRCS 		=	philo.c \
				check_args.c

OBJ			=	philo.o \
				check_args.o

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
