# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otodd <otodd@student.42london.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 17:53:24 by otodd             #+#    #+#              #
#    Updated: 2024/04/23 13:40:23 by otodd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YELLO			=	\033[1;33m
RED				=	\033[1;31m
GREEN			=	\033[1;32m
BLUE			=	\033[1;34m
CYAN			=	\033[1;36m
NC				=	\033[0m

CC 				= 	cc
CFLAGS 			= 	-Wall -Wextra -Werror
NAME			= 	push_swap

SRC_DIR 		= 	src
OBJ_DIR 		= 	obj
LIBFT_D 		= 	libft
INC_DIR 		= 	include

COMMANDS_DIR	=	$(SRC_DIR)/commands
MISC_DIR		=	$(SRC_DIR)/misc
SORTERS_DIR		=	$(SRC_DIR)/sorters
STACKS_DIR		=	$(SRC_DIR)/stacks

COMMANDS_OBJS	=	$(OBJ_DIR)/commands
MISC_OBJS		=	$(OBJ_DIR)/misc
SORTERS_OBJS	=	$(OBJ_DIR)/sorters
STACKS_OBJS		=	$(OBJ_DIR)/stacks

OBJ_DIRS		=	$(COMMANDS_OBJS)											\
					$(MISC_OBJS)												\
					$(SORTERS_OBJS)												\
					$(STACKS_OBJS)
					

COMMANDS_SRCS	= 	$(COMMANDS_DIR)/ft_ps_push.c								\
					$(COMMANDS_DIR)/ft_ps_rev_rotate.c							\
					$(COMMANDS_DIR)/ft_ps_rotate.c								\
					$(COMMANDS_DIR)/ft_ps_swap.c								\

MISC_SRCS		=	$(MISC_DIR)/ft_ps_eco_utils.c								\
					$(MISC_DIR)/ft_ps_error_handler.c							\
					$(MISC_DIR)/ft_ps_get_utils.c 								\
					$(MISC_DIR)/ft_ps_is_utils.c 								\
					
SORTERS_SRCS	=	$(SORTERS_DIR)/ft_ps_sort_stacks.c 							\
					$(SORTERS_DIR)/ft_ps_sort_three.c 							\
					
STACKS_SRCS		=	$(STACKS_DIR)/ft_ps_init_a_to_b.c 							\
					$(STACKS_DIR)/ft_ps_init_b_to_a.c 							\
					$(STACKS_DIR)/ft_ps_stack_init.c 							\

OBJS 			= 	$(OBJ_DIR)/ft_ps_program.o									\
					$(COMMANDS_SRCS:$(COMMANDS_DIR)/%.c=$(COMMANDS_OBJS)/%.o)	\
					$(MISC_SRCS:$(MISC_DIR)/%.c=$(MISC_OBJS)/%.o)				\
					$(SORTERS_SRCS:$(SORTERS_DIR)/%.c=$(SORTERS_OBJS)/%.o)		\
					$(STACKS_SRCS:$(STACKS_DIR)/%.c=$(STACKS_OBJS)/%.o)			\
					

LIBFT 			= 	$(LIBFT_D)/build/libft.a
LIBS 			= 	-L$(LIBFT_D)/build -lft

HEADERS			= 	-I$(INC_DIR) -I$(LIBFT_D)

all: $(LIBFT) $(NAME)

dir:
	@for dir in $(OBJ_DIRS) $(BUILD_DIR); do 									\
		if [ ! -d "$$dir" ]; then 												\
			echo "[$(GREEN)PUSH_SWAP$(NC)] Creating obj directory: $$dir"; 		\
			mkdir -p $$dir; 													\
		fi; 																	\
	done

$(NAME): $(OBJS)
	@echo "[$(BLUE)PUSH_SWAP$(NC)] Building $@..."
	@$(CC) $(CFLAGS) $(OBJS) $(HEADERS) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/push_swap.h | dir
	@echo "[$(CYAN)PUSH_SWAP$(NC)] Compiling $< --> $@"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(COMMANDS_OBJS)/%.o: $(COMMANDS_DIR)/%.c $(INC_DIR)/push_swap.h | dir
	@echo "[$(CYAN)PUSH_SWAP$(NC)] Compiling $< --> $@ from $(COMMANDS_DIR)"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(MISC_OBJS)/%.o: $(MISC_DIR)/%.c $(INC_DIR)/push_swap.h | dir
	@echo "[$(CYAN)PUSH_SWAP$(NC)] Compiling $< --> $@ from $(MISC_DIR)"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(SORTERS_OBJS)/%.o: $(SORTERS_DIR)/%.c $(INC_DIR)/push_swap.h | dir
	@echo "[$(CYAN)PUSH_SWAP$(NC)] Compiling $< --> $@ from $(SORTERS_DIR)"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(STACKS_OBJS)/%.o: $(STACKS_DIR)/%.c $(INC_DIR)/push_swap.h | dir
	@echo "[$(CYAN)PUSH_SWAP$(NC)] Compiling $< --> $@ from $(STACKS_DIR)"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_D)

clean:
	@echo "[$(YELLOW)PUSH_SWAP$(NC)] Cleaning object directory..."
	@$(MAKE) -s -C $(LIBFT_D) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "[$(RED)PUSH_SWAP$(NC)] Cleaning executable directory..."
	@$(MAKE) -s -C $(LIBFT_D) fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re norm
