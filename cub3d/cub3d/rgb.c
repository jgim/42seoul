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
	if (ceiling_floor[0] == 'C' && map_data->ceiling_floor.ceiling_RGB != -1)
		return (1);
	if (ceiling_floor[0] == 'F' && map_data->ceiling_floor.floor_RGB != -1)
		return (1);
	return (0);
}
