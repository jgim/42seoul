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

// #include <stdlib.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include <limits.h>
// #include <stdio.h>
// #include "mlx.h"
// #include <math.h>

// #ifndef BUFFER_SIZE
// #define BUFFER_SIZE 42
// #endif

// #define X 0
// #define Y 1

// #define not_find_cub_file 1
// #define many_argument 2
// #define Invalid_argument_save 3
// #define Invalid_argument_cub 4
// #define Undetermined 0

// #define TILE_SIZE 60

// #define PI 3.14159265
// #define TWO_PI 6.28316530
// #define FOV 1.047198
// #define HALF_FOV 0.523599

// #define North 0
// #define South 1
// #define East 2
// #define West 3
// #define Sprite 4

// #define ESC_KEY 53

// #define RIGHT 124
// #define LEFT 123
// #define UP 126
// #define DOWN 125

// #define W 13
// #define S 1
// #define A 0
// #define D 2

// #define KEY_PRESS_EVENT 2
// #define DESTROY_EVENT 17

// typedef struct s_texture
// {
// 	char *path;
// 	void *img;
// 	void *img_data;
// 	int bits_per_pixel;
// 	int size_line;
// 	int endian;
// 	int *data;
// 	int width;
// 	int height;
// 	int tex_x;
// 	int tex_y;
// 	int color;
// } t_texture;

// typedef struct s_ceilingfloor
// {
// 	int ceiling_RGB;
// 	int floor_RGB;
// } t_ceilingfloor;

// typedef struct s_error
// {
// 	int resolution;
// 	int texture;
// 	int map_chars;
// 	int map_malloc;
// 	int map_blank;
// 	int player_count;
// 	int ceiling_floor;
// 	int sprite_malloc;
// 	int data_type;
// } t_error;

// typedef struct s_map
// {
// 	int read_map;
// 	int valid_map;
// 	int height_map;
// 	int player_count;
// 	int sprite_count;
// 	char **map_line;
// } t_map;

// typedef struct s_player
// {
// 	int pos[2];
// 	int speed;
// 	double dir[2];
// 	double plane[2];
// 	float angle;
// 	float rotate;
// } t_player;

// typedef struct s_point
// {
// 	double x;
// 	double y;
// } t_point;

// typedef struct s_sprite
// {
// 	t_texture texture;
// 	int pos[2];
// 	double distance;
// 	int center[2];
// 	double inv_det;
// 	double tf[2];
// 	int height;
// 	int width;
// 	double draw_start[2];
// 	double draw_end[2];
// 	int screen_x;
// 	int visible;
// } t_sprite;

// typedef struct s_ray
// {
// 	int x;
// 	double *buffer;
// 	int width;
// 	int height;
// 	int map[2];
// 	double camera_x;
// 	double ray_dir[2];
// 	double side_dist[2];
// 	double delta_dist[2];
// 	double perp_wall_dist;
// 	double step[2];
// 	int hit;
// 	int side;
// 	double wall_X;
// 	int tex[2];
// 	double tex_step;
// 	double tex_pos;
// 	double floor_wall[2];
// 	double current_dist;
// 	double current_floor[2];
// 	int floor_tex[2];
// } t_ray;

// typedef struct s_line
// {
// 	int height;
// 	int start;
// 	int end;
// } t_line;

// typedef struct s_data
// {
// 	int update;
// 	int key_value;
// 	int save;
// 	int input_width;
// 	int input_height;
// 	char *map_str;
// 	void *mlx_ptr;
// 	void *win_ptr;
// 	t_ray ray;
// 	t_player player;
// 	t_sprite *sprite;
// 	t_map map_factor;
// 	t_error parsing_error;
// 	t_texture texture[5];
// 	t_ceilingfloor ceiling_floor;
// } t_data;

// int ft_strlen(const char *s);
// int check_save_argument(char *save);
// int ft_strncmp(const char *s1, const char *s2, int n);
// void check_argument(int argc, char **argv);
// int check_cub_argument(char *cub_file, char *file_extension);
// void error_type(int Error_number);
// int check_extension(char *check_file, char *large_ext, char *small_ext);
// void init_factor_data(t_data *map_data);
// void parse_map(t_data *map_data, char *cub);
// int is_valid_cub(t_data *map_data, char *line);
// int check_factor(t_data *map_data, char *line);
// void set_resolution(t_data *map_data, char *line);
// int check_resolution(t_data *map_data, char **resolution_factor);
// int NSEW_S_factor_check(char *str);
// void set_texture_path(t_data *map_data, char *line);
// int check_texture(t_data *map_data, char **texture_factor);
// int check_texture_overlap(t_data *map_data, char *NSEW_S);
// void input_texture(t_data *map_data, char *str, char *texture);
// void set_ceiling_floor(t_data *map_data, char *line);
// int check_ceiling_floor(t_data *map_data, char **C_F, char **RGB);
// void input_RGB(t_data *map_data, char *str, char **RGB);
// int check_RGB(char **RGB);
// int check_RGB_range(char **RGB);
// int check_c_f_overlap(t_data *map_data, char *ceiling_floor);
// int count_split(char **split, int check_num);
// void free_factor(char **factor);
// int check_num_str(char *str);
// int ft_strncmp(const char *s1, const char *s2, int n);
// int ft_strlen(const char *s);
// static int ft_delimiter(char const *s, char c);
// static void *free_word(char **word);
// char **ft_split(char const *s, char c);
// int ft_isdigit(int c);
// char *ft_substr(char const *s, unsigned int start, int len);
// int ft_strchr(const char *s, int c);
// char *ft_strdup(const char *s1);
// char *ft_strjoin(char const *s1, char const *s2);
// int n_len(char *s);
// int devider(char **paragraph, char **line);
// int get_next_line(int fd, char **line);
// int ft_atoi(const char *str);
// void *ft_memcpy(void *dst, const void *src, int num);
// int ft_strlcpy(char *dst, const char *src, int dstsize);
// void parse_error(t_data *map_data);
// int print_error(char *err);
// int init_player_sprite(t_data *map_data);
// void init_player(t_player *player, char *player_char, int row, int col);
// int init_sprite(t_data *map_data, int num, int row, int col);
// int is_valid_map(t_data *map_data, t_map *map_factor);
// int check_map_boundary(t_map *map_factor, int i, int j);
// int find_invalid_chars(char *map_factor, const char *factors);
// int read_map(t_data *map_data, char *line);
// int exit_program(t_data *map_data);
// int check_blank_one(t_data *map_data, char *line);
// void parse_map_error(t_data *map_data);
// int check_parsed(t_data *map_data);
// void game_start(t_data *map_data);
// void init_game(t_data *map_data);
// int bind_keys(int key_code, t_data *map_data);
// int loop_game(t_data *map_data);
// void set_screen(t_data *map_data);
// void get_image(t_data *map_data);
// void set_ray(t_ray *ray, t_player *player);
// void set_raycasting(t_ray *ray, t_player *player);
// void hit_point(t_data *map_data, t_ray *ray);
// void measure_distance(t_ray *ray, t_player *player);
// void draw_line(t_data *map_data, t_line *line);
// void get_texture(t_data *map_data, t_ray *ray, t_texture *wall_img);
// void draw_image(t_player *player, t_ray *ray, t_texture *wall_img, t_line *line);
// void get_pixel_image(t_data *map_data, t_line *line, t_texture *screen, t_texture *wall_img);
// void get_item(t_data *map_data, t_texture *screen);
// void calculate_distance(t_data *map_data, t_sprite *sprite, t_player *player);
// void reset_player(t_data *map_data);
// void raycast_screen(t_data *map_data);
// void move_right_left(t_data *map_data, t_player *player);
// void move_forward_backward(t_data *map_data, t_player *player);
// void turn_right_left(t_data *map_data, t_player *player);
// int init_sprite(t_data *map_data, int num, int row, int col);
// void get_sprite_image(t_data *map_data, t_sprite *sprite, int sprite_count);
// void player_direction(t_player *player, char *player_char);
// void get_texture_image(t_data *map_data);
// void turn_right_left(t_data *map_data, t_player *player);
// void init_screen(t_data *map_data, t_texture *screen);
// void calculate_rend_sprite(t_data *data, t_sprite *s, t_player *p);
// void *ft_memmove(void *dst, const void *src, int size);
// void sort_sprite(t_data *map_data, t_sprite *sprite);
// void fill_item_color(t_data *data, t_sprite *s, t_texture *img, t_texture *screen);

