
#include "../include/minishell.h"

void	ft_envclear(t_env **lst)
{
	t_env	*t;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		t = (*lst)->next;
		free((*lst)->key);
		free((*lst)->value);
		free(*lst);
		*lst = t;
	}
	*lst = NULL;
}

int	ft_fillnew(t_env *new, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	if (!str[i])
	{
		new->equal = 0;
		new->value = 0;
	}
	else if (str[i])
	{
		new->equal = 1;
		new->value = ft_strdup(str + i + 1);
		if (!new->value)
			return (free(new), 0);
	}
	new->key = ft_substr(str, 0, i);
	if (!new->key)
		return (free(new->value), free(new), 0);
	return (1);
}


t_env	*ft_envlast(t_env *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		return (lst);
	}
	return (NULL);
}

int	ft_envadd_back(t_env **lst, t_env *new)
{
	t_env	*last;

	if (lst && new)
	{
		if (!(*lst))
			*lst = new;
		else
		{
			last = ft_envlast(*lst);
			last -> next = new;
		}
	}
	if (!new)
		return (ft_envclear(lst), 0);
	return (1);
}

t_env	*ft_envnew(char *str)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	if (ft_fillnew(new, str) == 0)
		return (NULL);
	new->next = NULL;
	return (new);
}

t_env	*ft_env_fill(char **env)
{
	int		i;
	t_env	*new;
	t_env	*env_info;

	i = 0;
	env_info = NULL;
	if (env)
	{
		while (env[i])
		{
			new = ft_envnew(env[i++]);
			if (ft_envadd_back(&env_info, new) == 0)
				return (NULL);
		}
		
	}
	return (env_info);
}
void	ft_env(void)
{
	t_env	*p;

	p = g_shell.env;
	while (p)
	{
		if (p->equal == 1)
		{
			ft_putstr_fd(p->key, 1);
			ft_putchar_fd('=', 1);
			ft_putstr_fd(p->value, 1);
			ft_putchar_fd('\n', 1);
		}
		p = p->next;
	}
}
void	ft_intialize_shell(char **env)
{
	g_shell.env = ft_env_fill(env);
	g_shell.exitsts = 0;
}