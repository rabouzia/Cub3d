#ifndef CUBE_H
# define CUBE_H

# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define MLX_ERROR 0

# define BUFFER_SIZE 10
# define FILE_DESCRIPTORS 256

# define M_PI 3.14159265358979323846

# define RECT_P_SIZE 10
# define RECT_WALL_SIZE 30
# define FOV 60
# define KEYPRESS 2
# define KEYRELEASE 3
# define NUM_TEXTURES 4

# define SCREEN_WIDTH 1900
# define SCREEN_HEIGHT 1000
# define TILE_SIZE 30
# define FOV 60
# define ROTATION_SPEED 0.045
# define PLAYER_SPEED 4

# define RED_PIXEL 0xFF0000
# define BLUE_PIXEL 0x000000FF
# define GREEN_PIXEL 0X00FF00
# define WHITE_PIXEL 0XFFFFFF
# define GREY_PIXEL 0X808080
# define BLACK_PIXEL 0X000000
# define KAKI_PIXEL 0x799623

# define WEST_WALL 0xAA99CC
# define EAST_WALL 0xCCAA99
# define NORTH_WALL 0x5645A0
# define SOUTH_WALL 0x99CCAA

typedef struct s_pixel
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_pixel;

typedef struct s_player
{
	double		plyr_x;
	double		plyr_y;
	double		angle;
	float		fov_rd;
	int			rot;
	int			l_r;
	int			u_d;
}				t_player;

typedef struct s_ray
{
	double		ray_ngl;
	double		distance;
	int			flag;
}				t_ray;

typedef struct s_texture
{
	void		*north;
	void		*south;
	void		*west;
	void		*east;
	int			floor;
	int			ceiling;
}				t_texture;

typedef struct s_map_info
{
	char		**map2d;
	int			p_x;
	int			p_y;
	int			w_map;
	int			h_map;
}				t_map_info;

typedef struct s_cube
{
	char		**tab_map;
	int			fd;
	char		**av;
	void		*mlx;
	void		*win;
	bool		inputs[128];
	t_pixel		pixel;
	t_pixel		image;
	t_map_info	map;
	t_ray		ray;
	t_player	player;
	t_texture	texture;
}				t_cube;

//############ parsing ####################

bool			parsing(t_cube *cube, char **av);

int				read_cub(t_cube *data);

int				letter_check(t_cube *m);

int				is_good(char c);

bool			find_direction(char c, int i, int j, t_cube *cube);

int				setup_win(t_cube *cube);

int				init_argument(t_cube *cube, char **av);

//############ minilibx #####################

bool			win_create(t_cube *cube);

bool			minilibx(t_cube *cube);

//############ key log ##################

int				key_press(int key, t_cube *cube);

int				key_release(int key, t_cube *cube);

int				inputs(t_cube *cube);

double			wrap_angle(double angle);

//############ draw ##################

void			draw_floor_ceiling(t_cube *cube, int ray, int top_pix,
					int bottom_pix);

int				get_color(t_cube *cube, int flag);

void			draw_wall(t_cube *cube, int ray, int t_pix, int b_pix);

void			render_wall(t_cube *cube, int ray);

//############ calculus ##################

int				wall_hit(float x, float y, t_cube *cube);

float			get_horizontal_intersection(t_cube *cube, float angl);

float			get_vertical_intersection(t_cube *cube, float angl);

//############ display ##################

void			ft_display_pixel(t_pixel *pixel, int x, int y, int color);

void			ft_mlx_pixel_put(t_cube *cube, int x, int y, int color);

//############ raycasting ##################

int				inter_check(float angle, float *inter, float *step,
					int is_inter);

int				unit_circle(float angle, char c);

int				game_loop(t_cube *cube);

void			render_wall(t_cube *cube, int ray);

int				raycasting(t_cube *cube);

int				init_the_player(t_cube *cube);

void			move_player(t_cube *cube, double angle);

void			rotate_player(t_cube *cube, int i);

void			cast(t_cube *cube);

int				key_press(int key, t_cube *cube);

int				key_release(int key, t_cube *cube);

int				inputs(t_cube *cube);

int				start_the_game(t_cube *cube);

float			get_horizontal_intersection(t_cube *cube, float angl);

float			get_vertical_intersection(t_cube *cube, float angl);

//############ mini_libft ###################

void			render_wall(t_cube *cube, int ray);

char			*ft_strdup(char *str);

float			nor_angle(float angle);

void			print_tab(char **tab);

int				ft_strstr(char *str, char *to_find);

int				ft_strlen(char *str);

int				ft_strlcpy(char *dest, char *src, int len);

char			*ft_strjoin(char *s1, char *s2);

void			ft_putstr_fd(char *s, int fd);

char			*get_next_line(int fd);

void			*ft_calloc(size_t n, size_t s);

//############ clean ########################

int				quit_click(t_cube *d);

void			quit_esc(t_cube *d);

void			ft_exit(t_cube *cube);

#endif