// int main(int argc, char **argv)
// {
// 	t_data map_data;

// 	check_argument(argc, argv);
// 	init_factor_data(&map_data);
// 	parse_map(&map_data, argv[1]);
// 	if (argc == 3)
// 		map_data.save = 1;
// 	game_start(&map_data);
// }

// void check_argument(int argc, char **argv)
// {
// 	int i;

// 	i = 0;
// 	if (argc < 2)
// 		error_type(not_find_cub_file);
// 	if (argc > 3)
// 		error_type(many_argument);
// 	if (argc == 3 && check_save_argument(argv[2]))
// 		error_type(Invalid_argument_save);
// 	if (check_extension(argv[1], ".CUB", ".cub"))
// 		error_type(Invalid_argument_cub);
// }

// void error_type(int Error_number)
// {
// 	if (Error_number == 1)
// 		print_error("The .cub file doesn't exist\n");
// 	else if (Error_number == 2)
// 		print_error("Too many arguments\n");
// 	else if (Error_number == 3)
// 		print_error("only --save should come");
// 	else if (Error_number == 4)
// 		print_error("cub_file doesn't exist");
// 	exit(1);
// }

// int check_save_argument(char *save)
// {
// 	if (ft_strncmp(save, "--save", 6))
// 		return (1);
// 	if (ft_strlen(save) != 6)
// 		return (1);
// 	return (0);
// }

// int check_extension(char *check_file, char *large_ext, char *small_ext)
// {
// 	int file_len;
// 	int i;

// 	file_len = ft_strlen(check_file);
// 	i = file_len - 4;
// 	if (!check_file)
// 		return (1);
// 	if (file_len < 5 || (ft_strncmp(large_ext, check_file + i, 4) && ft_strncmp(small_ext, check_file + i, 4)))
// 		return (1);
// 	return (0);
// }

// void init_factor_data(t_data *map_data)
// {
// 	map_data->input_width = 0;
// 	map_data->input_height = 0;
// 	map_data->map_factor.read_map = 0;
// 	map_data->map_factor.valid_map = 0;
// 	map_data->map_factor.height_map = 0;
// 	map_data->map_factor.player_count = 0;
// 	map_data->map_factor.sprite_count = 0;
// 	map_data->texture[North].path = 0;
// 	map_data->texture[South].path = 0;
// 	map_data->texture[East].path = 0;
// 	map_data->texture[West].path = 0;
// 	map_data->texture[Sprite].path = 0;
// 	map_data->ceiling_floor.ceiling_RGB = -1;
// 	map_data->ceiling_floor.floor_RGB = -1;
// 	map_data->parsing_error.resolution = 0;
// 	map_data->parsing_error.texture = 0;
// 	map_data->parsing_error.ceiling_floor = 0;
// 	map_data->parsing_error.map_blank = 0;
// 	map_data->parsing_error.map_chars = 0;
// 	map_data->parsing_error.map_malloc = 0;
// 	map_data->parsing_error.sprite_malloc = 0;
// 	map_data->parsing_error.player_count = 0;
// 	map_data->parsing_error.data_type = 0;
// 	map_data->player.pos[X] = 0;
// 	map_data->player.pos[Y] = 0;
// 	map_data->map_factor.read_map = 0;
// }

// void parse_map(t_data *map_data, char *cub)
// {
// 	int i;
// 	int fd;
// 	char *line;
// 	int gnl_check;

// 	if ((fd = open(cub, O_RDONLY)) < 0)
// 		error_type(Undetermined);
// 	while ((gnl_check = get_next_line(fd, &line)) >= 0)
// 	{
// 		is_valid_cub(map_data, line);
// 		free(line);
// 		if (!gnl_check || map_data->parsing_error.data_type)
// 			break;
// 	}
// 	close(fd);
// 	parse_error(map_data);
// 	is_valid_map(map_data, &map_data->map_factor);
// 	parse_map_error(map_data);
// }

