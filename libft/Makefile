# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 13:30:36 by lbuscaro          #+#    #+#              #
#    Updated: 2025/04/16 15:32:42 by lbuscaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

FILES = ft_isalpha.c
FILES += ft_isdigit.c
FILES += ft_isalnum.c
FILES += ft_isascii.c
FILES += ft_isprint.c
FILES += ft_strlen.c
FILES += ft_memset.c
FILES += ft_bzero.c
FILES += ft_memcpy.c
FILES += ft_memmove.c
FILES += ft_strlcpy.c
FILES += ft_strlcat.c
FILES += ft_toupper.c
FILES += ft_tolower.c
FILES += ft_strchr.c
FILES += ft_strrchr.c
FILES += ft_strncmp.c
FILES += ft_memchr.c
FILES += ft_memcmp.c
FILES += ft_strnstr.c
FILES += ft_atoi.c
FILES += ft_calloc.c
FILES += ft_strdup.c
FILES += ft_substr.c
FILES += ft_strjoin.c
FILES += ft_strtrim.c
FILES += ft_split.c
FILES += ft_itoa.c
FILES += ft_strmapi.c
FILES += ft_striteri.c
FILES += ft_putchar_fd.c
FILES += ft_putstr_fd.c
FILES += ft_putendl_fd.c
FILES += ft_putnbr_fd.c

OBJS = $(FILES:%.c=%.o)

BONUS_FILES = ft_lstnew.c
BONUS_FILES += ft_lstadd_front.c
BONUS_FILES += ft_lstsize.c
BONUS_FILES += ft_lstlast.c
BONUS_FILES += ft_lstadd_back.c
BONUS_FILES += ft_lstdelone.c
BONUS_FILES += ft_lstclear.c
BONUS_FILES += ft_lstiter.c
BONUS_FILES += ft_lstmap.c

BONUS_OBJS = $(BONUS_FILES:%.c=%.o)

BONUS_STATUS = .bonus_linked

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) $(BONUS_STATUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_STATUS)

$(BONUS_STATUS): $(NAME) $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)
	@touch $(BONUS_STATUS)
