# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/08 17:52:50 by lbuscaro          #+#    #+#              #
#    Updated: 2025/08/08 17:53:12 by lbuscaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -g -Wall -Werror -Wextra
RM = rm -rf
LFT = libft/libft.a

SRC = push_swap.c
SRC += ins_a.c
SRC += ins_b.c
SRC += ins_g.c
SRC += ins_push.c
SRC += sort.c
SRC += cost.c
SRC += cost_utils.c
SRC += target.c
SRC += check.c

OBJ = $(SRC:.c=.o)

all: $(LFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -Ilibft -c $< -o $@

$(LFT):
	make -C libft all

clean:
	$(RM) $(OBJ)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all
