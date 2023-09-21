# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 15:24:43 by jakgonza          #+#    #+#              #
#    Updated: 2023/09/21 19:07:38 by jakgonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_strlen.c\
	   ft_strlcpy.c\
	   ft_strlcat.c\
	   ft_strncmp.c\
	   ft_substr.c\
	   ft_strjoin.c\
	   ft_split.c\

OBJS = $(SRCS:.c=.o)

CFLAGS = -g3 -Wall -Werror -Wextra -fsanitize=address

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

all: $(NAME) 

$(NAME): $(OBJS)
	ar rcs $@ $^

clean:
	rm -f $(OBJS)
	@echo "Object files removed"

fclean: clean
	rm -f $(NAME)
	@echo "Library removed"

re: fclean all

.PHONY: all clean fclean re
