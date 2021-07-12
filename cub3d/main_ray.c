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

#define X 0
#define Y 1

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

#define North 0
#define South 1
#define East 2
#define West 3
#define Sprite 4

#define ESC_KEY 53

#define RIGHT 124
#define LEFT 123
#define UP 126
#define DOWN 125

#define W 13
#define S 1
#define A 0
#define D 2

#define KEY_PRESS_EVENT 2
#define DESTROY_EVENT 17

typedef struct s_texture
{
	char *path;
	void *img;
	void *img_data;
	int bits_per_pixel;
	int size_line;
	int endian;
	int *data;
	int width;
	int height;
	int tex_x;
	int tex_y;
	int color;
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
	int map_chars;
	int map_malloc;
	int map_blank;
	int player_count;
	int ceiling_floor;
	int sprite_malloc;
	int data_type;
} t_error;

typedef struct s_map
{
	int read_map;
	int valid_map;
	int height_map;
	int player_count;
	int sprite_count;
	char **map_line;
} t_map;

typedef struct s_player
{
	int pos[2];
	int speed;
	int plane_dist;
	int dir[X];
	int dir[Y];
	int plane[2];
	float angle;
	float rotate;
} t_player;

typedef struct s_point
{
	double x;
	double y;
} t_point;

typedef struct s_sprite
{
	t_texture texture;
	int pos[2];
	double distance;
	int center[2];
	double inv_det;
	double tf[2];
	int height;
	int width;
	float distance;
	float draw_start[2];
	float draw_end[2];
	int screen_x;
	int visible;
} t_sprite;

typedef struct s_ray
{
	int x;
	double *buffer;
	int width;
	int height;
	int map[2];
	double camera_x;
	double ray_dir[2];
	double side_dist[2];
	double delta_dist[2];
	double perp_wall_dist;
	double step[2];
	int hit;
	int side;
	double wall_X;
	int tex[2];
	double tex_step;
	double tex_pos;
	double floor_wall[2];
	double current_dist;
	double current_floor[2];
	int floor_tex[2];
} t_ray;

typedef struct s_line
{
	int height;
	int start;
	int end;
} t_line;

typedef struct s_data
{
	int update;
	int key_value;
	int save;
	int input_width;
	int input_height;
	char *map_str;
	void *mlx_ptr;
	void *win_ptr;
	t_ray ray;
	t_player player;
	t_sprite *sprite;
	t_map map_factor;
	t_error parsing_error;
	t_texture texture[4];
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
int is_valid_cub(t_data *map_data, char *line);
int check_factor(t_data *map_data, char *line);
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
int ft_strchr(const char *s, int c);
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
int init_player_sprite(t_data *map_data);
void init_player(t_player *player, char *player_char, int row, int col);
int init_sprite(t_data *map_data, int num, int row, int col);
int is_valid_map(t_data *map_data, t_map *map_factor);
int check_map_boundary(t_map *map_factor, int i, int j);
int find_invalid_chars(char *map_factor, const char *factors);
int read_map(t_data *map_data, char *line);
void exit_program(t_data *map_data);
int check_blank_one(t_data *map_data, char *line);
void parse_map_error(t_data *map_data);
int check_parsed(t_data *map_data);
int bind_keys(int key_code, t_data *map_data);
void set_raycasting(t_ray *ray, t_player *player);
void raycast_screen(t_data *map_data);

int main(int argc, char **argv)
{
	t_data map_data;

	check_argument(argc, argv);
	init_factor_data(&map_data);
	parse_map(&map_data, argv[1]);
	if (argc == 3)
		map_data.save = 1;
	game_start(&map_data);
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

void set_screen(t_data *map_data)
{
	map_data->ray.width = map_data->input_width;
	map_data->ray.width = map_data->input_height;
	if (map_data->input_width < 640)
		map_data->ray.width = 640;
	else if (map_data->input_width > 2560)
		map_data->ray.width = 2560;
	if (map_data->input_height < 480)
		map_data->ray.height = 480;
	else if (map_data->input_height > 1440)
		map_data->ray.height = 1440;
}

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

void init_screen(t_data *map_data, t_texture *screen)
{
	screen->bits_per_pixel = 0;
	screen->size_line = 0;
	screen->endian = 0;
	screen->img = mlx_new_image(map_data->mlx_ptr, map_data->input_width, map_data->input_height);
	screen->data = (int *)mlx_get_data_addr(screen->img,
											&screen->bits_per_pixel, &screen->size_line, &screen->endian);
}

void reset_player(t_data *map_data)
{
	if (map_data->key_value == W || map_data->key_value == S || map_data->key_value == UP || map_data->key_value == DOWN)
		move_forward_backward(map_data, &map_data->player);
	if (map_data->key_value == A || map_data->key_value == D)
		move_right_left(map_data, &map_data->player);
	if (map_data->key_value == RIGHT || map_data->key_value == LEFT)
		turn_rigth_left(map_data);
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
	get_texture_image(map_data, &map_data->texture);
	get_sprite_image(map_data, &map_data->sprite, map_data->map_factor.sprite_count);
}

void get_texture_image(t_data *map_data, char **path)
{
	t_texture *texture;
	int i;

	texture = map_data->texture;
	i = 0;
	while (i <= 3)
	{
		texture[i].img = mlx_xpm_file_to_image(map_data->mlx_ptr, path[i],
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

void init_player(t_player *player, char *player_char, int row, int col)
{
	player_direction(player, player_char);
	player->pos[X] = row + 0.5;
	player->pos[Y] = col + 0.5;
	player->rotate = 2.5 * (PI / 180);
	*player_char = '0';
}

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

int init_sprite(t_data *map_data, int num, int row, int col)
{
	int sprite_count;

	sprite_count = map_data->map_factor.sprite_count;
	if (num == 0)
		if (!(map_data->sprite = malloc(sizeof(t_sprite) * sprite_count)))
			return (map_data->parsing_error.sprite_malloc = 1);
	map_data->sprite[num].pos[X] = col;
	map_data->sprite[num].pos[Y] = row;
	return (0);
}

void exit_program(t_data *map_data)
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
}
// sprite 할당해제,
