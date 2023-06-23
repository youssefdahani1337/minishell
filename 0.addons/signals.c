/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:11:08 by yodahani          #+#    #+#             */
/*   Updated: 2023/06/23 14:50:23 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/addons.h"

void	hand(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	exit(1);
}

void	remove_ctrl_c(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, 0, &term);
}

void	handler(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	// rl_on_new_line();
	// rl_replace_line("", 0);
	// rl_redisplay();
	g_shell.exitsts = 1;
}

void	handler_df(void)
{
	struct termios	term;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, 0, &term);
}

void	exit_with_sig(int status)
{
	g_shell.exitsts = WTERMSIG(status) + 128;
	if (g_shell.exitsts == 131)
		ft_putstr_fd("Quit: 3", 2);
	ft_putchar_fd('\n', 2);
}
