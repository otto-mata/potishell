/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   expander.c                                           ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/08 07:10:23 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/08 08:37:21 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*replace(char *in, char *sub, char *by)
{
	size_t	sub_sz;
	size_t	final_sz;
	char	*ret;
	char	*substart;

	if (!in || !sub)
		return (0);
	substart = ft_strstr(in, sub);
	if (!substart)
		return (ft_strdup(in));
	sub_sz = ft_strlen(sub);
	if (!by)
		by = "";
	final_sz = ft_strlen(in) - sub_sz + ft_strlen(by);
	ret = ft_calloc(final_sz + 1, sizeof(char));
	if (!ret)
		return (0);
	ft_strncpy(ret, in, (size_t)(substart - in));
	ft_strcat(ret, by);
	ft_strcat(ret, (char *)(substart + sub_sz));
	return (ret);
}

void	expand_token(t_token *token, int start)
{
	char	*var_name;
	char	*env_value;
	char	*expanded;
	int		end;

	end = index_of(token->text + start, ' ');
	if (end < 0)
		end = ft_strlen(token->text + start);
	var_name = ft_substr(token->text, start + 1, end);
	env_value = getenv(var_name);
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
			dollar_sign = index_of(token->text, '$');
			if (dollar_sign >= 0)
				expand_token(token, dollar_sign);
		}
		iter = iter->next;
	}
}