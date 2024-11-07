/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:50:18 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/08 00:52:45 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	word_count(char const *s, char c)
{
	int	count;
	int	on_word;

	count = 0;
	on_word = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (on_word)
			{
				count++;
				on_word = 0;
			}
		}
		else
			on_word = 1;
		s++;
	}
	return (count + on_word);
}

static char	*copy_next_word(char const *s, char c, int *i)
{
	char	*word;
	int		tmp;
	int		j;

	while (s[*i] && s[*i] == c)
		(*i)++;
	tmp = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	word = malloc((*i - tmp + 1) * sizeof(char));
	if (!word)
		return (NULL);
	j = 0;
	while (j < *i - tmp)
	{
		word[j] = s[tmp + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}
char	*ft_strjoin_4(char *s1, char *s2, char *s3, char *s4)
{
	int		i;
	char	*join;

	if (!s1 || !s2 || !s3 || !s4)
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3)
				+ ft_strlen(s4) + 1));
	if (!join)
		return (NULL);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	i--;
	while (s2[++i - ft_strlen(s1)])
		join[i] = s2[i - ft_strlen(s1)];
	i--;
	while (s3[++i - ft_strlen(s1) - ft_strlen(s2)])
		join[i] = s3[i - ft_strlen(s1) - ft_strlen(s2)];
	i--;
	while (s4[++i - ft_strlen(s1) - ft_strlen(s2) - ft_strlen(s3)])
		join[i] = s4[i - ft_strlen(s1) - ft_strlen(s2) - ft_strlen(s3)];
	join[i] = 0;
	return (join);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;
	int		word;
	int		i;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	split = malloc((words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	word = 0;
	while (word < words)
	{
		split[word] = copy_next_word(s, c, &i);
		if (!split[word])
			return (free_tab(split), NULL);
		word++;
	}
	split[words] = NULL;
	return (split);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	if (!n)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

int	nb_ligne(char *file)
{
	int		fd;
	int		i;
	char	*ligne;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	while (1)
	{
		ligne = get_next_line(fd);
		if (!ligne)
			break ;
		free(ligne);
		i++;
	}
	close(fd);
	return (i - 8);
}

int	check_extension(char *line, char *extension)
{
	int	i;
	int	ex_len;

	ex_len = ft_strlen(extension);
	i = 0;
	while (line[i])
		i++;
	if (i < ex_len + 1)
		return (0);
	i -= ex_len;
	return (!strncmp(&line[i], extension, ex_len));
}

int	get_path(t_cube *cube, char *line, void **way)
{
	int	x;
	int	y;

	if (!check_extension(line, ".xpm"))
		return (0);
	*way = mlx_xpm_file_to_image(cube->mlx, line, &x, &y);
	if (!*way)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (!str)
		return (-1);
	if (str[i] == '-')
		return (-1);
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	if (n > 255 || n < 0)
		return (-1);
	return (n);
}

int	get_rgb(t_cube *cube, char *line, unsigned int *way)
{
	char			**color;
	unsigned int	res;
	int				rgb[3];

	(void)cube;
	color = ft_split(line + 3, ',');
	rgb[0] = ft_atoi(color[0]);
	rgb[1] = ft_atoi(color[1]);
	rgb[2] = ft_atoi(color[2]);
	if (rgb[0] == -1 || rgb[1] == -1 || rgb[2] == -1)
		return (0);
	res = rgb[0] * 256 * 256 + rgb[1] * 256 + rgb[2];
	*way = res;
	free_tab(color);
	return (1);
}

int	get_info(t_cube *cube, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
	{
		if (!get_path(cube, line, &cube->texture.north))
			return (printf("Map error\n"), 0);
		return (1);
	}
	if (!ft_strncmp(line, "SO ", 3))
	{
		if (!get_path(cube, line, &cube->texture.south))
			return (printf("Map error\n"), 0);
		return (1);
	}
	if (!ft_strncmp(line, "EA ", 3))
	{
		if (!get_path(cube, line, &cube->texture.east))
			return (printf("Map error\n"), 0);
		return (1);
	}
	if (!ft_strncmp(line, "WE ", 3))
	{
		if (!get_path(cube, line, &cube->texture.west))
			return (printf("Map error\n"), 0);
		return (1);
	}
	if (!ft_strncmp(line, "C ", 2))
	{
		if (!get_rgb(cube, line, &cube->texture.ceiling))
			return (printf("Map error\n"), 0);
		return (1);
	}
	if (!ft_strncmp(line, "F ", 2))
	{
		if (!get_rgb(cube, line, &cube->texture.floor))
			return (printf("Map error\n"), 0);
		return (1);
	}
	return (0);
}

int	read_cub(t_cube *cube)
{
	char	*line;
	int		c;
	int		i;
	int		j;

	c = 0;
	if (!check_extension(cube->av[1], ".cub"))
		return (ft_putstr_fd("Error\nWrong file extension\n", 1), 0);
	i = 0;
	j = nb_ligne(cube->av[1]);
	cube->fd = open(cube->av[1], O_RDONLY, 0664);
	cube->map.map2d = ft_calloc(j + 1, sizeof(char *));
	while (1)
	{
		line = get_next_line(cube->fd);
		c++;
		if (!line)
			break ;
		if (get_info(cube, line) && c < 6)
		// check if the info are all picked and pass to next only if they are in 
			continue ;
		if (c < 7)
		{
			free(line);
			continue ;
		}
		cube->map.map2d[i] = ft_strdup(line);
		free(line);
		i++;
	}
	return (1);
}
int	is_map_valid(t_cube *m)
{
	(void)m;
	// if (!m->map || !(*m->map))
	return (ft_putstr_fd("Error\n Empty map\n", 1), 0);
	// 	if ((m->count.lines / 64 < 5) && m->count.columns / 64 < 5)
	// 		return (return_map_error("Error\n Too small\n", m), 0);
	// 	if ((m->count.lines / 64 > 21) && m->count.columns / 64 > 40)
	// 		return (return_map_error("Error\n Too BIG\n", m), 0);
	// 	if (!size_checking(m))
	// 		return (return_map_error("Error\nWrong size\n", m), 0);
	// 	if (!character_checker(m))
	// 		return (return_map_error("Error\nWrong char\n", m), 0);
	// 	if (!wall_check_up_down(m))
	// 		return (return_map_error("Error\nWrong char up and down\n", m), 0);
	// 	if (!wall_check_side(m))
	// 		return (return_map_error("Error\nWrong side char\n", m), 0);
	// 	if (!check_path(m))
	// 		return (return_map_error("Error\nNo way bro o_o\n", m));
	return (1);
}