// int is_valid_cub(t_data *map_data, char *line)
// {
// 	if (check_factor(map_data, line))
// 		return (1);
// 	if (*line == '1' || *line == ' ')
// 	{
// 		if (!check_parsed(map_data))
// 			return (map_data->parsing_error.data_type = 1);
// 		if (!map_data->map_factor.read_map)
// 			map_data->map_factor.read_map = 1;
// 	}
// 	else if (*line != '\0' && map_data->map_factor.read_map == 0)
// 		return (map_data->parsing_error.data_type = 1);
// 	read_map(map_data, line);
// 	return (0);
// }

// int check_parsed(t_data *map_data)
// {
// 	if (!map_data->input_width || !map_data->input_height || map_data->parsing_error.resolution)
// 		return (0);
// 	if (!map_data->texture[North].path || !map_data->texture[South].path || !map_data->texture[East].path || !map_data->texture[West].path || map_data->parsing_error.texture || !map_data->texture[Sprite].path)
// 		return (0);
// 	if (map_data->ceiling_floor.ceiling_RGB == -1 || map_data->ceiling_floor.floor_RGB == -1 || map_data->parsing_error.ceiling_floor)
// 		return (0);
// 	if (map_data->parsing_error.map_malloc)
// 		return (0);
// 	return (1);
// }

// int check_blank_one(t_data *map_data, char *line)
// {
// 	if (line[0] == ' ' || line[0] == '1')
// 		return (map_data->map_factor.valid_map = 1);
// 	return (0);
// }

