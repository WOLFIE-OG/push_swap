# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otodd <otodd@student.42london.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 17:53:24 by otodd             #+#    #+#              #
#    Updated: 2024/03/13 14:30:19 by otodd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YELLOW=\033[1;33m
RED=\033[1;31m
GREEN=\033[1;32m
BLUE=\033[0;34m
NC=\033[0m

CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror -g
NAME	= push_swap

SRC_DIR = src
OBJ_DIR = obj
LIBFT_D = libft
INC_DIR = include

SRCS	= 	$(SRC_DIR)/commands/ft_ps_push.c \
			$(SRC_DIR)/commands/ft_ps_rev_rotate.c \
			$(SRC_DIR)/commands/ft_ps_rotate.c \
			$(SRC_DIR)/commands/ft_ps_swap.c \
			$(SRC_DIR)/misc/ft_ps_eco_utils.c \
			$(SRC_DIR)/misc/ft_ps_error_handler.c \
			$(SRC_DIR)/misc/ft_ps_get_utils.c \
			$(SRC_DIR)/misc/ft_ps_is_utils.c \
			$(SRC_DIR)/sorters/ft_ps_sort_stacks.c \
			$(SRC_DIR)/sorters/ft_ps_sort_three.c \
			$(SRC_DIR)/stacks/ft_ps_init_a_to_b.c \
			$(SRC_DIR)/stacks/ft_ps_init_b_to_a.c \
			$(SRC_DIR)/stacks/ft_ps_stack_init.c \
			$(SRC_DIR)/ft_ps_program.c 

OBJS 	= 	$(OBJ_DIR)/ft_ps_push.o \
			$(OBJ_DIR)/ft_ps_rev_rotate.o \
			$(OBJ_DIR)/ft_ps_rotate.o \
			$(OBJ_DIR)/ft_ps_swap.o \
			$(OBJ_DIR)/ft_ps_eco_utils.o \
			$(OBJ_DIR)/ft_ps_error_handler.o \
			$(OBJ_DIR)/ft_ps_get_utils.o \
			$(OBJ_DIR)/ft_ps_is_utils.o \
			$(OBJ_DIR)/ft_ps_sort_stacks.o \
			$(OBJ_DIR)/ft_ps_sort_three.o \
			$(OBJ_DIR)/ft_ps_init_a_to_b.o \
			$(OBJ_DIR)/ft_ps_init_b_to_a.o \
			$(OBJ_DIR)/ft_ps_stack_init.o \
			$(OBJ_DIR)/ft_ps_program.o 

LIBFT 	= $(LIBFT_D)/build/libft.a
LIBS 	= -L$(LIBFT_D)/build -lft

HEADERS	= -I$(INC_DIR) -I$(LIBFT_D)

all: $(LIBFT) $(NAME)

dir:
	@if [ ! -d "obj" ]; then \
		echo "[$(GREEN)PUSH_SWAP$(NC)] Creating obj directory..."; \
		mkdir -p obj; \
	fi

check_norminette:
	@echo "[$(BLUE)PUSH_SWAP$(NC)] Checking for errors with Norminette..."
	@if [ $$(pip list | grep "norminette" | wc -l) -gt 1 ]; then \
		echo "[$(RED)PUSH_SWAP$(NC)] Norminette is not installed. Please install Norminette."; \
		exit 1; \
	else \
		if [ $$(norminette src include | grep "Error:" | wc -l) -gt 0 ]; then \
			echo "[$(RED)PUSH_SWAP$(NC)] Norminette found errors."; \
			exit 1; \
		else \
			echo "[$(GREEN)PUSH_SWAP$(NC)] Norminette found no errors."; \
		fi; \
	fi

$(NAME): $(OBJS)
	@echo "[$(GREEN)PUSH_SWAP$(NC)] Building $@..."
	@$(CC) $(CFLAGS) $(OBJS) $(HEADERS) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/push_swap.h | dir
	@echo "[$(GREEN)PUSH_SWAP$(NC)] Compiling $< --> $@"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c $(INC_DIR)/push_swap.h | dir
	@echo "[$(GREEN)PUSH_SWAP$(NC)] Compiling $< --> $@"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_D)

clean:
	@echo "[$(YELLOW)PUSH_SWAP$(NC)] Cleaning object files..."
	@$(MAKE) -s -C $(LIBFT_D) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "[$(YELLOW)PUSH_SWAP$(NC)] Cleaning executable file..."
	@$(MAKE) -s -C $(LIBFT_D) fclean
	@rm -rf $(NAME)

re: fclean all

norm: check_norminette all

.PHONY: all clean fclean re norm
