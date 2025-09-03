# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjusta <mjusta@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/05 00:43:12 by mjusta            #+#    #+#              #
#    Updated: 2025/09/03 03:05:39 by mjusta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_DIR = src
OBJ_DIR = build
INC_DIR = include
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)/include

SRC = \
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/checker.c \
		$(SRC_DIR)/helpers.c \
		$(SRC_DIR)/parser.c \
		$(SRC_DIR)/normalize.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/cost.c \
		$(SRC_DIR)/sort.c \
		$(SRC_DIR)/execute_move.c \
		$(SRC_DIR)/push_strategy.c \
		$(SRC_DIR)/exec_utils.c \
		$(SRC_DIR)/insert_pos_a.c \
		$(SRC_DIR)/insert_pos_b.c \
		$(SRC_DIR)/instructions/swap.c \
		$(SRC_DIR)/instructions/rotate.c \
		$(SRC_DIR)/instructions/reverse.c \
		$(SRC_DIR)/instructions/push.c \

#OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(filter-out $(OBJ_DIR)/checker.o, $(OBJ)) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(NAME)

$(BONUS): $(filter-out $(OBJ_DIR)/main.o, $(OBJ)) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(BONUS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)
	@test -d $(OBJ_DIR) && find $(OBJ_DIR) -type d -empty -delete || true
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

valgrind:
	@valgrind --leak-check=full --track-origins=yes ./$(NAME) 2 1 3 6 5 8

.PHONY: all clean fclean re bonus valgrind
