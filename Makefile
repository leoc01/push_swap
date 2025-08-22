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
BONUS_NAME = checker

CC = cc
CFLAGS = -g -Wall -Werror -Wextra
RM = rm -rf
LFT = libft/libft.a

MAIN = push_swap.c
MAIN_OBJ = $(MAIN:.c=.o)

SRC += ins_a.c
SRC += ins_b.c
SRC += ins_g.c
SRC += ins_push.c
SRC += sort.c
SRC += cost.c
SRC += cost_utils.c
SRC += target.c
SRC += check.c
SRC += utils.c

OBJ = $(SRC:.c=.o)

BONUS_SRC = checker_bonus.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(LFT) $(NAME)

$(NAME): $(OBJ) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MAIN_OBJ) -Llibft -lft -o $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -Ilibft -c $< -o $@

$(LFT):
	make -C libft all

clean:
	$(RM) $(OBJ) $(MAIN_OBJ) $(BONUS_OBJ)
	make -C libft clean

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	make -C libft fclean

re: fclean all

bonus: $(LFT) $(OBJ) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(BONUS_OBJ) -Llibft -lft -o $(BONUS_NAME)

