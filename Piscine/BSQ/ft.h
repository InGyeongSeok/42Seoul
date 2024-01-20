/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:12:07 by seonglim          #+#    #+#             */
/*   Updated: 2023/02/02 08:39:27 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_index{
	int	i;
	int	j;
	int	diag;
}	t_index;

int		first_row_check(char *map);
int		row_check(char *map);
int		is_collide_check(char **map_arr, char charset, t_index index);
int		is_valid_row(char *map, int count, int i, int k);
t_index	check_map_arr(char **map_arr, char charset);

char	*read_map(char *filename);
int		valid_map(char *map_str);
void	alloc_map_strs(char *map, char **map_arr, int num);
char	**make_map(char *map);
char	*make_map_str(int argc, char **argv);

void	str_cat_alloc(char **dest, char *src, int j);
t_index	first_valid_start(char **map_arr, int row_size, int col_size, char set);
int		bbq_atoi(char *str);
void	search_max_index(char **map_arr, char charset,
			t_index *now_index, t_index *max_index);

void	print_map(char **map_arr);
int		err_print(char *str);
void	change_map(char **map_arr, t_index range, char set);
int		goinfre(char *map_str, char **map_arr, int flag);

#endif