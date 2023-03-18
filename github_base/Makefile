# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpothin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 15:23:40 by cpothin           #+#    #+#              #
#    Updated: 2023/03/18 15:43:26 by cpothin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
MAIN_DICTIONARY = numbers.dict

$(NAME):
	@gcc -Wall -Wextra -Werror main.c -o $(NAME) -fsanitize=address

clean:
	@find . -name $(NAME) -delete

fclean: clean
	@find . -name *.dict -not -name $(MAIN_DICTIONARY) -delete
