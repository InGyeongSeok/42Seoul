#include <mlx.h>
#include "gnl/get_next_line.h"
#include "printf/ft_printf.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	// void *mlx;
	// void *win;

	// void *img;
	// int img_width;
	// int img_height;

	// mlx = mlx_init();
	// win = mlx_new_window(mlx, 500, 500, "Hellow World!");
	// img = mlx_xpm_file_to_image(mlx, "character.xpm", &img_width, &img_height);
	// mlx_put_image_to_window(mlx, win, img, 0, 0);
	// mlx_loop(mlx);

	char *name = "map.ber";
	int fd = open(name, O_RDONLY);
	for(int i =0; i <6; ++i)
		printf("%s", get_next_line(fd));
	return (0);
}
