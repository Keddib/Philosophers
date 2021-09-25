# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keddib <keddib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/15 17:44:01 by keddib            #+#    #+#              #
#    Updated: 2021/09/24 13:26:34 by keddib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo

SRC				= philo/

OBJ			=

GCC				= gcc -Wall -Wextra -Werror -pthread

all:	$(NAME)

$(NAME) : $(SRCS)
	@$(GCC) -o $(NAME) $(SRCS)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm $(NAME)

re: fclean all

.PHONY: clean fclean re all $(GNL)
