# Static library name
NAME = build/so_long.a
BONUS = build/so_long_bonus.a

# Compiler and rules
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -Iinclude 
LDFLAGS = -ldl -lglfw -pthread -lm

# Directories
SRC_DIR = source
SRC_BONUS_DIR = source_bonus
OBJ_DIR = build/mandatory/obj
BONUS_OBJS_DIR = build/bonus/obj

# Source files
SRC_FILES = 		$(SRC_DIR)/asset_manager.c $(SRC_DIR)/game_events.c $(SRC_DIR)/game_manager.c  \
					$(SRC_DIR)/hook_handler.c $(SRC_DIR)/map_utils.c $(SRC_DIR)/map_utils_2.c \
					$(SRC_DIR)/map_validation.c $(SRC_DIR)/map_validation_2.c $(SRC_DIR)/player_movement.c \
					$(SRC_DIR)/render_manager.c $(SRC_DIR)/so_long.c

SRC_BONUS_FILES =	$(SRC_BONUS_DIR)/asset_manager_bonus.c $(SRC_BONUS_DIR)/game_events_bonus.c \
					$(SRC_BONUS_DIR)/game_manager_bonus.c $(SRC_BONUS_DIR)/hook_handler_bonus.c \
					$(SRC_BONUS_DIR)/map_utils_bonus.c $(SRC_BONUS_DIR)/map_utils_2_bonus.c \
					$(SRC_BONUS_DIR)/map_validation_bonus.c $(SRC_BONUS_DIR)/map_validation_2_bonus.c \
					$(SRC_BONUS_DIR)/player_movement_bonus.c $(SRC_BONUS_DIR)/render_manager_bonus.c \
					$(SRC_BONUS_DIR)/so_long_bonus.c

OBJS = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS = $(SRC_BONUS_FILES:$(SRC_BONUS_DIR)/%.c=$(BONUS_OBJS_DIR)/%.o)

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
	@echo "\033[1;36mCOMPILING AND GENERATING EXECUTABLES...\033[0m"
	$(CC) $(CFLAGS) -o so_long $(OBJ_DIR)/so_long.o $(NAME) $(FT_PRINTF_LIB) $(LIBFT_LIB) $(LIBMLX_LIB) -lX11 -lXext $(LDFLAGS)

# Rule to compile .c files into .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "\033[1;33mCOMPILING $<...\033[0m"
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile .c files into .o (bonus files)
$(BONUS_OBJS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	@mkdir -p $(BONUS_OBJS_DIR)
	@echo "\033[1;33mCOMPILING BONUS $<...\033[0m"
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile the ft_printf library
$(FT_PRINTF_LIB):
	@echo "\033[1;35mCOMPILING FT_PRINTF LIBRARY...\033[0m"
	$(MAKE) -C $(FT_PRINTF_DIR)

# Rule to compile the ft_printf library
$(LIBFT_LIB):
	@echo "\033[1;35mCOMPILING LIBFT LIBRARY...\033[0m"
	$(MAKE) -C $(LIBFT_DIR)

# Rule to compile the mlx library
$(LIBMLX_LIB): 
	@echo "\033[1;34mCOMPILING LIBX...\033[0m"
	@cd MLX42 && cmake -B build
	$(MAKE) -C $(LIBMLX_DIR)

# Rule to clean object files and executables
clean:
	@echo "\033[1;31mCLEANING OBJECT FILES AND EXECUTABLES...\033[0m"
	rm -rf build
	rm -rf ./so_long
	rm -rf ./so_long_bonus
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

# Bonus rule (compiles the bonus files and generates a bonus executable)
bonus: $(BONUS)

# Rule to create the static library from the bonus program
$(BONUS): $(FT_PRINTF_LIB) $(LIBFT_LIB) $(LIBMLX_LIB) $(BONUS_OBJS)
	@mkdir -p $(BONUS_OBJS_DIR)
	@echo "\033[1;32mCREATING STATIC LIBRARY FOR BONUS$@\033[0m"
	ar rcs $@ $^
	@echo "\033[1;36mCOMPILING AND GENERATING EXECUTABLE...\033[0m"
	$(CC) $(CFLAGS) -o so_long_bonus $(BONUS_OBJS_DIR)/so_long_bonus.o $(BONUS) $(FT_PRINTF_LIB) $(LIBFT_LIB) $(LIBMLX_LIB) -lX11 -lXext $(LDFLAGS)

# Rule to compile .c files into .o (bonus files)
$(BONUS_OBJS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	@mkdir -p $(BONUS_OBJS_DIR)
	@echo "\033[1;33mCOMPILING BONUS $<...\033[0m"
	$(CC) $(CFLAGS) -c $< -o $@

PHONY: all clean fclean re bonus
