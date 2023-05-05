#include "get_next_line.h"

#include <stdio.h>

# include <fcntl.h>

int main()
{
	int fd = open("only_nl.txt", O_RDONLY);
	char *line;

	line = get_next_line(fd);
	printf("answer: %send\n\n\n\n\n", line);
	line = get_next_line(fd);
	printf("answer: %send\n\n", line);
	// line = get_next_line(fd);
	// printf("%s\n\n", line);
	// line = get_next_line(fd);
	// printf("%s\n\n", line);
	// line = get_next_line(fd);
	// printf("%s\n\n", line);



}
