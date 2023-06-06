
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
	if (!ft_parser(&parser, token))
		return (0);
	g_shell.table = NULL;
	fill_struct(&g_shell.table, parser);
	ft_execution(g_shell.table);
	//freecmd(g_shell.table);
	
	return (1);
}