int is_valid_map(t_data *map_data, t_map *map_factor)
{
	int i;
	int j;

	i = -1;
	while (++i < map_factor->height_map)
	{
		if (find_invalid_chars(map_factor->map_line[i], "NSEW 012"))
			return (map_data->parsing_error.map_chars = 1);
		j = -1;
		while (map_factor->map_line[i][++j])
		{
			if (ft_strchr("NSEW", map_factor->map_line[i][j]))
				map_factor->player_count += 1;
			if (map_factor->player_count > 1)
				return (map_data->parsing_error.player_count = 1);
			if (!(map_factor->map_line[i][j] == ' ') && !(map_factor->map_line[i][j] == '1'))
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
	if (map_factor->map_line[i + 1][j] == ' ' || map_factor->map_line[i + 1][j] == '\0' || map_factor->map_line[i - 1][j] == ' ' || map_factor->map_line[i - 1][j] == '\0' || map_factor->map_line[i][j + 1] == ' ' || map_factor->map_line[i][j + 1] == '\0' || map_factor->map_line[i][j - 1] == ' ' || map_factor->map_line[i][j - 1] == '\0')
		return (1);
	return (0);
}

// void parse_error(t_data *map_data)
// {
// 	int exit_process;

// 	exit_process = 0;
// 	if (!map_data->input_width || !map_data->input_height || map_data->parsing_error.resolution)
// 		exit_process = print_error("invalid resolution");
// 	if (!map_data->texture[North].path || !map_data->texture[South].path || !map_data->texture[East].path || !map_data->texture[West].path || map_data->parsing_error.texture || !map_data->texture[Sprite].path)
// 		exit_process = print_error("invalid texture");
// 	if (map_data->ceiling_floor.ceiling_RGB == -1 || map_data->ceiling_floor.floor_RGB == -1 || map_data->parsing_error.ceiling_floor)
// 		exit_process = print_error("invalid_RGB");
// 	if (map_data->parsing_error.map_malloc)
// 		exit_process = print_error("invalid_memory");
// 	if (map_data->parsing_error.data_type)
// 		exit_process = print_error("invalid format");
// 	if (exit_process)
// 		exit_program(map_data);
// }

// void parse_map_error(t_data *map_data)
// {
// 	int exit_process;

// 	exit_process = 0;

// 	if (map_data->parsing_error.map_chars)
// 		exit_process = print_error("invalid_char");
// 	if (map_data->parsing_error.map_malloc)
// 		exit_process = print_error("invalid_memory");
// 	if (map_data->parsing_error.map_blank)
// 		exit_process = print_error("invalid_blank");
// 	if (map_data->parsing_error.player_count)
// 		exit_process = print_error("invalid_player");
// 	if (map_data->parsing_error.sprite_malloc)
// 		exit_process = print_error("invalid_memory");
// 	if (exit_process)
// 		exit_program(map_data);
// }

int exit_program(t_data *map_data)
{
	if (map_data->texture[North].path)
		free(map_data->texture[North].path);
	if (map_data->texture[South].path)
		free(map_data->texture[South].path);
	if (map_data->texture[East].path)
		free(map_data->texture[East].path);
	if (map_data->texture[West].path)
		free(map_data->texture[West].path);
	if (map_data->texture[Sprite].path)
		free(map_data->texture[Sprite].path);
	if (map_data->map_factor.map_line)
		free_factor(map_data->map_factor.map_line);
	exit(1);
	return (0);
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
	int j;

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
	if (map_data->map_factor.map_line)
		free_factor(map_data->map_factor.map_line);
	map_data->map_factor.map_line = temp;
	map_data->map_factor.height_map += 1;
	return (0);
}

int check_factor(t_data *map_data, char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
	{
		set_resolution(map_data, line);
		return (1);
	}
	else if (NSEW_S_factor_check(line))
	{
		set_texture_path(map_data, line);
		return (1);
	}
	else if ((line[0] == 'C' || line[0] == 'F') && line[1] == ' ')
	{
		set_ceiling_floor(map_data, line);
		return (1);
	}
	return (0);
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

// void set_texture_path(t_data *map_data, char *line)
// {
// 	char **texture_factor;

// 	texture_factor = ft_split(line, ' ');
// 	if (check_texture(map_data, texture_factor))
// 		map_data->parsing_error.texture = 1;
// 	if (!map_data->parsing_error.texture)
// 		input_texture(map_data, texture_factor[0], texture_factor[1]);
// 	line = NULL;
// 	free_factor(texture_factor);
// }

// int check_texture(t_data *map_data, char **texture_factor)
// {
// 	if (!count_split(texture_factor, 2))
// 		return (1);
// 	if (check_extension(texture_factor[1], ".XPM", ".xpm"))
// 		return (1);
// 	if (check_texture_overlap(map_data, texture_factor[0]))
// 		return (1);
// 	return (0);
// }

// int check_texture_overlap(t_data *map_data, char *NSEW_S)
// {
// 	if (NSEW_S[0] == 'N' && map_data->texture[North].path)
// 		return (1);
// 	else if (NSEW_S[0] == 'S' && NSEW_S[1] == 'O' && map_data->texture[South].path)
// 		return (1);
// 	else if (NSEW_S[0] == 'E' && map_data->texture[East].path)
// 		return (1);
// 	else if (NSEW_S[0] == 'W' && map_data->texture[West].path)
// 		return (1);
// 	else if (NSEW_S[0] == 'S' && !NSEW_S[1] && map_data->texture[Sprite].path)
// 		return (1);
// 	return (0);
// }

// void input_texture(t_data *map_data, char *str, char *texture)
// {
// 	if (str[0] == 'N' && str[1] == 'O')
// 		map_data->texture[North].path = ft_strdup(texture);
// 	else if (str[0] == 'S' && str[1] == 'O')
// 		map_data->texture[South].path = ft_strdup(texture);
// 	else if (str[0] == 'E')
// 		map_data->texture[East].path = ft_strdup(texture);
// 	else if (str[0] == 'W')
// 		map_data->texture[West].path = ft_strdup(texture);
// 	else if (str[0] == 'S' && !str[1])
// 		map_data->texture[Sprite].path = ft_strdup(texture);
// }

// void set_ceiling_floor(t_data *map_data, char *line)
// {
// 	char **C_F_factor;
// 	char **C_F_RGB;

// 	C_F_factor = ft_split(line, ' ');
// 	C_F_RGB = ft_split(C_F_factor[1], ',');
// 	if (check_ceiling_floor(map_data, C_F_factor, C_F_RGB))
// 		map_data->parsing_error.ceiling_floor = 1;
// 	if (!map_data->parsing_error.ceiling_floor)
// 		input_RGB(map_data, C_F_factor[0], C_F_RGB);
// 	line = NULL;
// 	free_factor(C_F_factor);
// }

// int check_ceiling_floor(t_data *map_data, char **C_F, char **RGB)
// {
// 	if (!count_split(C_F, 2))
// 		return (1);
// 	if (check_c_f_overlap(map_data, C_F[0]))
// 		return (1);
// 	if (check_RGB(RGB))
// 		return (1);
// 	return (0);
// }

// void input_RGB(t_data *map_data, char *str, char **RGB)
// {
// 	int temp_RGB;

// 	temp_RGB = ft_atoi(RGB[0]) * 65536 + ft_atoi(RGB[1]) * 256 + ft_atoi(RGB[2]);
// 	if (str[0] == 'C')
// 		map_data->ceiling_floor.ceiling_RGB = temp_RGB;
// 	else if (str[0] == 'F')
// 		map_data->ceiling_floor.floor_RGB = temp_RGB;
// }

// int check_RGB(char **RGB)
// {
// 	if (!count_split(RGB, 3))
// 		return (1);
// 	if (check_num_str(RGB[0]) || check_num_str(RGB[1]) || check_num_str(RGB[2]))
// 		return (1);
// 	if (check_RGB_range(RGB))
// 		return (1);
// 	return (0);
// }

// int check_RGB_range(char **RGB)
// {
// 	int RGB_red;
// 	int RGB_green;
// 	int RGB_blue;

// 	RGB_red = ft_atoi(RGB[0]);
// 	RGB_green = ft_atoi(RGB[1]);
// 	RGB_blue = ft_atoi(RGB[2]);
// 	if (RGB_red < 0 || RGB_red > 255)
// 		return (1);
// 	if (RGB_green < 0 || RGB_green > 255)
// 		return (1);
// 	if (RGB_blue < 0 || RGB_blue > 255)
// 		return (1);
// 	return (0);
// }

// int check_c_f_overlap(t_data *map_data, char *ceiling_floor)
// {
// 	if (ceiling_floor[0] == 'C' && map_data->ceiling_floor.ceiling_RGB != -1)
// 		return (1);
// 	if (ceiling_floor[0] == 'F' && map_data->ceiling_floor.floor_RGB != -1)
// 		return (1);
// 	return (0);
// }

// int count_split(char **split, int check_num)
// {
// 	int i;

// 	i = 0;
// 	while (split[i])
// 		i++;
// 	if (i == check_num)
// 		return (1);
// 	return (0);
// }

// void free_factor(char **factor)
// {
// 	int i;

// 	i = -1;
// 	while (factor[++i])
// 		free(factor[i]);
// 	free(factor);
// }

// int check_num_str(char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i] && ft_isdigit(str[i]))
// 		i++;
// 	if (ft_strlen(str) != i)
// 		return (1);
// 	return (0);
// }
///////////// get_next_line_utilty ///////////////////

// int ft_strncmp(const char *s1, const char *s2, int n)
// {
// 	int i;
// 	unsigned char *str1;
// 	unsigned char *str2;

// 	str1 = (unsigned char *)s1;
// 	str2 = (unsigned char *)s2;
// 	i = 0;
// 	if (n == 0)
// 		return (0);
// 	while (i < (n - 1) && str1[i] != 0 && str2[i] != 0)
// 	{
// 		if (str1[i] > str2[i])
// 			return (1);
// 		else if (str1[i] < str2[i])
// 			return (-1);
// 		i++;
// 	}
// 	if (str1[i] == str2[i])
// 		return (0);
// 	else if (str1[i] > str2[i])
// 		return (1);
// 	return (-1);
// }

///////////////////////// split ////////////////////////////

// static int ft_delimiter(char const *s, char c)
// {
// 	int count;
// 	int i;

// 	i = 0;
// 	count = 0;
// 	if (s[i] == 0)
// 		return (0);
// 	while (s[i] != 0)
// 	{
// 		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }

// static void *free_word(char **word)
// {
// 	int i;
// 	i = 0;
// 	while (word[i])
// 	{
// 		free(word[i]);
// 		i++;
// 	}
// 	free(word);
// 	return (0);
// }

// char **ft_split(char const *s, char c)
// {
// 	char **src;
// 	int end;
// 	int j;
// 	int start;

// 	j = 0;
// 	end = 0;
// 	if (!s)
// 		return (0);
// 	if (!(src = (char **)malloc(sizeof(char *) * (ft_delimiter(s, c) + 1))))
// 		return (0);
// 	while (s[end] == c)
// 		++end;
// 	while (s[end] && j < ft_delimiter(s, c))
// 	{
// 		start = end;
// 		while (s[end] != c && s[end])
// 			end++;
// 		if (!(src[j++] = ft_substr(s, start, end - start)))
// 			return (free_word(src));
// 		while (s[end] == c)
// 			end++;
// 	}
// 	src[j] = 0;
// 	return (src);
// }
///////////////////////// split ////////////////////////////

// int ft_isdigit(int c)
// {
// 	if (c >= '0' && c <= '9')
// 		return (1);
// 	return (0);
// }

// char *ft_strdup(const char *s1)
// {
// 	int i;
// 	int len;
// 	char *dup;

// 	len = 0;
// 	while (s1[len])
// 		len++;
// 	dup = malloc(len + 1);
// 	if (dup)
// 	{
// 		i = 0;
// 		while (s1[i])
// 		{
// 			dup[i] = s1[i];
// 			i++;
// 		}
// 		dup[i] = '\0';
// 	}
// 	return (dup);
// }

// char *ft_substr(char const *s, unsigned int start, int len)
// {
// 	int s_len;
// 	char *str;

// 	if (!s)
// 		return (0);
// 	s_len = ft_strlen(s);
// 	if (s_len < start)
// 		return (ft_strdup(""));
// 	if (!(str = malloc(sizeof(char) * (len + 1))))
// 		return (0);
// 	ft_strlcpy(str, s + start, len + 1);
// 	return (str);
// }

////////////////// get_next_line /////////////////////////
// int n_len(char *s)
// {
// 	int i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == '\n')
// 			break;
// 		i++;
// 	}
// 	return (i);
// }

// int devider(char **paragraph, char **line)
// {
// 	char *temp;

// 	if (n_len(*paragraph) < ft_strlen(*paragraph))
// 	{
// 		*line = ft_substr(*paragraph, 0, n_len(*paragraph));
// 		temp = ft_substr(*paragraph, n_len(*paragraph) + 1, ft_strlen(*paragraph));
// 		free(*paragraph);
// 		*paragraph = ft_strdup(temp);
// 		free(temp);
// 		return (1);
// 	}
// 	else
// 	{
// 		*line = ft_strdup(*paragraph);
// 		free(*paragraph);
// 		*paragraph = 0;
// 		return (0);
// 	}
// }

// int get_next_line(int fd, char **line)
// {
// 	static char *paragraph[OPEN_MAX];
// 	char buf[BUFFER_SIZE + 1];
// 	int rd_byte;
// 	char *temp;

// 	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
// 		return (-1);
// 	while ((rd_byte = read(fd, buf, BUFFER_SIZE)) > 0)
// 	{
// 		buf[rd_byte] = '\0';
// 		if (!paragraph[fd])
// 			paragraph[fd] = ft_strdup(buf);
// 		else
// 		{
// 			temp = ft_strjoin(paragraph[fd], buf);
// 			free(paragraph[fd]);
// 			paragraph[fd] = temp;
// 		}
// 		if (ft_strchr(paragraph[fd], '\n'))
// 			break;
// 	}
// 	if (rd_byte < 0)
// 		return (-1);
// 	else if (rd_byte == 0 && paragraph[fd] == 0)
// 	{
// 		*line = ft_strdup("");
// 		return (0);
// 	}
// 	return (devider(&paragraph[fd], line));
// }

// int ft_strlen(const char *s)
// {
// 	int i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// int ft_strchr(const char *s, int c)
// {
// 	char *ptr;

// 	ptr = (char *)s;
// 	while (*ptr)
// 	{
// 		if (*ptr == (char)c)
// 			return (1);
// 		++ptr;
// 	}
// 	if (*ptr == '\0' && c == '\0')
// 		return (1);
// 	return (0);
// }

// char *ft_strjoin(char const *s1, char const *s2)
// {
// 	int s1_len;
// 	int s2_len;
// 	char *str;
// 	int i;
// 	int j;

// 	if (!s1 || !s2)
// 		return (0);
// 	s1_len = ft_strlen(s1);
// 	s2_len = ft_strlen(s2);
// 	i = -1;
// 	if (!(str = malloc(sizeof(char) * (s1_len + s2_len + 1))))
// 		return (0);
// 	while (s1[++i])
// 		str[i] = s1[i];
// 	j = 0;
// 	while (s2[j])
// 		str[i++] = s2[j++];
// 	str[i] = 0;
// 	return (str);
// }

// int ft_atoi(const char *str)
// {
// 	int sign;
// 	long result;
// 	int i;

// 	i = 0;
// 	sign = 1;
// 	result = 0;
// 	while (*str == ' ' || (*str >= 9 && *str <= 13))
// 		str++;
// 	if (*str == '-' || *str == '+')
// 	{
// 		if (*str == '-')
// 			sign = -1;
// 		str++;
// 	}
// 	while (*str >= '0' && *str <= '9')
// 	{
// 		result = result * 10 + *str - '0';
// 		str++;
// 		i++;
// 	}
// 	if (i > 20)
// 		return ((sign == 1) ? -1 : 0);
// 	return (sign * result);
// }

// int ft_strlcpy(char *dst, const char *src, int dstsize)
// {
// 	int i;
// 	int len;

// 	if (!dst || !src)
// 		return (0);
// 	i = ft_strlen(src);
// 	if (!dst)
// 		return (ft_strlen(src));
// 	if (dstsize)
// 	{
// 		len = (i >= dstsize) ? dstsize - 1 : i;
// 		ft_memcpy(dst, src, len);
// 		dst[len] = '\0';
// 	}
// 	return (i);
// }

// void *ft_memcpy(void *dst, const void *src, int num)
// {
// 	unsigned char *dest;
// 	unsigned char *source;
// 	int i;

// 	if (!dst && !src)
// 		return (0);
// 	dest = (unsigned char *)dst;
// 	source = (unsigned char *)src;
// 	i = 0;
// 	while (i < num)
// 	{
// 		dest[i] = source[i];
// 		i++;
// 	}
// 	return (dst);
// }

int print_error(char *err)
{
	write(1, "Error\n", 6);
	write(1, err, ft_strlen(err));
	write(1, "\n", 1);
	return (1);
}

void game_start(t_data *map_data)
{
	init_player_sprite(map_data);
	init_game(map_data);
	mlx_hook(map_data->win_ptr, KEY_PRESS_EVENT, 1L << 0, bind_keys, map_data);
	mlx_hook(map_data->win_ptr, DESTROY_EVENT, 1L << 17, exit_program, map_data);
	mlx_loop_hook(map_data->mlx_ptr, loop_game, map_data);
}

// void init_game(t_data *map_data)
// {
// 	if (!(map_data->ray.buffer = (double *)malloc(sizeof(double) * map_data->input_width)))
// 		return;
// 	map_data->mlx_ptr = mlx_init();
// 	map_data->win_ptr = mlx_new_window(map_data->mlx_ptr,
// 									   map_data->input_width, map_data->input_height, "jgim");
// 	set_screen(map_data);
// 	get_image(map_data);
// }

// void set_screen(t_data *map_data)
// {
// 	map_data->ray.width = map_data->input_width;
// 	map_data->ray.width = map_data->input_height;
// 	if (map_data->input_width < 640)
// 		map_data->ray.width = 640;
// 	else if (map_data->input_width > 2560)
// 		map_data->ray.width = 2560;
// 	if (map_data->input_height < 480)
// 		map_data->ray.height = 480;
// 	else if (map_data->input_height > 1440)
// 		map_data->ray.height = 1440;
// }

int loop_game(t_data *map_data)
{
	if (map_data->update)
	{
		reset_player(map_data);
		raycast_screen(map_data);
	}
	map_data->update = 0;
}

void raycast_screen(t_data *map_data)
{
	t_texture screen;
	t_texture wall_img;
	t_line line;

	init_screen(map_data, &screen);
	map_data->ray.x = -1;
	while (map_data->ray.x < map_data->input_width)
	{
		set_ray(&map_data->ray, &map_data->player);
		set_raycasting(&map_data->ray, &map_data->player);
		hit_point(&map_data->player, &map_data->ray);
		measure_distance(&map_data->ray, &map_data->player);
		draw_line(map_data, &line);
		get_texture(map_data, &map_data->ray, &wall_img);
		draw_image(&map_data->player, &map_data->ray, &wall_img, &line);
		get_pixel_image(map_data, &line, &screen, &wall_img);
	}
	get_item(map_data, &screen);
	mlx_put_image_to_window(map_data->mlx_ptr, map_data->win_ptr, screen.img, 0, 0);
	mlx_destroy_image(map_data->mlx_ptr, screen.img);
}

void get_item(t_data *map_data, t_texture *screen)
{
	t_sprite *sprite;
	t_player *player;
	t_texture img;
	int i;

	i = -1;
	calculate_distance(map_data, sprite, player);
	sort_sprite(map_data, sprite);
	while (++i < map_data->map_factor.sprite_count)
	{
		calculate_rend_sprite(map_data, sprite, player);
		fill_item_color(map_data, sprite, &img, screen);
	}
}

void fill_item_color(t_data *data, t_sprite *s, t_texture *img, t_texture *screen)
{
	int x;
	int y;
	int tmp;

	x = s->draw_start[X] - 1;
	while (++x < s->draw_end[X])
	{
		img->tex_x = (int)(256 * (x - (-s->width / 2 + s->screen_x)) * img->width / s->width) / 256;
		if (s->tf[Y] > 0 && x > 0 && x < data->ray.width &&
			s->tf[Y] < data->ray.buffer[X])
		{
			y = s->draw_start[Y] - 1;
			while (++y < s->draw_end[Y])
			{
				tmp = y * 256 - data->ray.height * 128 + s->height * 128;
				img->tex_y = ((tmp * img->height) / s->height) / 256;
				img->color = img->data[img->width * img->tex_y + img->tex_x];
				if ((img->color & 0x00FFFFFF) != 0)
					screen->data[y * data->ray.width + x] = img->color;
			}
		}
	}
}

void calculate_distance(t_data *map_data, t_sprite *sprite, t_player *player)
{
	int i;

	sprite->texture = map_data->texture[4];
	player = &map_data->player;
	i = -1;
	while (++i < map_data->map_factor.sprite_count)
	{
		sprite[i].distance = (player->pos[X] - sprite[i].pos[X]) * (player->pos[X] - sprite[i].pos[X]) + ((player->pos[Y] - sprite[i].pos[Y]) * (player->pos[Y] - sprite[i].pos[Y]));
	}
}

void sort_sprite(t_data *map_data, t_sprite *sprite)
{
	int i;
	int j;
	t_sprite temp;

	i = -1;
	while (++i < map_data->map_factor.sprite_count)
	{
		j = -1;
		while (++j < map_data->map_factor.sprite_count - 1)
		{
			if (sprite[j].distance < sprite[j + 1].distance)
			{
				ft_memmove(&temp, &sprite[j + 1], sizeof(t_sprite));
				ft_memmove(&sprite[j + 1], &sprite[j], sizeof(t_sprite));
				ft_memmove(&sprite[j], &temp, sizeof(t_sprite));
			}
		}
	}
}

void calculate_rend_sprite(t_data *data, t_sprite *s, t_player *p)
{
	s->center[X] = s->pos[X] - p->pos[X] + 0.5;
	s->center[Y] = s->pos[Y] - p->pos[Y] + 0.5;
	s->inv_det = 1.0 / (p->plane[X] * p->dir[Y] - p->dir[X] * p->plane[Y]);
	s->tf[X] = s->inv_det * (p->dir[Y] * s->center[X] - p->dir[X] * s->center[Y]);
	s->tf[Y] = s->inv_det * (-p->plane[Y] * s->center[X] + p->plane[X] * s->center[Y]);
	s->screen_x = (int)((data->input_width / 2) * (1 + s->tf[X] / s->tf[Y]));
	s->height = abs((int)(data->input_height / s->tf[Y]));
	s->draw_start[Y] = -s->height / 2 + data->input_height / 2;
	if (s->draw_start[Y] < 0)
		s->draw_start[Y] = 0;
	s->draw_end[Y] = s->height / 2 + data->input_height / 2;
	if (s->draw_end[Y] >= data->input_height)
		s->draw_end[Y] = data->input_height - 1;
	s->width = abs((int)(data->input_height / s->tf[Y]));
	s->draw_start[X] = -s->width / 2 + s->screen_x;
	if (s->draw_start[X] < 0)
		s->draw_start[X] = 0;
	s->draw_end[X] = s->width / 2 + s->screen_x;
	if (s->draw_end[X] >= data->input_width)
		s->draw_end[X] = data->input_width - 1;
}

void get_texture(t_data *map_data, t_ray *ray, t_texture *wall_img)
{
	if (ray->map[X] - map_data->player.pos[X] <= 0 && ray->side == 0)
		wall_img = &map_data->texture[North];
	else if (ray->map[X] - map_data->player.pos[X] > 0 && ray->side == 0)
		wall_img = &map_data->texture[South];
	else if (ray->map[Y] - map_data->player.pos[Y] > 0 && ray->side == 1)
		wall_img = &map_data->texture[East];
	else if (ray->map[Y] - map_data->player.pos[Y] <= 0 && ray->side == 1)
		wall_img = &map_data->texture[West];
}

void draw_image(t_player *player, t_ray *ray, t_texture *wall_img, t_line *line)
{
	if (ray->side == 1)
		ray->wall_X = player->pos[Y] + ray->perp_wall_dist * ray->ray_dir[X];
	else
		ray->wall_X = player->pos[X] + ray->perp_wall_dist * ray->ray_dir[Y];
	ray->wall_X -= floor(ray->wall_X);
	ray->tex[X] = (int)(ray->wall_X * (double)wall_img->width);
	if (ray->ray_dir[X] > 0 && ray->side == 0)
		ray->tex[X] = wall_img->width - ray->tex[X] - 1;
	if (ray->ray_dir[Y] < 0 && ray->side == 1)
		ray->tex[X] = wall_img->width - ray->tex[X] - 1;
	ray->tex_step = 1.0 * (double)wall_img->height / (double)line->height;
	ray->tex_pos = (double)(line->start - ray->height / 2 + line->height / 2) * ray->tex_step;
}

void get_pixel_image(t_data *map_data, t_line *line, t_texture *screen, t_texture *wall_img)
{
	int y;
	t_ray ray;

	y = -1;
	ray = map_data->ray;
	while (++y < ray.height)
	{
		if (y < line->start)
			screen->data[y * ray.width + ray.x] = map_data->ceiling_floor.ceiling_RGB;
		else if (y >= line->start && y <= line->end)
		{
			ray.tex[Y] = (int)ray.tex_pos & (wall_img->height - 1);
			ray.tex_pos += ray.tex_step;
			screen->data[y * ray.height + ray.x] = wall_img->data[wall_img->width * ray.tex[Y] + ray.tex[X]];
		}
		else if (y < ray.height)
			screen->data[y * ray.width + ray.x] = map_data->ceiling_floor.floor_RGB;
	}
}

void draw_line(t_data *map_data, t_line *line)
{
	line->height = (int)(map_data->input_height / map_data->ray.perp_wall_dist);
	line->start = (-1 * line->height / 2) + (map_data->input_height / 2);
	if (line->start < 0)
		line->start = 0;
	line->end = (line->height / 2) + (map_data->input_height / 2);
	if (line->end >= map_data->input_height)
		line->end = map_data->input_height - 1;
}

void set_ray(t_ray *ray, t_player *player)
{
	ray->camera_x = (2 * ray->x / (double)ray->width) - 1;
	ray->ray_dir[X] = player->dir[X] + player->plane[X] * ray->camera_x;
	ray->ray_dir[Y] = player->dir[Y] + player->plane[Y] * ray->camera_x;
	ray->map[X] = (int)player->pos[X];
	ray->map[Y] = (int)player->pos[Y];
	ray->delta_dist[X] = 0;
	ray->delta_dist[Y] = 0;
	ray->step[X] = 1;
	ray->step[Y] = 1;
}

void measure_distance(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map[X] - player->pos[X] + (1 - ray->step[X]) / 2) / ray->ray_dir[X];
	else
		ray->perp_wall_dist = (ray->map[Y] - player->pos[Y] + (1 - ray->step[Y]) / 2) / ray->ray_dir[Y];
	ray->buffer[ray->x] = ray->perp_wall_dist;
}

void hit_point(t_data *map_data, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist[X] < ray->side_dist[Y])
		{
			ray->side_dist[X] += ray->delta_dist[X];
			ray->map[X] += ray->step[X];
			ray->side = 0;
		}
		else
		{
			ray->side_dist[Y] += ray->delta_dist[Y];
			ray->map[Y] += ray->step[Y];
			ray->side = 1;
		}
		if (map_data->map_factor.map_line[ray->map[X]][ray->map[Y]] == '1')
			ray->hit = 1;
	}
}

