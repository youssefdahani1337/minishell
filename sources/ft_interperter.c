
#include "../include/minishell.h"

#include "../debug/debug.h"

int	ft_minishell(char *line)
{
	t_tokens	*token;
	t_parser	*parser;

	parser = NULL;
	token = NULL;
	if (check_space(line))
		return (free(line), 1);
	if (!ft_lexer(line, &token))
		return (0);
	if (ft_parser(&parser, token))
		return (0);
	print_parser_iter(parser);
	fill_struct(&g_shell.table, parser);
	//ft_execution(g_shell.table);
	print_cmd_iter(g_shell.table);
	free_cmd(g_shell.table);
	return (1);
}
