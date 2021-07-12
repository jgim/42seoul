#include "cub3d.h"

void init_factor_data(t_data *map_data)
{
	map_data->input_width = 0;
	map_data->input_height = 0;
	map_data->map_factor.read_map = 0;
	map_data->map_factor.valid_map = 0;
	map_data->map_factor.height_map = 0;
	map_data->map_factor.player_count = 0;
	map_data->map_factor.sprite_count = 0;
	map_data->texture[North].path = 0;
	map_data->texture[South].path = 0;
	map_data->texture[East].path = 0;
	map_data->texture[West].path = 0;
	map_data->texture[Sprite].path = 0;
	map_data->ceiling_floor.ceiling_RGB = -1;
	map_data->ceiling_floor.floor_RGB = -1;
	map_data->parsing_error.resolution = 0;
	map_data->parsing_error.texture = 0;
	map_data->parsing_error.ceiling_floor = 0;
	map_data->parsing_error.map_blank = 0;
	map_data->parsing_error.map_chars = 0;
	map_data->parsing_error.map_malloc = 0;
	map_data->parsing_error.sprite_malloc = 0;
	map_data->parsing_error.player_count = 0;
	map_data->parsing_error.data_type = 0;
	map_data->player.pos[X] = 0;
	map_data->player.pos[Y] = 0;
	map_data->map_factor.read_map = 0;
}

void init_game(t_data *map_data)
{
	if (!(map_data->ray.buffer = (double *)malloc(sizeof(double) * map_data->input_width)))
		return;
	map_data->mlx_ptr = mlx_init();
	map_data->win_ptr = mlx_new_window(map_data->mlx_ptr,
									   map_data->input_width, map_data->input_height, "jgim");
	set_screen(map_data);
	get_image(map_data);
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

void init_player(t_player *player, char *player_char, int row, int col)
{
	player_direction(player, player_char);
	player->pos[X] = row + 0.5;
	player->pos[Y] = col + 0.5;
	player->rotate = 2.5 * (PI / 180);
	*player_char = '0';
}
