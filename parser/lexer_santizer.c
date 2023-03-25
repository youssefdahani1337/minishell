/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_santizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 08:17:22 by yodahani          #+#    #+#             */
/*   Updated: 2023/03/21 18:42:31 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"


void	join_str(t_tokens **t, char *line, int start, int i)
{
	char	*str;

	(void)t;
	if (i > start)
	{
		str = ft_substr(line, start, i);
		ft_tokenadd_back(t, ft_newtoken(str, string, 0));
	}
}

void	ft_red_find(t_tokens **t, char *line, int *i)
{
	int	type;

	(*i) ++;
	if (line[*i] == red_in)
	{
		type = red_in;
		if (line[(*i) + 1] == red_in && ++(*i))
			type = herdoc;
	}
	else
	{
		type = red_out;
		if (line[(*i) + 1] == red_out && ++(*i))
			type = red_app;
	}
	ft_tokenadd_back(t, ft_newtoken(NULL, type, 0));
}

void	ft_quote_find(t_tokens **t, char *line, int *i)
{
	int		join;
	int		type;
	int		start;
	char	*str;

	if (*i != 0 && !ft_strchr(" |<>", line[(*i) - 1]))
		join = 1;
	if (line[(*i)++] == d_quote)
		type = d_quote;
	else
		type = s_quote;
	start = *i;
	while (line[*i] && line[*i] != type)
		(*i)++;
	if (!line[*i])
		ft_exit_lexer(t, line, "unclosed quote\n");
	(*i)++;
	if (!ft_strchr("<>| ", line[*i]))
		join += 2;
	str = ft_substr(line, start, (*i) - (start +1 ));
	if (type == d_quote)
		str = ft_find_var_quote(str);
	ft_tokenadd_back(t, ft_newtoken(str, type, join));
}

char	*ft_find_var_quote(char *str)
{
	int			i;
	int			start;
	char		*s;
	t_tokens	*t;

	s = NULL;
	i = 0;
	start = 0;
	while (str[i])
	{	
		while (str[i] && str[i] != var)
			i++;
		s = ft_strjoin_m(s, ft_substr(str, start, i - start));
		start = i;
		printf("%c\n", str[i]);
		if (str[i] == var)
		{
			t = split_var(str, &i);
			str = ft_strjoin_m(str, t->value);
			free(t);
		}
	}
	return (s);
}

t_tokens	*split_var(char *line, int *i)
{
	char	*str;
	int		type;
	int		index;
	int		join;

	join = 0;
	index = *i;
	type = string;
	(*i)++;
	if (ft_isdigit(line[*i]) && ++(*i))
		str = NULL;
	else if (var_ex == line[*i])
	{
		type = var_ex;
		str = NULL;
	}
	else if (!ft_isalpha(line[*i]) && line[*i] != '_')
		str = ft_substr(line, (*i) - 1, 2);
	else
	{
		while (line[*i] && (ft_isalnum(line[*i]) || line[*i] == '_'))
			(*i)++;
		str = ft_substr(line, index, (*i) - index);
		type = var;
	}
	if (index != 0 && !ft_strchr("<>| ", line[index -1]))
		join = 1;
	if (!ft_strchr("<>| ", line[*i]))
		join += 2;
	return (ft_newtoken(str, type, join));
}

void	ft_var_find(t_tokens **t, char *line, int *i)
{
	ft_tokenadd_back(t, split_var(line, i));
}
