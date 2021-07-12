#include "cub3d.h"

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

int check_c_f_overlap(t_data *map_data, char *ceiling_floor)
{
	if (ceiling_floor[0] == 'C' && map_data->ceiling_floor.ceiling_RGB != -1)
		return (1);
	if (ceiling_floor[0] == 'F' && map_data->ceiling_floor.floor_RGB != -1)
		return (1);
	return (0);
}

