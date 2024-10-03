SRC_FILES	=	main.c 							\



CFLAGS 		=	-Wall -Wextra -Werror
NAME		=	cube
NAME_MAC	=	cube_MAC
LIBX		=	minilibx-linux/libmlx_Linux.a
LIBX_MAC	=	minilibx-linux/libmlx_Darwin.a
SRC_DIR		=	src
OBJ_DIR		=	obj
INCLUDES	=	inc
SRC 		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

remac: fclean mac

re: fclean all

mac: $(NAME_MAC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -g3 -I$(INCLUDES) -c -o $@ $<

debug: $(OBJS) $(LIBX) $(LIBFT)
	cc $(CFLAGS) -g3 -gdwarf-4 -L/opt/homebrew/Cellar/libxext/1.3.6/lib -lXext -L/opt/homebrew/Cellar/libx11/1.8.7/lib -lX11 -Lminilibx-linux/ -lmlx $^ -o $(NAME)_debug

$(NAME_MAC): $(OBJS) $(LIBX_MAC) $(LIBFT)
	 cc $(CFLAGS) -L/opt/homebrew/Cellar/libxext/1.3.6/lib -lXext -L/opt/homebrew/Cellar/libx11/1.8.7/lib -lX11  -Lminilibx-linux/ -lmlx $^ -o $@

$(NAME): $(OBJS) $(LIBX) $(LIBFT)
	cc $(CFLAGS) -lXext -lX11 -Lminilibx-linux/ -lmlx $^ -o $@

$(LIBX_MAC):
	make -C minilibx-linux/

$(LIBX):
	make -C minilibx-linux/

$(OBJ_DIR):
	mkdir obj
	mkdir obj/libft

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf *.o $(NAME) $(NAME)_debug $(NAME_MAC)
	make -C minilibx-linux/ clean

.PHONY: all clean fclean re