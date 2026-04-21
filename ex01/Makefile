# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axgimene <axgimene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/21 16:34:16 by axgimene          #+#    #+#              #
#    Updated: 2026/04/21 16:40:58 by axgimene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = bur2
CC          = c++
FLAGS       = -Wall -Wextra -Werror -std=c++98
SRCS        = main.cpp Bureaucrat.cpp Form.cpp
OBJS        = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re