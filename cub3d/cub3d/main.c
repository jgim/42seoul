#include "cub3d.h"

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

