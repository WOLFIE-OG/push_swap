# Define colors
YELLOW=\033[1;33m
RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRC_DIR = src
OBJ_DIR = obj
LIBFT_D = libft
INC_DIR = include

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_D)/build/libft.a
LIBS = -L$(LIBFT_D)/build -lft

HEADERS = -I$(INC_DIR) -I$(LIBFT_D)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "[$(GREEN)PUSH_SWAP$(NC)] Building $@..."
	@$(CC) $(CFLAGS) $(OBJS) $(HEADERS) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/push_swap.h
	@mkdir -p $(OBJ_DIR)
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

.PHONY: all clean fclean re