void set_raycasting(t_ray *ray, t_player *player)
{
	if (ray->ray_dir[Y] == 0)
		ray->delta_dist[Y] = 1;
	else if (ray->ray_dir[X] == 0)
		ray->delta_dist[X] = 1;
	else
	{
		ray->delta_dist[X] = fabs(1 / ray->ray_dir[X]);
		ray->delta_dist[Y] = fabs(1 / ray->ray_dir[Y]);
	}
	if (ray->ray_dir[X] < 0)
	{
		ray->step[X] = -1;
		ray->side_dist[X] = (player->pos[X] - ray->map[X]) * ray->delta_dist[X];
	}
	else if (ray->ray_dir[X] >= 0)
		ray->side_dist[X] = (ray->map[X] + 1.0 - player->pos[X]) * ray->delta_dist[X];
	if (ray->ray_dir[Y] < 0)
	{
		ray->step[Y] = -1;
		ray->side_dist[Y] = (player->pos[Y] - ray->map[Y]) * ray->delta_dist[Y];
	}
	else if (ray->ray_dir[Y] >= 0)
		ray->side_dist[Y] = (ray->map[Y] + 1.0 - player->pos[Y]) * ray->delta_dist[Y];
}

// void init_screen(t_data *map_data, t_texture *screen)
// {
// 	screen->bits_per_pixel = 0;
// 	screen->size_line = 0;
// 	screen->endian = 0;
// 	screen->img = mlx_new_image(map_data->mlx_ptr, map_data->input_width, map_data->input_height);
// 	screen->data = (int *)mlx_get_data_addr(screen->img,
// 											&screen->bits_per_pixel, &screen->size_line, &screen->endian);
// }

