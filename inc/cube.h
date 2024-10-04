#ifndef CUBE_H
# define CUBE_H

# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
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
	char 			**map;
	struct s_pos	*pos;
	char			**av;
	void 			*mlx;
	void 			*win;
}					t_game;

#endif