
#include "../include/minishell.h"

#include "../debug/debug.h"

int	ft_minishell(char *line)
{
	t_tokens	*token;
	t_tokens	*t;
	t_parser	*parser;
	t_cmdtable	*cmd;
	parser = NULL;
	token = NULL;
	if (!ft_lexer(line, &token))
		return (0);
	t = token;
	while (t)
	{
		printtoken(t);
		t = t->next;
	}
	printf("\n++++++++++++++++\n");
	if (!ft_parser(&parser, token))
		return (0);
	
	while (parser)
	{
		printparser(parser);
		parser = parser->next;
	}
	cmd = g_shell.table;
	ft_execution(cmd);
	freecmd(g_shell.table);
	fill_struct(&g_shell.table, parser);
	return (1);
}