void reset_player(t_data *map_data)
{
	if (map_data->key_value == W || map_data->key_value == S || map_data->key_value == UP || map_data->key_value == DOWN)
		move_forward_backward(map_data, &map_data->player);
	if (map_data->key_value == A || map_data->key_value == D)
		move_right_left(map_data, &map_data->player);
	if (map_data->key_value == RIGHT || map_data->key_value == LEFT)
		turn_right_left(map_data, &map_data->player);
	map_data->key_value = -1;
}

void move_foward_backward(t_data *map_data, t_player *player)
{
	int i;

	i = 1;
	if (map_data->key_value == S || map_data->key_value == DOWN)
		i = -1;
	player->pos[X] += i * player->dir[X] * player->speed;
	player->pos[Y] += i * player->dir[Y] * player->speed;
	if (map_data->map_factor.map_line[(int)player->pos[X]][(int)player->pos[Y]] != '0')
	{
		player->pos[X] -= i * player->dir[X] * player->speed;
		player->pos[Y] -= i * player->dir[Y] * player->speed;
	}
}

void move_right_left(t_data *map_data, t_player *player)
{
	int i;

	i = 1;
	if (map_data->key_value == A)
		i = -1;
	player->pos[X] += i * player->dir[Y] * player->speed;
	player->pos[Y] -= i * player->dir[X] * player->speed;
	if (map_data->map_factor.map_line[(int)player->pos[X]][(int)player->pos[Y]] != '0')
	{
		player->pos[X] -= i * player->dir[X] * player->speed;
		player->pos[Y] += i * player->dir[Y] * player->speed;
	}
}

