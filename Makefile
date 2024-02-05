# Define colors
YELLOW=\033[1;33m
RED=\033[1;31m
GREEN=\033[1;32m
BLUE=\033[0;34m
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

all: display check_norminette $(NAME)

display:
	@echo "$(BLUE)=======================================================$(NC)"
	@echo "Program: $(NAME)"
	@echo "Compiler: $(CC)"
	@echo "Compiler Flags: $(CFLAGS)"
	@echo "Using libft?: Yes"
	@echo "$(BLUE)=======================================================$(NC)"

check_norminette:
	@echo "[$(BLUE)PUSH_SWAP$(NC)] Checking for errors with Norminette..."
	@if [ $$(pip list | grep "norminette" | wc -l) -gt 1 ]; then \
		echo "[$(RED)PUSH_SWAP$(NC)] Norminette is not installed. Please install Norminette."; \
		exit 1; \
	else \
		if [ $$(norminette | grep "Error:" | wc -l) -gt 0 ]; then \
			echo "[$(RED)PUSH_SWAP$(NC)] Norminette found errors."; \
			exit 1; \
		else \
			echo "[$(GREEN)PUSH_SWAP$(NC)] Norminette found no errors."; \
		fi; \
	fi

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
