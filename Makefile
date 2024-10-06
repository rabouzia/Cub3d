NAME		=			cube
NAME_MAC	=			cube_MAC

SRC_DIR		=			src
OBJ_DIR		=			obj

SRC_FILES	=			main.c 							\
						minilibx.c						\
						raycasting.c 					\
						clean.c 						\
						libft_portable.c 				\
						parsing/parsing.c 				\
						parsing/check_letter.c			\
						parsing/check_format.c			\
						parsing/get_next_line.c

CC			=			cc
CFLAGS 		=			-Wall -Wextra -Werror -g3 -Iinc

LIBX		=			minilibx-linux/libmlx.a
LIBX_MAC	=			minilibx-linux/libmlx_Darwin.a

SRCS		=			$(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS		=			$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

OBJ_SUBDIRS	=			$(sort $(dir $(OBJS)))

MAKE_DIR	=			mkdir -p

$(OBJ_DIR)/%.o: 		$(SRC_DIR)/%.c
						$(MAKE_DIR) $(dir $@)
						$(CC) $(CFLAGS) -c $< -o $@

all: 					$(NAME)

remac: 					fclean mac

re: 					fclean all

mac: 					$(NAME_MAC)

$(NAME): 				$(OBJS) $(LIBX) $(LIBFT)
						@$(CC) $(CFLAGS) -lXext -lX11 -Lminilibx-linux/ -lmlx $^ -o $@

$(NAME_MAC): 			$(OBJS) $(LIBX_MAC) $(LIBFT)
						$(CC) $(CFLAGS) -L/opt/homebrew/Cellar/libxext/1.3.6/lib -lXext -L/opt/homebrew/Cellar/libx11/1.8.7/lib -lX11 -Lminilibx-linux/ -lmlx $^ -o $@

debug: 					$(OBJS) $(LIBX) $(LIBFT)
						$(CC) $(CFLAGS) -g3 -gdwarf-4 -L/opt/homebrew/Cellar/libxext/1.3.6/lib -lXext -L/opt/homebrew/Cellar/libx11/1.8.7/lib -lX11 -Lminilibx-linux/ -lmlx $^ -o $(NAME)_debug

$(LIBX_MAC):
						@make -C minilibx-linux/

$(LIBX):
						@make -C minilibx-linux/

clean:
						rm -rf $(OBJ_DIR)
						@echo "\033[1;31m======== object files removed ========\033[0m"

fclean: 				clean
						rm -rf $(NAME) $(NAME)_debug $(NAME_MAC)
						@make -C minilibx-linux/ clean
						@echo "\033[1;31m======== executable removed ========\033[0m"

re: 					fclean all

.PHONY: 				all clean fclean re