void turn_right_left(t_data *map_data, t_player *player)
{
	double old_dir[X];
	double old_plane[X];
	double rotate;

	old_dir[X] = player->dir[X];
	old_plane[X] = player->plane[X];
	rotate = player->rotate;
	if (map_data->key_value == RIGHT)
		rotate *= -1;
	player->dir[X] = old_dir[X] * cos(rotate) - player->dir[Y] * sin(rotate);
	player->dir[Y] = old_dir[X] * sin(rotate) + player->dir[Y] * cos(rotate);
	player->plane[X] = old_plane[X] * cos(rotate) - player->plane[Y] * sin(rotate);
	player->plane[Y] = old_plane[X] * sin(rotate) + player->plane[Y] * cos(rotate);
}

int bind_keys(int key_code, t_data *map_data)
{
	if (key_code == ESC_KEY)
	{
		mlx_destroy_window(map_data->mlx_ptr, map_data->win_ptr);
		//나중에 수정필요//
		exit_program(map_data);
	}
	if (key_code == LEFT || key_code == RIGHT)
		map_data->key_value = key_code;
	if (key_code == UP || key_code == W || key_code == DOWN || key_code == S)
		map_data->key_value = key_code;
	if (key_code == A || key_code == D)
		map_data->key_value = key_code;
	return (0);
}

