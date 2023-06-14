
#include "../include/minishell.h"

#include "../debug/debug.h"

int	ft_minishell(char *line)
{
	t_tokens	*token;
	t_parser	*parser;

	parser = NULL;
	token = NULL;
	if (!ft_lexer(line, &token))
		return (0);
	print_token_iter(token);
	if (ft_parser(&parser, token))
		return (0);
	//print_parser_iter(parser);
	//ft_clearparse(parser);
	fill_struct(&g_shell.table, parser);
	print_cmd_iter(g_shell.table);
	ft_execution(g_shell.table);
	// freecmd(g_shell.table);
	//while (g_shell.table)
	//{
	//	print_cmd(g_shell.table);
	//	g_shell.table = g_shell.table->next;
	//}
	return (1);
}
