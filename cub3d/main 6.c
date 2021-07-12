/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:11:36 by jgim              #+#    #+#             */
/*   Updated: 2021/05/03 18:11:39 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#define not_find_cub_file 1
#define many_argument 2
#define Invalid_argument_save 3
#define Invalid_argument_cub 4
#define Undetermined 0

#define TILE_SIZE 60

#define PI 3.14159265
#define TWO_PI 6.28316530
#define FOV 1.047198
#define HALF_FOV 0.523599

typedef struct s_texture
{
	char *North_texture;
	char *South_texture;
	char *East_texture;
	char *West_texture;
	char *Sprite_texture;
} t_texture;

typedef struct s_ceilingfloor
{
	int ceiling_RGB;
	int floor_RGB;
} t_ceilingfloor;

typedef struct s_error
{
	int resolution;
	int texture;
	int map_line;
	int map_chars;
	int map_malloc;
	int map_blank;
	int player_count;
	int ceiling_floor;
	int sprite_malloc;
} t_error;

typedef struct s_map
{
	int height_map;
	int player_count;
	int sprite_count;
	char **map_line;
} t_map;

typedef struct s_player
{
	int posX;
	int posY;
	int speed;
	int is_valid;
	int plane_dist;
	int direction[3];
	float angle;
	float rotate_speed;
} t_player;

typedef struct s_sprite
{
	int posX;
	int posY;
} t_sprite;

typedef struct s_data
{
	int input_width;
	int input_height;
	char *map_str;
	t_player player;
	t_sprite *sprites;
	t_map map_factor;
	t_error parsing_error;
	t_texture texture;
	t_ceilingfloor ceiling_floor;
} t_data;

int ft_strlen(const char *s);
int check_save_argument(char *save);
int ft_strncmp(const char *s1, const char *s2, size_t n);
void check_argument(int argc, char **argv);
int check_cub_argument(char *cub_file, char *file_extension);
void error_type(int Error_number);
int check_extension(char *check_file, char *large_ext, char *small_ext);
void init_factor_data(t_data *map_data);
void parse_map(t_data *map_data, char *cub);
void is_valid_cub(t_data *map_data, char *line);
void check_factor(t_data *map_data, char *line);
void set_resolution(t_data *map_data, char *line);
int check_resolution(t_data *map_data, char **resolution_factor);
int NSEW_S_factor_check(char *str);
void set_texture_path(t_data *map_data, char *line);
int check_texture(t_data *map_data, char **texture_factor);
int check_texture_overlap(t_data *map_data, char *NSEW_S);
void input_texture(t_data *map_data, char *str, char *texture);
void set_ceiling_floor(t_data *map_data, char *line);
int check_ceiling_floor(t_data *map_data, char **C_F, char **RGB);
void input_RGB(t_data *map_data, char *str, char **RGB);
int check_RGB(char **RGB);
int check_RGB_range(char **RGB);
int check_c_f_overlap(t_data *map_data, char *ceiling_floor);
int count_split(char **split, int check_num);
void free_factor(char **factor);
int check_num_str(char *str);
int ft_strncmp(const char *s1, const char *s2, size_t n);
int ft_strlen(const char *s);
static int ft_delimiter(char const *s, char c);
static void *free_word(char **word);
char **ft_split(char const *s, char c);
int ft_isdigit(int c);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strchr(const char *s, int c);
char *ft_strdup(const char *s1);
char *ft_strjoin(char const *s1, char const *s2);
int n_len(char *s);
int devider(char **paragraph, char **line);
int get_next_line(int fd, char **line);
int ft_atoi(const char *str);
void *ft_memcpy(void *dst, const void *src, size_t num);
int ft_strlcpy(char *dst, const char *src, size_t dstsize);
void the_parsing_check(t_data *map_data);
void parse_error(t_data *map_data);
int print_error(char *err);
void init_player_sprite(t_data *map_data);

int main(int argc, char **argv)
{
	t_data map_data;

	check_argument(argc, argv);
	init_factor_data(&map_data);
	parse_map(&map_data, argv[1]);
}

void check_argument(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc < 2)
		error_type(not_find_cub_file);
	if (argc > 3)
		error_type(many_argument);
	if (argc == 3 && check_save_argument(argv[2]))
		error_type(Invalid_argument_save);
	if (check_extension(argv[1], ".CUB", ".cub"))
		error_type(Invalid_argument_cub);
}

void error_type(int Error_number)
{
	if (Error_number == 1)
		print_error("The .cub file doesn't exist\n");
	else if (Error_number == 2)
		print_error("Too many arguments\n");
	else if (Error_number == 3)
		print_error("only --save should come");
	else if (Error_number == 4)
		print_error("cub_file doesn't exist");
	exit(1);
}

int check_save_argument(char *save)
{
	if (ft_strncmp(save, "--save", 6))
		return (1);
	if (ft_strlen(save) != 6)
		return (1);
	return (0);
}

int check_extension(char *check_file, char *large_ext, char *small_ext)
{
	int file_len;
	int i;

	file_len = ft_strlen(check_file);
	i = file_len - 4;
	if (!check_file)
		return (1);
	if (file_len < 5 || (ft_strncmp(large_ext, check_file + i, 4) && ft_strncmp(small_ext, check_file + i, 4)))
		return (1);
	return (0);
}

void init_factor_data(t_data *map_data)
{
	map_data->input_width = 0;
	map_data->input_height = 0;
	map_data->map_factor.height_map = 0;
	map_data->map_factor.player_count = 0;
	map_data->map_factor.sprite_count = 0;
	map_data->texture.North_texture = 0;
	map_data->texture.South_texture = 0;
	map_data->texture.East_texture = 0;
	map_data->texture.West_texture = 0;
	map_data->texture.Sprite_texture = 0;
	map_data->ceiling_floor.ceiling_RGB;
	map_data->ceiling_floor.floor_RGB;
	map_data->parsing_error.resolution = 0;
	map_data->parsing_error.texture = 0;
	map_data->parsing_error.ceiling_floor = 0;
	map_data->parsing_error.map_line = 0;
	map_data->parsing_error.map_blank = 0;
	map_data->parsing_error.map_chars = 0;
	map_data->parsing_error.map_malloc = 0;
	map_data->parsing_error.sprite_malloc = 0;
}

void parse_map(t_data *map_data, char *cub)
{
	int fd;
	char *line;

	if ((fd = open(cub, O_RDONLY)) < 0)
		error_type(Undetermined);
	while (get_next_line(fd, &line))
	{
		is_valid_cub(map_data, line);
		free(line);
		parse_error(map_data);
	}
	free(line);
	close(fd);
	is_valid_map(map_data, &map_data->map_factor);
	parse_error(map_data);
	init_player_sprite(map_data);
	the_parsing_check(map_data);
}

void init_player_sprite(t_data *map_data)
{
	int i;
	int j;
	int sprite;

	sprite = 0;
	i = -1;
	if (!map_data->map_factor.player_count)
		return (map_data->parsing_error.player_count = 1);
	while (++i < map_data->map_factor.height_map)
	{
		j = -1;
		while (map_data->map_factor.map_line[i][++j])
		{
			if (ft_strchr("NSEW", map_data->map_factor.map_line[i][j]))
				init_player(&map_data->player, &map_data->map_factor.map_line[i][j], i, j);
			else if (map_data->map_factor.map_line[i][j] == '2')
				init_sprites(map_data, sprite++, i, j);
		}
	}
	return (0);
}

void init_player(t_player *player, char *player_char, int row, int col)
{
	if (*player_char == 'N')
		player->angle = 3 * PI / 2;
	else if (*player_char == 'S')
		player->angle = PI / 2;
	else if (*player_char == 'E')
		player->angle = 2 * PI;
	else if (*player_char == 'W')
		player->angle = PI;
	player->posX = row * TILE_SIZE;
	player->posY = col * TILE_SIZE;
	player->speed = 10;
	player->rotate_speed = 2.5 * (PI / 180);
	*player_char = '0';
}

int init_sprites(t_data *map_data, int num, int row, int col)
{
	int sprite_count;

	sprite_count = map_data->map_factor.sprite_count;
	if (num == 0)
		if (!(map_data->sprites = malloc(sizeof(t_sprite) * sprite_count)))
			return (map_data->parsing_error.sprite_malloc = 1);
	map_data->sprites[num].posX = col * TILE_SIZE;
	map_data->sprites[num].posY = row * TILE_SIZE;
}

int is_valid_map(t_data *map_data, t_map *map_factor)
{
	int i;
	int j;
	char map_factor;

	i = -1;
	j = -1;
	while (++i < map_factor->height_map)
	{
		if (!(find_invalid_chars(map_factor->map_line[i], "NSEW 012")))
			return (map_data->parsing_error.map_chars = 1);
		while (map_factor->map_line[i][++j])
		{
			if (ft_strchr("NSEW", map_factor->map_line[i][j]))
				map_factor->player_count += 1;
			if (map_factor->player_count > 1)
				return (map_data->parsing_error.player_count = 1);
			if (!(map_factor->map_line[i][j] == ' ' || !(map_factor->map_line[i][j] == '1')))
				if (check_map_boundary((map_factor), i, j))
					return (map_data->parsing_error.map_blank = 1);
			if (ft_strchr("2", map_factor->map_line[i][j]))
				map_factor->sprite_count += 1;
		}
	}
	return (0);
}

int check_map_boundary(t_map *map_factor, int i, int j)
{
	if (i == 0 || i == map_factor->height_map - 1 || j == 0 || (j == ft_strlen(map_factor->map_line[i]) - 1))
		return (1);
	if (map_factor->map_line[i + 1][j] == ' ' || map_factor->map_line[i - 1][j] == ' ' || map_factor->map_line[i][j + 1] == ' ' || map_factor->map_line[i][j - 1] == ' ')
		return (1);
	return (0);
}

void parse_error(t_data *map_data)
{
	if (!map_data->input_width || !map_data->input_height || map_data->parsing_error.resolution)
		print_error("invalid resolution");
	if (!map_data->texture.North_texture || !map_data->texture.South_texture || !map_data->texture.East_texture || !map_data->texture.West_texture || map_data->parsing_error.texture || map_data->texture.Sprite_texture)
		print_error("invalid texture");
	if (!map_data->ceiling_floor.ceiling_RGB || !map_data->ceiling_floor.floor_RGB || map_data->parsing_error.ceiling_floor)
		print_error("invalid_RGB");
	if (map_data->parsing_error.map_chars)
		print_error("invalid_char");
	if (map_data->parsing_error.map_line)
		print_error("invalid_blankline");
	if (map_data->parsing_error.map_malloc)
		print_error("invalid_memory");
	if (map_data->parsing_error.map_blank)
		print_error("invalid_blank");
	if (!map_data->map_factor.player_count)
		print_error("invalid_player");
	exit_program(map_data);
}

void exit_program(t_data *map_data)
{
	if (map_data->texture.North_texture)
		free(map_data->texture.North_texture);
	if (map_data->texture.South_texture)
		free(map_data->texture.South_texture);
	if (map_data->texture.East_texture)
		free(map_data->texture.East_texture);
	if (map_data->texture.West_texture)
		free(map_data->texture.West_texture);
	if (map_data->texture.Sprite_texture)
		free(map_data->texture.Sprite_texture);
	if (map_data->map_factor.map_line[0])
		free_factor(map_data->map_factor.map_line);
	exit(1);
}

void is_valid_cub(t_data *map_data, char *line)
{
	check_factor(map_data, line);
	read_map(map_data, line);
}

int find_invalid_chars(char *map_factor, const char *factors)
{
	int i;

	i = -1;
	while (map_factor[++i])
	{
		if (!ft_strchr(factors, map_factor[i]))
			return (1);
	}
	return (0);
}

int read_map(t_data *map_data, char *line)
{
	char **temp;
	int i;

	if (!line[0])
		return (map_data->parsing_error.map_line = 1);
	if (!(temp = (char **)malloc(sizeof(char *) * (map_data->map_factor.height_map + 2))))
	{
		free_factor(map_data->map_factor.map_line);
		return (map_data->parsing_error.map_malloc = 1);
	}
	i = -1;
	while (++i < map_data->map_factor.height_map)
		temp[i] = ft_strdup(map_data->map_factor.map_line[i]);
	temp[i] = ft_strdup(line);
	temp[++i] = NULL;
	free_factor(map_data->map_factor.map_line);
	map_data->map_factor.map_line = temp;
	map_data->map_factor.height_map += 1;
	return (0);
}

void check_factor(t_data *map_data, char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		set_resolution(map_data, line);
	else if (NSEW_S_factor_check(line))
		set_texture_path(map_data, line);
	else if ((line[0] == 'C' || line[0] == 'F') && line[1] == ' ')
		set_ceiling_floor(map_data, line);
}

void set_resolution(t_data *map_data, char *line)
{
	char **resolution_factor;

	resolution_factor = ft_split(line, ' ');
	if (check_resolution(map_data, resolution_factor))
		map_data->parsing_error.resolution = 1;
	if (!map_data->parsing_error.resolution)
	{
		map_data->input_width = ft_atoi(resolution_factor[1]);
		map_data->input_height = ft_atoi(resolution_factor[2]);
	}
	line = NULL;
	free_factor(resolution_factor);
}

int check_resolution(t_data *map_data, char **resolution_factor)
{
	if (!count_split(resolution_factor, 3))
		return (1);
	if (check_num_str(resolution_factor[1]) || check_num_str(resolution_factor[2]))
		return (1);
	if (map_data->input_width || map_data->input_height)
		return (1);
	return (0);
}

int NSEW_S_factor_check(char *str)
{
	if (!str || !str[0])
		return (0);
	if (str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
		return (1);
	if (str[0] == 'S' && str[1] == 'O' && str[2] == ' ')
		return (1);
	if (str[0] == 'E' && str[1] == 'A' && str[2] == ' ')
		return (1);
	if (str[0] == 'W' && str[1] == 'E' && str[2] == ' ')
		return (1);
	if (str[0] == 'S' && str[1] == ' ')
		return (1);
	return (0);
}

void set_texture_path(t_data *map_data, char *line)
{
	char **texture_factor;

	texture_factor = ft_split(line, ' ');
	if (check_texture(map_data, texture_factor))
		map_data->parsing_error.texture = 1;
	if (!map_data->parsing_error.texture)
		input_texture(map_data, texture_factor[0], texture_factor[1]);
	line = NULL;
	free_factor(texture_factor);
}

int check_texture(t_data *map_data, char **texture_factor)
{
	if (!count_split(texture_factor, 2))
		return (1);
	if (check_extension(texture_factor[1], ".XPM", ".xpm"))
		return (1);
	if (check_texture_overlap(map_data, texture_factor[0]))
		return (1);
	return (0);
}

int check_texture_overlap(t_data *map_data, char *NSEW_S)
{
	if (NSEW_S[0] == 'N' && map_data->texture.North_texture)
		return (1);
	else if (NSEW_S[0] == 'S' && NSEW_S[1] == 'O' && map_data->texture.South_texture)
		return (1);
	else if (NSEW_S[0] == 'E' && map_data->texture.East_texture)
		return (1);
	else if (NSEW_S[0] == 'W' && map_data->texture.West_texture)
		return (1);
	else if (NSEW_S[0] == 'S' && !NSEW_S[1] && map_data->texture.Sprite_texture)
		return (1);
	return (0);
}

void input_texture(t_data *map_data, char *str, char *texture)
{
	if (str[0] == 'N' && str[1] == 'O')
		map_data->texture.North_texture = ft_strdup(texture);
	else if (str[0] == 'S' && str[1] == 'O')
		map_data->texture.South_texture = ft_strdup(texture);
	else if (str[0] == 'E')
		map_data->texture.East_texture = ft_strdup(texture);
	else if (str[0] == 'W')
		map_data->texture.West_texture = ft_strdup(texture);
	else if (str[0] == 'S' && !str[1])
		map_data->texture.Sprite_texture = ft_strdup(texture);
}

void set_ceiling_floor(t_data *map_data, char *line)
{
	char **C_F_factor;
	char **C_F_RGB;

	C_F_factor = ft_split(line, ' ');
	C_F_RGB = ft_split(C_F_factor[1], ',');
	if (check_ceiling_floor(map_data, C_F_factor, C_F_RGB))
		map_data->parsing_error.ceiling_floor = 1;
	if (!map_data->parsing_error.ceiling_floor)
		input_RGB(map_data, C_F_factor[0], C_F_RGB);
	line = NULL;
	free_factor(C_F_factor);
}

int check_ceiling_floor(t_data *map_data, char **C_F, char **RGB)
{
	if (!count_split(C_F, 2))
		return (1);
	if (check_c_f_overlap(map_data, C_F[0]))
		return (1);
	if (check_RGB(RGB))
		return (1);
	return (0);
}

void input_RGB(t_data *map_data, char *str, char **RGB)
{
	int temp_RGB;

	temp_RGB = ft_atoi(RGB[0]) * 65536 + ft_atoi(RGB[1]) * 256 + ft_atoi(RGB[2]);
	if (str[0] == 'C')
		map_data->ceiling_floor.ceiling_RGB = temp_RGB;
	else if (str[0] == 'F')
		map_data->ceiling_floor.floor_RGB = temp_RGB;
}

int check_RGB(char **RGB)
{
	if (!count_split(RGB, 3))
		return (1);
	if (check_num_str(RGB[0]) || check_num_str(RGB[1]) || check_num_str(RGB[2]))
		return (1);
	if (check_RGB_range(RGB))
		return (1);
	return (0);
}

int check_RGB_range(char **RGB)
{
	int RGB_red;
	int RGB_green;
	int RGB_blue;

	RGB_red = ft_atoi(RGB[0]);
	RGB_green = ft_atoi(RGB[1]);
	RGB_blue = ft_atoi(RGB[2]);
	if (RGB_red < 0 || RGB_red > 255)
		return (1);
	if (RGB_green < 0 || RGB_green > 255)
		return (1);
	if (RGB_blue < 0 || RGB_blue > 255)
		return (1);
	return (0);
}

int check_c_f_overlap(t_data *map_data, char *ceiling_floor)
{
	if (ceiling_floor[0] == 'C' && map_data->ceiling_floor.ceiling_RGB)
		return (1);
	if (ceiling_floor[0] == 'F' && map_data->ceiling_floor.floor_RGB)
		return (1);
	return (0);
}

int count_split(char **split, int check_num)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	if (i == check_num)
		return (1);
	return (0);
}

void free_factor(char **factor)
{
	int i;

	i = -1;
	while (factor[++i])
		free(factor[i]);
	free(factor);
}

int check_num_str(char *str)
{
	int i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (ft_strlen(str) != i)
		return (1);
	return (0);
}
///////////// get_next_line_utilty ///////////////////

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1) && str1[i] != 0 && str2[i] != 0)
	{
		if (str1[i] > str2[i])
			return (1);
		else if (str1[i] < str2[i])
			return (-1);
		i++;
	}
	if (str1[i] == str2[i])
		return (0);
	else if (str1[i] > str2[i])
		return (1);
	return (-1);
}

///////////////////////// split ////////////////////////////

static int ft_delimiter(char const *s, char c)
{
	int count;
	int i;

	i = 0;
	count = 0;
	if (s[i] == 0)
		return (0);
	while (s[i] != 0)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void *free_word(char **word)
{
	int i;
	i = 0;
	while (word[i])
	{
		free(word[i]);
		i++;
	}
	free(word);
	return (0);
}

char **ft_split(char const *s, char c)
{
	char **src;
	int end;
	int j;
	int start;

	j = 0;
	end = 0;
	if (!s)
		return (0);
	if (!(src = (char **)malloc(sizeof(char *) * (ft_delimiter(s, c) + 1))))
		return (0);
	while (s[end] == c)
		++end;
	while (s[end] && j < ft_delimiter(s, c))
	{
		start = end;
		while (s[end] != c && s[end])
			end++;
		if (!(src[j++] = ft_substr(s, start, end - start)))
			return (free_word(src));
		while (s[end] == c)
			end++;
	}
	src[j] = 0;
	return (src);
}
///////////////////////// split ////////////////////////////

int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char *ft_strdup(const char *s1)
{
	int i;
	int len;
	char *dup;

	len = 0;
	while (s1[len])
		len++;
	dup = malloc(len + 1);
	if (dup)
	{
		i = 0;
		while (s1[i])
		{
			dup[i] = s1[i];
			i++;
		}
		dup[i] = '\0';
	}
	return (dup);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t s_len;
	char *str;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_strdup(""));
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

////////////////// get_next_line /////////////////////////
int n_len(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			break;
		i++;
	}
	return (i);
}

int devider(char **paragraph, char **line)
{
	char *temp;

	if (n_len(*paragraph) < ft_strlen(*paragraph))
	{
		*line = ft_substr(*paragraph, 0, n_len(*paragraph));
		temp = ft_substr(*paragraph, n_len(*paragraph) + 1, ft_strlen(*paragraph));
		free(*paragraph);
		*paragraph = ft_strdup(temp);
		free(temp);
		return (1);
	}
	else
	{
		*line = ft_strdup(*paragraph);
		free(*paragraph);
		*paragraph = 0;
		return (0);
	}
}

int get_next_line(int fd, char **line)
{
	static char *paragraph[OPEN_MAX];
	char buf[BUFFER_SIZE + 1];
	int rd_byte;
	char *temp;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while ((rd_byte = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rd_byte] = '\0';
		if (!paragraph[fd])
			paragraph[fd] = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(paragraph[fd], buf);
			free(paragraph[fd]);
			paragraph[fd] = temp;
		}
		if (ft_strchr(paragraph[fd], '\n'))
			break;
	}
	if (rd_byte < 0)
		return (-1);
	else if (rd_byte == 0 && paragraph[fd] == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (devider(&paragraph[fd], line));
}

int ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == 0 && *s != c)
		return (0);
	return ((char *)s);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	int s1_len;
	int s2_len;
	char *str;
	int i;
	int j;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = -1;
	if (!(str = malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}

int ft_atoi(const char *str)
{
	int sign;
	long result;
	int i;

	i = 0;
	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
		i++;
	}
	if (i > 20)
		return ((sign == 1) ? -1 : 0);
	return (sign * result);
}

int ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t len;

	if (!dst || !src)
		return (0);
	i = ft_strlen(src);
	if (!dst)
		return (ft_strlen(src));
	if (dstsize)
	{
		len = (i >= dstsize) ? dstsize - 1 : i;
		ft_memcpy(dst, src, len);
		dst[len] = '\0';
	}
	return (i);
}

void *ft_memcpy(void *dst, const void *src, size_t num)
{
	unsigned char *dest;
	unsigned char *source;
	size_t i;

	if (!dst && !src)
		return (0);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	while (i < num)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}

void the_parsing_check(t_data *map_data)
{
	printf("R : W = %d, H = %d\n", map_data->input_width, map_data->input_height);
	printf("NO : %s\n", map_data->texture.North_texture);
	printf("SO : %s\n", map_data->texture.South_texture);
	printf("EA : %s\n", map_data->texture.East_texture);
	printf("WE : %s\n", map_data->texture.West_texture);
	printf("S : %s\n", map_data->texture.Sprite_texture);
	printf("C : %d\n", map_data->ceiling_floor.ceiling_RGB);
	printf("F : %d\n", map_data->ceiling_floor.floor_RGB);
}

int print_error(char *err)
{
	write(1, "Error\n", 6);
	write(1, err, ft_strlen(err));
	write(1, "\n", 1);
	return (1);
}

void change_blank_to_wall(char **is_blank_wall)
{
	int i;
	int map_len;
	char *is_wall;

	i = -1;
	map_len = ft_strlen(is_blank_wall);
	while (++i < map_len)
	{
		if (is_blank_wall[i] == ' ')
			is_blank_wall[i] = '1';
	}
}
