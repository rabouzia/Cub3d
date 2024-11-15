/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:35:41 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/15 15:46:37 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"
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

// # define BUFFER_SIZE 1000
# define FILE_DESCRIPTORS 256

# define M_PI 3.14159265358979323846

# define RECT_P_SIZE 10
# define RECT_WALL_SIZE 30
# define FOV 60
# define KEYPRESS 2
# define KEYRELEASE 3
# define NUM_TEXTURES 4
# define TEXTURE_SIZE 64

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

typedef enum s_arg_type
{
	TRASH,
	INFO,
	MAP,
	SPACE,
}					t_arg_type;

typedef struct s_arg
{
	t_arg_type		type;
	char			*content;
	struct s_arg	*next;
}					t_arg;

typedef struct s_pixel
{
	void			*img;
	char			*addr;
	int				pix_w;
	int				pix_h;
	int				bpp;
	int				line_len;
	int				endian;
	unsigned int	f_or_c;
}					t_pixel;

typedef struct s_player
{
	double			plyr_x;
	double			plyr_y;
	double			angle;
	float			fov_rd;
	int				rot;
	int				l_r;
	int				u_d;
}					t_player;

typedef struct s_ray
{
	int				index;
	double			ray_ngl;
	double			horiz_x;
	double			horiz_y;
	double			vert_x;
	double			vert_y;
	double			distance;
	int				flag;
}					t_ray;

typedef struct s_map_info
{
	char			**tab_map;
	int				p_x;
	int				p_y;
	int				rows;
	int				columns;
}					t_map_info;

typedef struct s_cube
{
	int				fd;
	char			**av;
	void			*mlx;
	void			*win;
	bool			inputs[128];
	int				text_count;
	int				color_count;
	t_pixel			image;
	t_map_info		map;
	t_ray			ray;
	t_arg			*arg;
	t_player		player;
	t_pixel			texture_way[6];
}					t_cube;

/*
	texture_way[0] -> texture.north;
	texture_way[1] -> texture.south;
	texture_way[2] -> texture.west;
	texture_way[3] -> texture.east
	texture_way[3] -> texture.floor
	texture_way[3] -> texture.ceil
*/
//############ parsing ####################

int					check_extension(char *line, char *extension);

bool				is_map_valid(t_cube *cube);

int					get_path(t_cube *cube, char *line, t_pixel *p);

int					get_rgb(t_cube *cube, char *line, t_pixel *way);

int					get_info(t_cube *cube, char *line);

bool				parsing(t_cube *cube, char **av);
int					collumlen(char **tab);
int					tab_size(char **tab);

int					read_cub(t_cube *data);

int					letter_check(t_cube *map);

void				fill_info(t_cube *cube);

void				count_row(t_cube *cube);

int					fill_map(t_cube *cube);

bool				flood_fill(char **map);

int					get_lst(t_cube *cube, char *file);

int					flag_line(char *str);

void				count_columns(t_cube *cube);

int					is_good(char c);

bool				find_direction(char c, int i, int j, t_cube *cube);

int					setup_win(t_cube *cube);

int					init_argument(t_cube *cube, char **av);

//############ minilibx #####################

bool				win_create(t_cube *cube);

bool				minilibx(t_cube *cube);

//############ key log ##################

int					key_press(int key, t_cube *cube);

int					key_release(int key, t_cube *cube);

int					inputs(t_cube *cube);

double				wrap_angle(double angle);

//############ draw ##################

void				draw_floor_ceiling(t_cube *cube, int ray, int top_pix,
						int bottom_pix);

int					get_color(t_cube *cube, int flag);

// void				draw_wall(t_cube *cube, int ray, int t_pix, int b_pix);
void				draw_wall(t_cube *cube, int t_pix, int b_pix,
						double wall_h);

void				render_wall(t_cube *cube, int ray);

//############ calculus ##################

int					wall_hit(float x, float y, t_cube *cube);

float				get_horizontal_intersection(t_cube *cube, float angl);

float				get_vertical_intersection(t_cube *cube, float angl);

//############ display ##################

void				ft_display_pixel(t_pixel *pixel, int x, int y, int color);

void				ft_mlx_pixel_put(t_cube *cube, int x, int y, int color);

//############ raycasting ##################

int					inter_check(float angle, float *inter, float *step,
						int is_inter);

int					unit_circle(float angle, char c);

int					game_loop(t_cube *cube);

void				render_wall(t_cube *cube, int ray);

int					raycasting(t_cube *cube);

int					init_the_player(t_cube *cube);

void				move_player(t_cube *cube, double angle);

void				rotate_player(t_cube *cube, int i);

void				cast(t_cube *cube);

int					key_press(int key, t_cube *cube);

int					key_release(int key, t_cube *cube);

int					inputs(t_cube *cube);

int					start_the_game(t_cube *cube);

float				get_horizontal_intersection(t_cube *cube, float angl);

float				get_vertical_intersection(t_cube *cube, float angl);

//############ mini_libft ###################

void				render_wall(t_cube *cube, int ray);

char				**ft_split(char const *s, char c);

int					ft_atoi(const char *str);

int					ft_strncmp(char *s1, char *s2, int n);

void				printarg(t_arg *arg);

char				*ft_strdup(char *str);

float				nor_angle(float angle);

void				print_tab(char **tab);

int					ft_strstr(char *str, char *to_find);

int					ft_strlen(char *str);

int					ft_strlcpy(char *dest, char *src, int len);

char				*ft_strjoin(char *s1, char *s2);

void				ft_putstr_fd(char *s, int fd);

void				*ft_calloc(size_t n, size_t s);

//############ clean ########################

int					quit_click(t_cube *d);

void				quit_esc(t_cube *d);

void				free_tab(char **tab);

void				epur_space(char *str);

//############ lst arg #######################

void				ft_end(t_cube *cube, char *str);

void				ft_argaddback(t_arg **head, t_arg *new);

t_arg				*ft_argnew(char *str, t_arg_type type);

t_arg				*ft_arglast(t_arg *head);

int					ft_argmap(t_arg *arg);

void				ft_argclear(t_arg *arg);

int					reverse_bytes(int c);

#endif
