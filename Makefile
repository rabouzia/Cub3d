SRC_FILES	=	1.main.c 					\
				2.minilibx.c				\
				3.raycasting.c 				\
				4.clean.c 					\
				5.libft_portable.c 			\
				parsing/1.parsing.c 		\
				parsing/2.check_letter.c	\
				parsing/3.check_format.c	

CFLAGS 		=	-Wall -Wextra -Werror -g3
NAME		=	cube
NAME_MAC	=	cube_MAC
LIBX		=	minilibx-linux/libmlx_Linux.a
LIBX_MAC	=	minilibx-linux/libmlx_Darwin.a
SRC_DIR		=	src
OBJ_DIR		=	obj
INCLUDES	=	inc

# Update SRC to include subdirectories and normalize paths
SRC 		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))
# Transform the source files into object files while preserving directory structure
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Create the corresponding subdirectories in obj for the .o files
OBJ_SUBDIRS	=	$(sort $(dir $(OBJS)))

all: $(NAME)

remac: fclean mac

re: fclean all

mac: $(NAME_MAC)

# Create the obj subdirectories first, then compile
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_SUBDIRS)
	$(CC) $(CFLAGS) -I$(INCLUDES) -c -o $@ $<

# Create obj directories including subdirectories
$(OBJ_SUBDIRS):
	mkdir -p $(OBJ_SUBDIRS)

debug: $(OBJS) $(LIBX) $(LIBFT)
	cc $(CFLAGS) -g3 -gdwarf-4 -L/opt/homebrew/Cellar/libxext/1.3.6/lib -lXext -L/opt/homebrew/Cellar/libx11/1.8.7/lib -lX11 -Lminilibx-linux/ -lmlx $^ -o $(NAME)_debug

$(NAME_MAC): $(OBJS) $(LIBX_MAC) $(LIBFT)
	cc $(CFLAGS) -L/opt/homebrew/Cellar/libxext/1.3.6/lib -lXext -L/opt/homebrew/Cellar/libx11/1.8.7/lib -lX11 -Lminilibx-linux/ -lmlx $^ -o $@

$(NAME): $(OBJS) $(LIBX) $(LIBFT)
	cc $(CFLAGS) -lXext -lX11 -Lminilibx-linux/ -lmlx $^ -o $@

$(LIBX_MAC):
	make -C minilibx-linux/

$(LIBX):
	make -C minilibx-linux/

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(OBJ_DIR) $(NAME) $(NAME)_debug $(NAME_MAC)
	make -C minilibx-linux/ clean

.PHONY: all clean fclean re
