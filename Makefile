# Static library name
NAME = build/so_long.a

# Compiler and rules
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -Iinclude 
LDFLAGS = -ldl -lglfw -pthread -lm

# Directories
SRC_DIR = source
OBJ_DIR = build/obj

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBMLX_DIR = MLX42/build
LIBFT_DIR = source/ft_libft
FT_PRINTF_DIR = source/ft_printf

# # Sub-sources
LIBFT_LIB = $(LIBFT_DIR)/build/libft.a
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/build/ft_printf.a
LIBMLX_LIB = $(LIBMLX_DIR)/libmlx42.a

# Default rule
all: $(NAME)

$(NAME): $(FT_PRINTF_LIB) $(LIBFT_LIB) $(LIBMLX_LIB) $(OBJS)
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

# Rule to compile the ft_printf library
$(LIBFT_LIB):
	@echo "\033[1;35mCOMPILING LIBFT LIBRARY...\033[0m"
	@cd MLX42 && cmake -B build
	$(MAKE) -C $(LIBFT_DIR)

# Rule to compile the mlx library
$(LIBMLX_LIB): 
	@echo "\033[1;34mCOMPILING LIBX...\033[0m"
	$(MAKE) -C $(LIBMLX_DIR)

# Rule to clean object files and executables
clean:
	@echo "\033[1;31mCLEANING OBJECT FILES AND EXECUTABLES...\033[0m"
	rm -rf $(OBJ_DIR)
	rm -rf ./so_long
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(LIBMLX_DIR) clean
	@echo "\033[1;32mCLEANING DONE.\033[0m"

# Rule for full clean
fclean: clean
	@echo "\033[1;31mDELETING FILES $(NAME)...\033[0m"
	rm -f $(NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "\033[1;32mALL CLEANED UP.\033[0m"

# Rule to rebuild the project
re: fclean all
	@echo "\033[1;34mPROJECT REBUILD.\033[0m"

# Rule to run tests
gen_exec:
	@echo "\033[1;36mCOMPILING AND RUNNING TESTS...\033[0m"
	$(CC) $(CFLAGS) -o so_long $(OBJ_DIR)/so_long.o $(NAME) $(FT_PRINTF_LIB) $(LIBFT_LIB) $(LIBMLX_LIB) -lX11 -lXext $(LDFLAGS)

.PHONY: all clean fclean re gen_exec
