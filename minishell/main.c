/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:16:08 by seonglim          #+#    #+#             */
/*   Updated: 2023/11/18 03:03:31 by seonglim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit_code(int code, int is_set)
{
	static int	ret_code;

	if (is_set)
		ret_code = code;
	return (ret_code);
}

void	sigint_handler(int signal)
{
	(void)signal;
	printf("\n");
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
	exit_code(1, 1);
}

int	set_sig_terminal(int option)
{
	struct termios			term;
	static struct termios	origin;

	if (option >= 0)
	{
		tcsetattr(STDIN_FILENO, TCSANOW, &origin);
		return (option);
	}
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	tcgetattr(STDIN_FILENO, &term);
	origin = term;
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	return (-1);
}

void	work_line(char *line, char ***my_envp)
{
	if (!*line)
		return ;
	if (is_single_cmd(line))
		single_cmd(line, my_envp);
	else
		pipe_cmd(line, my_envp);
}

int	main(int argc, char **argv, char **envp)
{
	char		*str;
	t_pvec		my_envp;

	(void)(argc + argv);
	printf("This is a gsh that comes with a lot of pain.\n");
	set_sig_terminal(-1);
	my_envp = make_my_envp(envp);
	builtin_export(NULL, &my_envp.p, 1);
	while (1)
	{
		str = readline("gsh$ ");
		if (!str)
		{
			printf("\033[1A\033[5Cexit\n");
			break ;
		}
		work_line(str, &my_envp.p);
		add_history(str);
		free(str);
	}
	sum_msg(NULL, NULL, 1);
	return (set_sig_terminal(0));
}
