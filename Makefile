# Static library name
NAME = build/so_long.a

# Compiler and rules
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

# Directories
SRC_DIR = source
OBJ_DIR = build/obj

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
FT_PRINTF_DIR = source/ft_printf
LIBMLX_DIR = source/mlx_linux

# # Sub-sources
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/build/ft_printf.a
MLX_LINUX_LIB = $(LIBMLX_DIR)/libmlx_Linux.a

# Default rule
all: $(NAME)

$(NAME): $(FT_PRINTF_LIB) $(MLX_LINUX_LIB) $(OBJS)
	@mkdir -p $(OBJ_DIR)
	@echo "\033[1;32mCREATING STATIC LIBRARY $@\033[0m"
	ar rcs $@ $^

# Rule to compile .c files into .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "\033[1;33mCOMPILING $<...\033[0m"
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile the ft_printf library
$(FT_PRINTF_LIB):
	@echo "\033[1;35mCOMPILING FT_PRINTF LIBRARY...\033[0m"
	$(MAKE) -C $(FT_PRINTF_DIR)

# Rule to compile the mlx library
$(MLX_LINUX_LIB): 
	@echo "\033[1;34mCOMPILING MINI LIBX...\033[0m"
	$(MAKE) -C $(LIBMLX_DIR)

# Rule to clean object files and executables
clean:
	@echo "\033[1;31mCLEANING OBJECT FILES AND EXECUTABLES...\033[0m"
	rm -rf $(OBJ_DIR)
	rm -rf ./so_long
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(LIBMLX_DIR) clean
	@echo "\033[1;32mCLEANING DONE.\033[0m"

# Rule for full clean
fclean: clean
	@echo "\033[1;31mDELETING FILES $(NAME)...\033[0m"
	rm -f $(NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(LIBMLX_DIR) fclean
	@echo "\033[1;32mALL CLEANED UP.\033[0m"

# Rule to rebuild the project
re: fclean all
	@echo "\033[1;34mPROJECT REBUILD.\033[0m"

# Rule to run tests
test:
	@echo "\033[1;36mCOMPILING AND RUNNING TESTS...\033[0m"
	$(CC) $(CFLAGS) -o so_long $(OBJ_DIR)/so_long.o $(NAME) $(FT_PRINTF_LIB) $(MLX_LINUX_LIB) -lX11 -lXext
	@./so_long

.PHONY: all clean fclean re test
