# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/05 00:43:12 by mjusta            #+#    #+#              #
#    Updated: 2025/08/22 19:53:05 by mjusta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_DIR = src
OBJ_DIR = build
INC_DIR = include
LIBFT_DIR = libft

SRC = \
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/helpers.c \
		$(SRC_DIR)/instructions/swap.c \
		$(SRC_DIR)/instructions/rotate.c \
		$(SRC_DIR)/instructions/reverse.c \

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)/include

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)
	@test -d $(OBJ_DIR) && find $(OBJ_DIR) -type d -empty -delete || true
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

valgrind:
	@valgrind --leak-check=full --track-origins=yes ./$(NAME) 2 1 3 6 5 8

.PHONY: all clean fclean re valgrind
