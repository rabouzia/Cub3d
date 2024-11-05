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

// LINUX
# define UP 115
# define DOWN 119
# define LEFT 97
# define RIGHT 100
// MAC
# define MUP 115
# define MDOWN 119
# define MLEFT 97
# define MRIGHT 100

# define BUFFER_SIZE 10
# define FILE_DESCRIPTORS 256

# define M_PI 3.14159265358979323846

# define RECT_P_SIZE 10
# define RECT_WALL_SIZE 30
# define FOV 60
# define KEYPRESS 2
# define KEYRELEASE 3
# define NUM_TEXTURES 4

# define S_W 1900             // screen width
# define S_H 1000             // screen height3
# define TILE_SIZE 30         // tile size
# define FOV 60               // field of view
# define ROTATION_SPEED 0.045 // rotation speed
# define PLAYER_SPEED 4       // player speed

# define RED_PIXEL 0xFF0000
# define BLUE_PIXEL 0x000000FF
# define GREEN_PIXEL 0X00FF00
# define WHITE_PIXEL 0XFFFFFF
# define GREY_PIXEL 0X808080
# define BLACK_PIXEL 0X000000

typedef enum action
{
	MLX_RELEASE = 0,
	MLX_PRESS = 1,
	MLX_REPEAT = 2,
}					action_t;

typedef enum modifier_key
{
	MLX_SHIFT = 0x0001,
	MLX_CONTROL = 0x0002,
	MLX_ALT = 0x0004,
	MLX_SUPERKEY = 0x0008,
	MLX_CAPSLOCK = 0x0010,
	MLX_NUMLOCK = 0x0020,
}					modifier_key_t;

typedef struct mlx_key_data
{
	action_t		action;
	int32_t			os_key;
	modifier_key_t	modifier;
}					mlx_key_data_t;
typedef struct s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct s_pixel
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}					t_pixel;

typedef struct s_player // the player structure
{
	double plyr_x; // player x position in pixels
	double plyr_y; // player y position in pixels
	double angle;  // player angle
	float fov_rd;  // field of view in radians
	int rot;       // rotation flag
	int l_r;       // left right flag
	int u_d;       // up down flag
}					t_player;

typedef struct s_ray // the ray structure
{
	double ray_ngl;  // ray angle
	double distance; // distance to the wall
	int flag;        // flag for the wall
}					t_ray;

typedef struct s_map_info // the data structure
{
	char **map2d; // the map
	int p_x;      // player x position in the map
	int p_y;      // player y position in the map
	int w_map;    // map width
	int h_map;    // map height
}					t_map_info;

typedef struct s_cube
{
	char			**tab_map;
	int				fd;
	char			**av;
	void			*mlx;
	void			*win;
	bool			inputs[128];
	// struct s_pos	pos;
	t_pixel			pixel;
	t_pixel			image;
	t_map_info		map;
	t_ray ray;       // the ray structure
	t_player player; // the player structure
}					t_cube;

//############ parsing ####################

bool				parsing(t_cube *cube);

int					read_cub(t_cube *data);

int					letter_check(t_cube *m);

int					is_good(char c);

bool				find_direction(char c, int i, int j, t_cube *cube);

//############ minilibx #####################

bool				win_create(t_cube *cube);

bool				minilibx(t_cube *cube);

//############ raycasting ##################

void				move_player(t_cube *cube, double angle);
void				rotate_player(t_cube *cube, int i);
void				hook(t_cube *mlx, double move_x, double move_y);
void				cast_rays(t_cube *mlx);
int					key_press(int key, t_cube *cube);
int					key_release(int key, t_cube *cube);
int					inputs(t_cube *cube);

bool				raycasting(t_cube *cube, double facteur, int color);

//############ mini_libft ###################

char				*ft_strdup(char *str);

void				print_tab(char **tab);

int					ft_strstr(char *str, char *to_find);

int					ft_strlen(char *str);

int					ft_strlcpy(char *dest, char *src, int len);

char				*ft_strjoin(char *s1, char *s2);

void				ft_putstr_fd(char *s, int fd);

char				*get_next_line(int fd);

void				*ft_calloc(size_t n, size_t s);

//############ clean ########################

int					quit_click(t_cube *d);

void				quit_esc(t_cube *d);
void				ft_exit(t_cube *cube);

