#include <mlx.h>
#include "gnl/get_next_line.h"
#include "printf/ft_printf.h"
#include <fcntl.h>
#include <stdio.h>

char	*map_strjoin(char const *s1, char const *s2, int s2_len)
{
	size_t	len;
	char	*s3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (gnl_strndup(s2, s2_len));
	else if (!s2)
		return (gnl_strndup(s1, gnl_strlen(s1)));
	len = gnl_strlen((char *)s1) + s2_len;
	s3 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s3)
		return (NULL);
	while (*s1)
		s3[i++] = *s1++;
	while (j < s2_len)
		s3[i + j++] = *s2++;
	s3[i + j] = '\0';
	return (s3);
}


int main()
{

	char *name = "map.ber";
	int fd = open(name, O_RDONLY);
	char *map;
	char *one_line;

	while(fd>0){
		one_line = get_next_line(fd);
		printf("%s", one_line);
		map = map_strjoin(map, one_line, gnl_strlen(one_line));
		if(one_line == NULL) // 이러면 예외처리 어케함??
			fd = 0;
	}
	printf("\n===map===\n%s", map);

	int next_line_count = 0;
	int count = 0;
	while(map[count]){
		count++;
		if(map[count] == '\n')
			next_line_count++;
	}


	// printf("전체: %d", count);
	// printf("개행: %d", next_line_count);
	///////////////////

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
	win = mlx_new_window(mlx, (count- next_line_count) / (next_line_count+1) * 64, (next_line_count +1 ) * 64, "Hellow World!");
	img1 = mlx_xpm_file_to_image(mlx, "img/1.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, "img/wall.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, "img/star.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx, "img/end.xpm", &img_width, &img_height);
	img5 = mlx_xpm_file_to_image(mlx, "img/ghost.xpm", &img_width, &img_height);
	img6 = mlx_xpm_file_to_image(mlx, "img/grass2.xpm", &img_width, &img_height);
	int j = (count- next_line_count) / (next_line_count+1);
	printf("%d", j);
	// for(int i =0; i <(next_line_count +1 ); ++i)
	// {
	// 	for(int j = 0; j < (count- next_line_count) / (next_line_count+1); j++){

	// 		mlx_put_image_to_window(mlx, win, img6, j * 64, i * 64);
	// 		if(map[i*j + j + next] == '\0')
	// 			next +=1;
	// 		if(map[i*j + j+ next] == '1')
	// 			mlx_put_image_to_window(mlx, win, img2, j * 64, i * 64);
	// 	}
	// }
	j =0;
	int  next = 0;
	while(j  <= count)
	{
		if(map[j] == '\0')
			j++;
		else{
			mlx_put_image_to_window(mlx, win, img6, j %14 * 64, j / 14 * 64);
			if(map[j] == '1')
 				mlx_put_image_to_window(mlx, win, img2, j %14 * 64, j / 14 * 64);
			else if(map[j] == 'C')
				mlx_put_image_to_window(mlx, win, img3, j %14 * 64, j / 14 * 64);
			else if(map[j] == 'E')
				mlx_put_image_to_window(mlx, win, img4, j %14 * 64, j / 14 * 64);
			else if(map[j] == 'P')
				mlx_put_image_to_window(mlx, win, img1, j %14 * 64, j / 14 * 64);
			j++;
		}
	}

	// mlx_put_image_to_window(mlx, win, img2, 64, 0);
	// mlx_put_image_to_window(mlx, win, img3, 64*2, 0);
	// mlx_put_image_to_window(mlx, win, img4, 64*3, 0);
	// mlx_put_image_to_window(mlx, win, img5, 64*4, 0);
	// mlx_put_image_to_window(mlx, win, img1, 0, 0);
	mlx_loop(mlx);
	return (0);
}

// esc key press event
