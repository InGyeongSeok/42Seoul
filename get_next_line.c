/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:45:02 by inseok            #+#    #+#             */
/*   Updated: 2023/05/20 20:24:43 by inseok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *add_line(char** line, char* read_buffer)
{
	char * result;
	// free(*line);
	// line = NULL;
	result = gnl_strjoin(*line, read_buffer);
	return (result);
}

char *gnl_split(char **line, int i)
{
	char *result;
	char *save;
	//write(1, "here", 4);

	result = gnl_strndup(*line, i + 1);
	save = gnl_strndup(*line + i + 1, gnl_strlen(*line) - i);
	free(*line);
	*line = save;
	return (result);
}

char * final_line(char **line, int read_size)
{
	char * result;
	if (read_size < 0)
	{
 		free(*line);
		*line = NULL;
		return (0);
	} //에러러러러러ㅓ
	// if(*line && gnl_strchr(*line) > -1)
	// 	return(gnl_split(line, gnl_strchr(*line)));
	if(*line)
	{
		if(**line == '\0')
		{
			free(*line);
			return (NULL);
		}
		result = gnl_strndup(*line, gnl_strlen(*line));
		free(*line);
		*line = NULL;
		return (result);
	}
	else
		return (NULL);
}



char * get_next_line(int fd)
{
	char	*read_buffer;
	int		read_size;
	static char *line;
	char 	*temp;

	if(fd <0 || BUFFER_SIZE < 1)
		return (0);
	read_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!read_buffer)
		return (NULL);
	while(1)
	{


		if(gnl_strchr(line) > -1){ // 개행이 있다
			free(read_buffer);
			return(gnl_split(&line, gnl_strchr(line)));
		}

		read_size = read(fd, read_buffer, BUFFER_SIZE);
		//잘못 읽으면 멈추기
		if(read_size <=0)
			break;
		read_buffer[read_size] = '\0';
		// 계속 뒤에 붙이기
		temp = line;
		line = add_line(&temp, read_buffer);
		free(temp);
		temp = NULL;
		gnl_memset(read_buffer,0,BUFFER_SIZE);
	}
	// 나머지 부분 읽기
		//printf("%s", line);

	free(read_buffer);
	return(final_line(&line, read_size));
}
