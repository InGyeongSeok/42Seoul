#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*temp;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	temp = get_next_line(fd);
	while (temp)
	{
		printf("%s", temp);
		free(temp);
		//printf("test");

		temp = get_next_line(fd);
	}
	printf("%s", temp);
	//free(temp);
	close(fd);
	return (0);
	system("leaks a.out");
}

// int main()
// {
// 	char *s;
// 	int fd;

// 	fd = open("test.txt", O_RDONLY);
// 	s = get_next_line(fd);
// 	printf("answer:%s|", s);
// 	// s = get_next_line(fd);
// 	// printf("answer:%s|", s);
// 	// s = get_next_line(fd);
// 	// printf("answer:%s|", s);
// }
