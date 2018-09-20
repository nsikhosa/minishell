# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/26 08:17:56 by nsikhosa          #+#    #+#              #
#    Updated: 2017/10/03 09:43:32 by nsikhosa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c env.c signals.c ft_setenv.c path.c memory.c init.c \
	  ft_cd.c ft_echo.c

FLAG = -Wall -Wextra -Werror -g3

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libftSub
	@gcc $(FLAG) -c $(SRC)
	@gcc $(FLAG) $(OBJ) libftSub/libft.a  -o $(NAME)

clean:
	@make clean -C libftSub
	@/bin/rm -f $(OBJ) $(LOBJ) *.o

fclean: clean
	@make fclean -C libftSub
	@/bin/rm -f $(NAME)

re: fclean all
