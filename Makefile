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
SRC += inter.c

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
	make -C libft clean

re: fclean all