void get_image(t_data *map_data)
{
	get_texture_image(map_data);
	get_sprite_image(map_data, map_data->sprite, map_data->map_factor.sprite_count);
}

void get_texture_image(t_data *map_data)
{
	t_texture *texture;
	int i;

	texture = map_data->texture;
	i = 0;
	while (i <= 3)
	{
		texture[i].img = mlx_xpm_file_to_image(map_data->mlx_ptr, texture[i].path,
											   &texture[i].width, &texture[i].height);
		if (!(texture[i].img))
			print_error("texture image not found");
		texture[i].img_data = mlx_get_data_addr(texture[i].img,
												&texture[i].bits_per_pixel,
												&texture[i].size_line,
												&texture[i].endian);
		if (!(texture[i].img_data))
			print_error("texture data not found");
		i++;
	}
}

/// 나중에 printe_error를 바꿔줘야함
void get_sprite_image(t_data *map_data, t_sprite *sprite, int sprite_count)
{
	int i;

	i = 0;
	while (i < sprite_count)
	{
		sprite[i].texture.img = mlx_xpm_file_to_image(map_data->mlx_ptr,
													  map_data->texture[4].path,
													  &sprite[i].texture.width,
													  &sprite[i].texture.height);
		if (!(sprite[i].texture.img))
			print_error("texture image not found");
		sprite[i].texture.img_data = mlx_get_data_addr(
			sprite[i].texture.img,
			&sprite[i].texture.bits_per_pixel,
			&sprite[i].texture.size_line,
			&sprite[i].texture.endian);
		if (!(sprite[i].texture.img_data))
			print_error("texture data not found");
		i++;
	}
}

int init_player_sprite(t_data *map_data)
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
				init_sprite(map_data, sprite++, i, j);
		}
	}
	return (0);
}

// void init_player(t_player *player, char *player_char, int row, int col)
// {
// 	player_direction(player, player_char);
// 	player->pos[X] = row + 0.5;
// 	player->pos[Y] = col + 0.5;
// 	player->rotate = 2.5 * (PI / 180);
// 	*player_char = '0';
// }

void player_direction(t_player *player, char *player_char)
{
	player->dir[X] = 0;
	player->dir[Y] = 0;
	player->plane[X] = 0;
	player->plane[Y] = 0;
	if (*player_char == 'N')
	{
		player->dir[X] = -1;
		player->plane[Y] = 0.66;
	}
	if (*player_char == 'S')
	{
		player->dir[X] = 1;
		player->plane[Y] = -0.66;
	}
	if (*player_char == 'E')
	{
		player->dir[Y] = 1;
		player->plane[X] = 0.66;
	}
	if (*player_char == 'W')
	{
		player->dir[Y] = -1;
		player->plane[X] = -0.66;
	}
}

// int init_sprite(t_data *map_data, int num, int row, int col)
// {
// 	int sprite_count;

// 	sprite_count = map_data->map_factor.sprite_count;
// 	if (num == 0)
// 		if (!(map_data->sprite = malloc(sizeof(t_sprite) * sprite_count)))
// 			return (map_data->parsing_error.sprite_malloc = 1);
// 	map_data->sprite[num].pos[X] = col;
// 	map_data->sprite[num].pos[Y] = row;
// 	return (0);
// }

// void *ft_memmove(void *dst, const void *src, int size)
// {
// 	int i;

// 	i = 0;
// 	if (!dst && !src)
// 		return (0);
// 	if (src >= dst)
// 		while (i < size)
// 		{
// 			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
// 			i++;
// 		}
// 	else if (src < dst)
// 		while (size)
// 		{
// 			size--;
// 			((unsigned char *)dst)[size] = ((unsigned char *)src)[size];
// 		}
// 	return (dst);
// }
