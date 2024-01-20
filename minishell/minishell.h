/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:15:40 by seonglim          #+#    #+#             */
/*   Updated: 2023/11/04 18:14:06 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>		// open
# include <unistd.h>	// close read write dup dup2 pipe fork access execve
						// unlink getcwd chdir isatty ttyname ttyslot
# include <stdio.h>		// printf perror
# include <stdlib.h>	// malloc free exit getenv
# include <string.h>	// strerror
# include <signal.h>	// signal sigaction sigemptyset sigaddset kill
# include <dirent.h>	// opendir readdir closedir
# include <errno.h>		// errno
# include <termios.h>	// tcsetattr tcgetattr
# include <term.h>		// tgetent tgetflag tgetnum tgetstr tgoto tputs
# include <sys/wait.h>	// wait waitpid wait3 wait4
# include <sys/stat.h>	// stat lstat fstat
# include <sys/ioctl.h>	// ioctl
# include <readline/readline.h>	// readline rl_clear_history rl_on_new_line
								// rl_replace_line rl_redisplay
# include <readline/history.h>	// add_history

# define READ 0
# define WRITE 1

typedef struct s_pvec
{
	char	**p;
	int		size;
}	t_pvec;

typedef struct s_str
{
	char	*s;
	int		size;
}	t_str;

typedef struct s_fds
{
	int	in_fd;
	int	out_fd;
}	t_fds;

typedef struct s_cmd_var
{
	t_pvec	split;
	t_str	str;
	int		isquote;
	int		isdouble;
	int		i;
}	t_c;

typedef struct s_tree
{
	char			*key;
	char			*value;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

// main.c
int			exit_code(int code, int is_set);
void		sigint_handler(int signal);
int			set_sig_terminal(int option);
void		work_line(char *line, char ***my_envp);

// my_util.c
void		change_inout(t_fds fds, int is_set);
int			is_builtin_sg(char **split, char ***my_envp, t_fds fds);
int			is_builtin(char **split, char ***my_envp, t_fds fds);
char		*my_pathjoin(char const *s1, char const *s2);
const char	*sum_msg(const char *s1, const char *s2, int flag);

// my_util2.c
int			is_all_ws(char *str);
int			is_right_pipe(char *line);
int			wait_all(pid_t last_pid);
t_pvec		make_my_envp(char **envp);
char		*my_getenv(char **envp, const char *name);

// ft_util.c
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr_fd(const char *s, int fd);
char		*ft_strdup(const char *s1);

// ft_split.c
void		free_split(char **arr);
char		**ft_split(char const *s, char c);

// parse.c
void		split_pipe_sub1(t_c *var, char c);
void		split_pipe_sub2(t_c *var, char c);
char		**split_pipe(const char *line);
void		change_env_str(t_str *str, char **envp, t_str r_str, t_str n_str);
void		pipe_cmd(char *line, char ***my_envp);

// cmd_split.c
t_c			make_cmd_var(void);
char		**cmd_split(char *line, char **envp);

// single_cmd.c
int			is_single_cmd(char *str);
void		single_cmd(char *line, char ***my_envp);

// solve.c
int			close_fds(t_fds fds);
void		exe_failed(const char *cmd);
int			solve_cmd(char **cmd_list, char **envp);
void		exe_cmd(char **cmd_list, char **envp);

// redirect.c
void		stdin_redirect(int *fd, char **cmd_list, int *i);
void		stdout_redirect(int *fd, char **cmd_list, int *i, int open_flag);
void		heredoc_redirect(int *fd, char **cmd_list, int *i);
t_fds		change_redirect(char **cmd_list);

// here_doc_sub.c
int			here_doc_input(char *limiter, int wr_fd);
int			here_doc(char *limiter);

// vector.c
t_pvec		make_pvec(void);
t_str		make_str(void);
void		pvec_push(t_pvec *pvec, char *str);
void		str_push(t_str *str, char c);

// pipe_child.c
void		run_child_start(void);
void		run_child_sub(int fd[2], t_fds fds, int infd, int flag);
void		run_child_end(char **split, char ***my_envp, t_fds fds);

// pipe.c
void		run_child(int infd, char **cmd_lines, pid_t *pid, char ***my_envp);
void		run_pipe(int infd, char **cmd_lines, pid_t *pid, char ***my_envp);

// tree.c
t_tree		*find_node_del(t_tree *node);
t_tree		*del_node(t_tree *root, char *key);
t_tree		*free_tree(t_tree	*root, int flag);
t_tree		*insert_node(t_tree	*root, char *key, char	*value);
void		print_tree(t_tree *root);

// built-in commands
// cd.c
void		builtin_cd(char **cmds, char ***my_envp);

// exit.c
void		builtin_exit(char **cmds);

// pwd.c
void		builtin_pwd(char **cmds, char ***my_envp);

// env.c
void		builtin_env(char **cmds, char ***my_envp);

// export.c
void		add_my_envp(char **cmds, char ***my_envp);
t_tree		*make_export_envp(char ***my_envp);
void		builtin_export(char **cmds, char ***my_envp, int flag);
void		del_export(char **cmds, t_tree *root);

// export2.c
int			isvalid_export(char **cmds);
int			find_cmds_my_envp(char **cmds, char ***my_envp);
void		find_key(t_tree *root, char **cmds);
int			search(t_tree *root, char *key, char *value);
int			find_equal(char **cmd);

// unset.c
void		del_my_envp(char **cmds, char ***my_envp);
void		builtin_unset(char **cmds, char ***my_envp);
int			is_del(t_tree *root, char *key);

// echo.c
void		builtin_echo(char **cmds);

#endif
