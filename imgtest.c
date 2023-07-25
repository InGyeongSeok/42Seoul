#include <mlx.h>
#include "gnl/get_next_line.h"
#include "printf/ft_printf.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	void *mlx;
	void *win;

	void *img1; //캐릭터
	void *img2; //벽
	void *img3; //수집품
	void *img4; // 출구
	void *img5; //고스트
	void *img6; //배경
	int img_width;
	int img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 640, "Hellow World!");
	img1 = mlx_xpm_file_to_image(mlx, "img/1.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, "img/wall.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, "img/star.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx, "img/end.xpm", &img_width, &img_height);
	img5 = mlx_xpm_file_to_image(mlx, "img/ghost.xpm", &img_width, &img_height);
	img6 = mlx_xpm_file_to_image(mlx, "img/grass2.xpm", &img_width, &img_height);

	for(int i =0; i <6; ++i)
	{
		mlx_put_image_to_window(mlx, win, img6, i * 64, 0);
	}
	mlx_put_image_to_window(mlx, win, img2, 64, 0);
	mlx_put_image_to_window(mlx, win, img3, 64*2, 0);
	mlx_put_image_to_window(mlx, win, img4, 64*3, 0);
	mlx_put_image_to_window(mlx, win, img5, 64*4, 0);
	mlx_put_image_to_window(mlx, win, img1, 0, 0);

	mlx_loop(mlx);
	return (0);
}
