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
	if (NSEW_S[0] == 'N' && map_data->texture[North].path)
		return (1);
	else if (NSEW_S[0] == 'S' && NSEW_S[1] == 'O' && map_data->texture[South].path)
		return (1);
	else if (NSEW_S[0] == 'E' && map_data->texture[East].path)
		return (1);
	else if (NSEW_S[0] == 'W' && map_data->texture[West].path)
		return (1);
	else if (NSEW_S[0] == 'S' && !NSEW_S[1] && map_data->texture[Sprite].path)
		return (1);
	return (0);
}

void input_texture(t_data *map_data, char *str, char *texture)
{
	if (str[0] == 'N' && str[1] == 'O')
		map_data->texture[North].path = ft_strdup(texture);
	else if (str[0] == 'S' && str[1] == 'O')
		map_data->texture[South].path = ft_strdup(texture);
	else if (str[0] == 'E')
		map_data->texture[East].path = ft_strdup(texture);
	else if (str[0] == 'W')
		map_data->texture[West].path = ft_strdup(texture);
	else if (str[0] == 'S' && !str[1])
		map_data->texture[Sprite].path = ft_strdup(texture);
}
