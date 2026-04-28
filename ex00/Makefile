# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axgimene <axgimene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/14 19:09:19 by axgimene          #+#    #+#              #
#    Updated: 2026/04/28 13:56:37 by axgimene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = bur1
CC          = c++
FLAGS       = -Wall -Wextra -Werror -std=c++98
SRCS        = main.cpp Bureaucrat.cpp
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