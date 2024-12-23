# Define colors
GREEN = \033[4;32m
YELLOW = \033[1;33m
NC = \033[0m  # No Color

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -I./include/ -I./libft/
LIBFT_DIR = libft
MLX_DIR = mlx
OBJ_DIR = obj
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
    INCLUDES = -I/usr/include -I$(MLX_DIR)
    MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
else
    INCLUDES = -I/opt/X11/include -I$(MLX_DIR)
    MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit -ftrapv
endif

LIBFT = $(LIBFT_DIR)/libft.a

SRCS = srcs/main.c srcs/utils/check_player.c srcs/parsing/extract_map.c srcs/parsing/extract_data.c srcs/utils/str_and_list_utils.c
SRCS += srcs/utils/init_mlx.c srcs/utils/hooks.c srcs/parsing/parsing.c srcs/parsing/init_map.c srcs/raycasting/player_move.c
SRCS += error/err_msg.c error/free.c srcs/parsing/check_extraction.c srcs/parsing/extract_color.c srcs/utils/init_player.c
SRCS += srcs/utils/init_texture.c error/free_utils.c
SRCS += libft/get_next_line.c libft/get_next_line_utils.c libft/ft_strtok.c srcs/utils/extract_map_utils.c srcs/raycasting/mini_map.c
SRCS += srcs/utils/draw_player.c srcs/raycasting/player_turn.c srcs/utils/init_pos.c srcs/raycasting/raycasting.c srcs/utils/texture.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

NAME = cub3D

all: create_obj_dir libft mlx $(MLX_LIB) $(NAME)
	@echo "$(GREEN)Compilation successful!$(NC)"

create_obj_dir:
	@mkdir -p $(OBJ_DIR)

libft:
	@echo "$(YELLOW)Compiling libft...$(NC)"
	@make -C $(LIBFT_DIR)

mlx:
	@echo "$(YELLOW)Compiling mlx...$(NC)"
	@make -C $(MLX_DIR)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(MLX_LIB):
	@make -s -C $(MLX_DIR)


clean:
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean:
	@make -s -C $(LIBFT_DIR) fclean
	@make -s -C $(MLX_DIR) clean
	@rm -f $(NAME) $(MLX_LIB)
	@rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all create_obj_dir libft mlx clean fclean re
