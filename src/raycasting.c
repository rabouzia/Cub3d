/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:34:44 by ramzerk           #+#    #+#             */
/*   Updated: 2024/10/31 17:55:12 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// typedef struct o_img
// {
//     void	*img;
//     int	*addr;
// 	char	*path;
// 	int		widht;
// 	int		height;
//     int		bpp; /* bits per pixel */
//     int		line_len;
//     int		endian;
// }	t_img_data;

// void    img_pix_put(t_img_data *img, int x, int y, int color)
// {
//     char    pixel;

//     pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
//     (unsigned int)pixel = color;
// }

// void drawing_wall(t_game data, int x, int y)
// {
//     int i;
//     int j;

//     i = y;
//     while (i < y + RECT_WALL_SIZE)
//     {
//         j = x;
//         while (j < x + RECT_WALL_SIZE)
//         {
//             img_pix_put(data->background_img, i, j, BLUE_PIXEL);
//             j++;
//         }
//         ++i;
//     }
// }

// void    draw_wall(t_map_datadata)
// {
//     int    y;
//     int    x;

//     x = 0;
//     y = 0;
//     while(data->map[y])
//     {
//         x = 0;
//         while (data->map[y][x])
//         {
//             if (data->map[y][x] == WALL)
//             {
//                 drawing_wall(data, y * RECT_WALL_SIZE, x * RECT_WALL_SIZE);
//             }
//             x++;
//         }
//         y++;
//     }

// }
// void draw_line(t_img_data img, int x1, int y1, int x2, int y2, int color)
// {
//     int dx = abs(x2 - x1);
//     int dy = abs(y2 - y1);
//     int sx, sy;
//     int err;

//     if (x1 < x2)
//         sx = 1;
//     else
//         sx = -1;

//     if (y1 < y2)
//         sy = 1;
//     else
//         sy = -1;
//     if (dx > dy)
//         err = dx / 2;
//     else
//         err = -dy / 2;
//     int e2;

//     while (1)
//     {
//         img_pix_put(img, x1, y1, color);
//         if (x1 == x2 && y1 == y2)
//             break ;
//         e2 = err;
//         if (e2 > -dx)
//         {
//             err -= dy;
//             x1 += sx;
//         }
//         if (e2 < dy)
//         {
//             err += dx;
//             y1 += sy;
//         }
//     }
// }

// int    draw_player_rect(t_map_datadata)
// {
//     int y;
//     int x;

//     y = data->r_play->y;
//     while (y < data->r_play->y + RECT_P_SIZE)
//     {
//         x = data->r_play->x;
//         while (x < data->r_play->x + RECT_P_SIZE)
//         {
//             img_pix_put(data->background_img, x, y, WHITE_PIXEL);
//             x++;
//         }
//         ++y;
//     }
//     return (0);

// }
// void    draw_background(t_map_data data)
// {
//     // int    y;
//     // int    x;

//     // y = 0;
//     // x = 0;

//     if (data->background_img == NULL)
//     {
//         fprintf(stderr, " get_data_addr fail\n");
//         exit (1);
//     }
//     while (y < SCREEN_WIDHT_SIZE)
//     {
//         x = 0;
//         while (x < SCREEN_HEIGHT_SIZE)
//         {
//             img_pix_put(data->background_img, y, x, BLACK_PIXEL);
//             x++;
//         }
//         y++;
//     }
//     draw_wall(data);
//     y = 0;
//     while (y < SCREEN_WIDHT_SIZE)
//     {
//         x = 0;
//         while (x < SCREEN_HEIGHT_SIZE)
//         {
//             if (x % RECT_WALL_SIZE == 0 || y % RECT_WALL_SIZE == 0)
//                 img_pix_put(data->background_img, y, x, GREY_PIXEL);
//             x++;
//         }
//         y++;
//     }
//     draw_player_rect(data);
//     draw_ray(data);
//     draw_camera(data, data->r_play,  data->draw);
//     mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
//             data->background_img->mlx_img, 0, 0);
// }
// void draw_ray(t_map_datadata)
// {
//     int player_center_x;
//     int player_center_y;
//     double line_length;
//     int line_end_x = 1;
//     int line_end_y  = 1;
//     int x;
//     int y;
//     float a;
//     int i;

//     a = data->r_play->a;
//     line_length = 0.1;
//     player_center_x = data->r_play->x + RECT_P_SIZE / 2;
//     player_center_y = data->r_play->y + RECT_P_SIZE / 2;
//     i = 0;
//     while (i < 60)
//     {
//         a+=0.01;
//         if (a < 0)
//             a += 2 * PI;
//         if (a > 2 * PI)
//             a -= 2 * PI;
//         line_length = 0;
//         while (line_length < 900)
//         {
//             line_end_x = player_center_x + cos(a) * line_length;
//             line_end_y = player_center_y + sin(a) * line_length;
//             y = line_end_y / RECT_WALL_SIZE;
//             x = line_end_x / RECT_WALL_SIZE;
//             if (y < SCREEN_HEIGHT_SIZE && x < SCREEN_WIDHT_SIZE)
//             {
//                 if (data->map[y][x] == WALL)
//                     break ;
//             }
//             line_length+=1.0;
//         }
//         draw_line(data->background_img, player_center_x , player_center_y,
// line_end_x, line_end_y, GREEN_PIXEL);
//         i++;
//     }
// }

void	ft_display(t_pixel *pixel, int x, int y, int color)
{
	char	*dst;

	dst = pixel->addr + (y * pixel->line_len + x * (pixel->bpp / 8));
	*(unsigned int *)dst = color;
}

bool	raycasting(t_game *g)
{
	t_pixel	p;

	p = g->pixel;
	p.img = mlx_new_image(g->mlx, 1920, 1080);
	p.addr = mlx_get_data_addr(p.img, &p.bpp, &p.line_len, &p.endian);
	int i, j;
	i = 0;
	while (i++ < 1920)
	{
		j = 0;
		while (j++ < 1080)
		{
			usleep(10);
			ft_display(&p, i, j, 0x00FF0F00);
		}
		mlx_put_image_to_window(g->mlx, g->win, p.img, 0, 0);
	}
		return (1);
}
