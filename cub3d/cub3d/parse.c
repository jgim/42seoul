#include "cub3d.h"

void parse_map(t_data *map_data, char *cub)
{
	int i;
	int fd;
	char *line;
	int gnl_check;

	if ((fd = open(cub, O_RDONLY)) < 0)
		error_type(Undetermined);
	while ((gnl_check = get_next_line(fd, &line)) >= 0)
	{
		is_valid_cub(map_data, line);
		free(line);
		if (!gnl_check || map_data->parsing_error.data_type)
			break;
	}
	close(fd);
	parse_error(map_data);
	is_valid_map(map_data, &map_data->map_factor);
	parse_map_error(map_data);
	the_parsing_check(map_data);
}

int is_valid_cub(t_data *map_data, char *line)
{
	if (check_factor(map_data, line))
		return (1);
	if (*line == '1' || *line == ' ')
	{
		if (!check_parsed(map_data))
			return (map_data->parsing_error.data_type = 1);
		if (!map_data->map_factor.read_map)
			map_data->map_factor.read_map = 1;
	}
	else if (*line != '\0' && map_data->map_factor.read_map == 0)
		return (map_data->parsing_error.data_type = 1);
	read_map(map_data, line);
	return (0);
}

int check_parsed(t_data *map_data)
{
	if (!map_data->input_width || !map_data->input_height || map_data->parsing_error.resolution)
		return (0);
	if (!map_data->texture[North].path || !map_data->texture[South].path || !map_data->texture[East].path || !map_data->texture[West].path || map_data->parsing_error.texture || !map_data->texture[Sprite].path)
		return (0);
	if (map_data->ceiling_floor.ceiling_RGB == -1 || map_data->ceiling_floor.floor_RGB == -1 || map_data->parsing_error.ceiling_floor)
		return (0);
	if (map_data->parsing_error.map_malloc)
		return (0);
	return (1);
}

void parse_error(t_data *map_data)
{
	int exit_process;

	exit_process = 0;
	if (!map_data->input_width || !map_data->input_height || map_data->parsing_error.resolution)
		exit_process = print_error("invalid resolution");
	if (!map_data->texture[North].path || !map_data->texture[South].path || !map_data->texture[East].path || !map_data->texture[West].path || map_data->parsing_error.texture || !map_data->texture[Sprite].path)
		exit_process = print_error("invalid texture");
	if (map_data->ceiling_floor.ceiling_RGB == -1 || map_data->ceiling_floor.floor_RGB == -1 || map_data->parsing_error.ceiling_floor)
		exit_process = print_error("invalid_RGB");
	if (map_data->parsing_error.map_malloc)
		exit_process = print_error("invalid_memory");
	if (map_data->parsing_error.data_type)
		exit_process = print_error("invalid format");
	if (exit_process)
		exit_program(map_data);
}

void parse_map_error(t_data *map_data)
{
	int exit_process;

	exit_process = 0;

	if (map_data->parsing_error.map_chars)
		exit_process = print_error("invalid_char");
	if (map_data->parsing_error.map_malloc)
		exit_process = print_error("invalid_memory");
	if (map_data->parsing_error.map_blank)
		exit_process = print_error("invalid_blank");
	if (map_data->parsing_error.player_count)
		exit_process = print_error("invalid_player");
	if (map_data->parsing_error.sprite_malloc)
		exit_process = print_error("invalid_memory");
	if (exit_process)
		exit_program(map_data);
}
