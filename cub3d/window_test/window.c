#include "../mlx/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1200, 1200, "lovely sini");
	mlx_loop(mlx);
}

