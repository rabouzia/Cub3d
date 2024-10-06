#ifndef CUBE_H
# define CUBE_H

# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>
# include <unistd.h>

# define MLX_ERROR 0
# define UP 115
# define DOWN 119
# define LEFT 97
# define RIGHT 100

typedef struct s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct s_game
{
	char			**map;
	struct s_pos	pos;
	int				fd;
	char			**av;
	void			*mlx;
	void			*win;
}					t_game;

//############ parsing ####################

bool				parsing(t_game *game);

int					read_cub(t_game *data);

int					letter_check(t_game *m);

int					is_good(char c, int i, int j, t_game *game);

bool				find_direction(char c, int i, int j, t_game *game);

int					ft_strstr(char *str, char *to_find);


//############ minilibx #####################

bool				win_create(t_game *game);

bool				minilibx(t_game *game);

//############ raycasting ##################

bool				raycasting(t_game *game);

//############ mini_libft ###################

char				*ft_strdup(char *str);

//############ clean ########################

int					quit_click(t_game *d);

void				quit_esc(t_game *d);


#endif
