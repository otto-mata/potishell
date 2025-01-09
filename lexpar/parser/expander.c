/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   expander.c                                           ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/08 07:10:23 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 02:10:34 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	var_name_sz(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
		if (!ft_isalnum(s[i]) && s[i] != '_')
			break ;
	return (i);
}

char	*retrieve_last_exit_code(void)
{
	return (0);
}

void	expand_token(t_token *token, int start)
{
	char	*var_name;
	char	*env_value;
	char	*expanded;
	int		end;

	if (token->text + start + 1 == '?')
		env_value = retrieve_last_exit_code();
	else
	{
		end = var_name_sz(token->text + start + 1);
		if (end < 0)
			return ;
		var_name = ft_substr(token->text, start + 1, end);
		env_value = getenv(var_name);
	}
	expanded = replace(token->text, var_name, env_value);
	free(token->text);
	free(var_name);
	token->text = expanded;
}

void	expand_tokens(t_list *tokens)
{
	t_list *iter;
	t_token *token;
	int dollar_sign;

	if (!tokens)
		return ;
	iter = tokens;
	while (iter)
	{
		token = (t_token *)iter->content;
		if (!token)
			return ;
		if (token->type == WORD)
		{
			dollar_sign = 0;
			while (dollar_sign >= 0)
			{
				dollar_sign = index_of(token->text, '$');
				if (dollar_sign >= 0)
					expand_token(token, dollar_sign);
			}
		}
		iter = iter->next;
	}
}