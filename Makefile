# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keddib <keddib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/15 17:44:01 by keddib            #+#    #+#              #
#    Updated: 2021/07/15 17:50:55 by keddib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo

GCC				= gcc -Wall -Wextra -Werror

SRC				= src

SRCS			=

all:	$(NAME)

$(NAME) : $(SRCS)
	@$(GCC) -o $(NAME) $(SRCS)

clean:
	@rm -rf *.o *.dSYM

fclean: clean
	@rm $(NAME)

re: fclean all

.PHONY: clean fclean re all $(GNL)
