#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include "mlx/mlx.h"
#include <math.h>

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
	double dir[2];
	double plane[2];
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
	double draw_start[2];
	double draw_end[2];
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
	t_texture texture[5];
	t_ceilingfloor ceiling_floor;
} t_data;

int ft_strlen(const char *s);
int check_save_argument(char *save);
int ft_strncmp(const char *s1, const char *s2, int n);
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
int ft_strncmp(const char *s1, const char *s2, int n);
int ft_strlen(const char *s);
static int ft_delimiter(char const *s, char c);
static void *free_word(char **word);
char **ft_split(char const *s, char c);
int ft_isdigit(int c);
char *ft_substr(char const *s, unsigned int start, int len);
int ft_strchr(const char *s, int c);
char *ft_strdup(const char *s1);
char *ft_strjoin(char const *s1, char const *s2);
int n_len(char *s);
int devider(char **paragraph, char **line);
int get_next_line(int fd, char **line);
int ft_atoi(const char *str);
void *ft_memcpy(void *dst, const void *src, int num);
int ft_strlcpy(char *dst, const char *src, int dstsize);
void parse_error(t_data *map_data);
int print_error(char *err);
int init_player_sprite(t_data *map_data);
void init_player(t_player *player, char *player_char, int row, int col);
int init_sprite(t_data *map_data, int num, int row, int col);
int is_valid_map(t_data *map_data, t_map *map_factor);
int check_map_boundary(t_map *map_factor, int i, int j);
int find_invalid_chars(char *map_factor, const char *factors);
int read_map(t_data *map_data, char *line);
int exit_program(t_data *map_data);
int check_blank_one(t_data *map_data, char *line);
void parse_map_error(t_data *map_data);
int check_parsed(t_data *map_data);
void game_start(t_data *map_data);
void init_game(t_data *map_data);
int bind_keys(int key_code, t_data *map_data);
int loop_game(t_data *map_data);
void set_screen(t_data *map_data);
void get_image(t_data *map_data);
void set_ray(t_ray *ray, t_player *player);
void set_raycasting(t_ray *ray, t_player *player);
void hit_point(t_data *map_data, t_ray *ray);
void measure_distance(t_ray *ray, t_player *player);
void draw_line(t_data *map_data, t_line *line);
void get_texture(t_data *map_data, t_ray *ray, t_texture *wall_img);
void draw_image(t_player *player, t_ray *ray, t_texture *wall_img, t_line *line);
void get_pixel_image(t_data *map_data, t_line *line, t_texture *screen, t_texture *wall_img);
void get_item(t_data *map_data, t_texture *screen);
void calculate_distance(t_data *map_data, t_sprite *sprite, t_player *player);
void reset_player(t_data *map_data);
void raycast_screen(t_data *map_data);
void move_right_left(t_data *map_data, t_player *player);
void move_forward_backward(t_data *map_data, t_player *player);
void turn_right_left(t_data *map_data, t_player *player);
int init_sprite(t_data *map_data, int num, int row, int col);
void get_sprite_image(t_data *map_data, t_sprite *sprite, int sprite_count);
void player_direction(t_player *player, char *player_char);
void get_texture_image(t_data *map_data);
void turn_right_left(t_data *map_data, t_player *player);
void init_screen(t_data *map_data, t_texture *screen);
void calculate_rend_sprite(t_data *data, t_sprite *s, t_player *p);
void *ft_memmove(void *dst, const void *src, int size);
void sort_sprite(t_data *map_data, t_sprite *sprite);
void fill_item_color(t_data *data, t_sprite *s, t_texture *img, t_texture *screen);
