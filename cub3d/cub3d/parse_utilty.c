#include "cub3d.h"

int check_blank_one(t_data *map_data, char *line)
{
	if (line[0] == ' ' || line[0] == '1')
		return (map_data->map_factor.valid_map = 1);
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