typedef enum mouse_key
{
	MLX_MOUSE_BUTTON_LEFT = 0,
	MLX_MOUSE_BUTTON_RIGHT = 1,
	MLX_MOUSE_BUTTON_MIDDLE = 2,
}					mouse_key_t;

typedef enum mouse_mode
{
	MLX_MOUSE_NORMAL = 0x00034001,
	MLX_MOUSE_HIDDEN = 0x00034002,
	MLX_MOUSE_DISABLED = 0x00034003,
}					mouse_mode_t;

typedef enum cursor
{
	MLX_CURSOR_ARROW = 0x00036001,
	MLX_CURSOR_IBEAM = 0x00036002,
	MLX_CURSOR_CROSSHAIR = 0x00036003,
	MLX_CURSOR_HAND = 0x00036004,
	MLX_CURSOR_HRESIZE = 0x00036005,
	MLX_CURSOR_VRESIZE = 0x00036006,
}					cursor_t;

// typedef struct mlx_texture
// {
// 	uint32_t	width;
// 	uint32_t	height;
// 	uint8_t		bytes_per_pixel;
// 	uint8_t*	pixels;
// }	mlx_texture_t;

// typedef struct xpm
// {
// 	mlx_texture_t	texture;
// 	int32_t			color_count;
// 	int32_t			cpp;
// 	char			mode;
// }	xpm_t;

// typedef struct mlx_instance
// {
// 	int32_t	x;
// 	int32_t	y;
// 	int32_t	z;
// 	bool	enabled;
// }	mlx_instance_t;

// typedef struct mlx_image
// {
// 	const uint32_t	width;
// 	const uint32_t	height;
// 	uint8_t*		pixels;
// 	mlx_instance_t*	instances;
// 	size_t			count;
// 	bool			enabled;
// 	void*			context;
// }	mlx_image_t;

// typedef struct mlx
// {
// 	void*		window;
// 	void*		context;
// 	int32_t		width;
// 	int32_t		height;
// 	double		delta_time;
// }	mlx_t;

// typedef enum mlx_errno
// {
// 	MLX_SUCCESS = 0,                                     // No Errors
// 	MLX_INVEXT,
// 		// File has an invalid extension
// 	MLX_INVFILE,                                         // File was invalid
// 		/ does not exist.
// 	MLX_INVPNG,
// 		// Something is wrong with the given PNG file.
// 	MLX_INVXPM,
// 		// Something is wrong with the given XPM file.
// 	MLX_INVPOS,
// 		// The specified X/Y positions are out of bounds.
// 	MLX_INVDIM,
// 		// The specified W/H dimensions are out of bounds.
// 	MLX_INVIMG,
// 		// The provided image is invalid,
// 	might indicate mismanagement of images.MLX_VERTFAIL,
// 		// Failed to compile the vertex shader.
// 	MLX_FRAGFAIL,
// 		// Failed to compile the fragment shader.
// 	MLX_SHDRFAIL,
// 		// Failed to compile the shaders.
// 	MLX_MEMFAIL,
// 		// Dynamic memory allocation has failed.
// 	MLX_GLADFAIL,
// 		// OpenGL loader has failed.
// 	MLX_GLFWFAIL,
// 		// GLFW failed to initialize.
// 	MLX_WINFAIL,
// 		// Failed to create a window.
// 	MLX_STRTOOBIG,
// 		// The string is too big to be drawn.
// 	MLX_ERRMAX,                                          // Error count
// }					mlx_errno_t;

// extern mlx_errno_t	mlx_errno;

// typedef enum mlx_settings {
// 	MLX_STRETCH_IMAGE = 0,
// 	// Should images resize with the window as it's being resized or not. Default: false
// 	MLX_FULLSCREEN,

// 		// Should the window be in Fullscreen,
// 	note it will fullscreen at the given resolution.Default : false MLX_MAXIMIZED,
// 		// Start the window in a maximized state,
// 	overwrites the fullscreen state if this is true.Default : false MLX_DECORATED,
// 	// Have the window be decorated with a window bar. Default: true
// 	MLX_HEADLESS, // Run in headless mode,
// 	no window is created.(NOTE
// 							: Still requires some form of window manager such as xvfb)MLX_SETTINGS_MAX,
// 								// Setting count.
// }					mlx_settings_t;

#endif
