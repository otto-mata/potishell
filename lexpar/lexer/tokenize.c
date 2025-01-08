/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   tokenize.c                                           ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/08 04:35:34 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/08 09:15:16 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	non_quoted_index(char *s, char c)
{
	int	i;
	int	c_index;
	int	in_quote;

	c_index = index_of(s, c);
	if (c_index < 0 || (!ft_strchr(s, '"') && !ft_strchr(s, '\'')))
		return (c_index);
	i = -1;
	in_quote = 0;
	while (s[++i])
	{
		if (in_quote && i == c_index)
			return (-1);
		if (s[i] == '"' || s[i] == '\'')
			set_quote_state(s[i], &in_quote);
	}
	return (c_index);
}

static int	special_char_index(char *s)
{
	int	idx;

	idx = non_quoted_index(s, '|');
	if (idx >= 0)
		return (idx);
	idx = non_quoted_index(s, '>');
	if (idx >= 0)
		return (idx);
	idx = non_quoted_index(s, '<');
	if (idx >= 0)
		return (idx);
	return (idx);
}

static t_list	*subpart_lex(char *part)
{
	t_list	*out;
	size_t	bufsz;
	char	*buf;
	int		i;
	int		j;

	if (!part)
		return (0);
	bufsz = ft_strlen(part);
	buf = ft_calloc(bufsz, sizeof(char));
	if (!buf)
		return (0);
	out = 0;
	i = -1;
	j = 0;
	while (part[++i])
	{
		if (!ft_strchr("|<>", part[i]) && !ft_isspace(part[i]))
			buf[j++] = part[i];
		else
		{
			if (j > 0)
				ft_lstadd_back(&out, ft_lstnew(ft_strdup(buf)));
			j = 0;
			ft_memset(buf, 0, bufsz);
			if (i < bufsz - 1 && part[i + 1] == part[i])
				ft_lstadd_back(&out, ft_lstnew(ft_substr(&part[i++], 0, 2)));
			else
				ft_lstadd_back(&out, ft_lstnew(ft_substr(&part[i], 0, 1)));
		}
	}
	if (j > 0)
		ft_lstadd_back(&out, ft_lstnew(ft_strdup(buf)));
	free(buf);
	return (out);
}

static t_list	*get_clean_parts(char *raw)
{
	t_list	*ws_split;
	t_list	*part;
	t_list	*pre_token;

	ws_split = smarter_split(raw);
	if (!ws_split)
		return (0);
	pre_token = 0;
	part = ws_split;
	while (part)
	{
		if (special_char_index((char *)part->content) >= 0)
			ft_lstadd_back(&pre_token, subpart_lex((char *)part->content));
		else
			ft_lstadd_back(&pre_token,
				ft_lstnew(ft_strdup((char *)part->content)));
		part = part->next;
	}
	ft_lstclear(&ws_split, free);
	return (pre_token);
}
static t_token	*a2token(char *part)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		return (0);
	token->text = 0;
	if (ft_strcmp(part, "|") == 0)
		token->type = PIPE;
	else if (ft_strcmp(part, ">>") == 0)
		token->type = GREATGREAT;
	else if (ft_strcmp(part, ">") == 0)
		token->type = GREAT;
	else if (ft_strcmp(part, "<<") == 0)
		token->type = LESSLESS;
	else if (ft_strcmp(part, "<") == 0)
		token->type = LESS;
	else
	{
		token->type = WORD;
		token->text = ft_strdup(part);
		if (!token->text)
			return (free(token), (t_token *)0);
	}
	return (token);
}

t_list	*tokenize(char *raw)
{
	t_list	*clean_input;
	t_list	*iter;
	t_list	*tokens;

	clean_input = get_clean_parts(raw);
	if (!clean_input)
		return (0);
	iter = clean_input;
	tokens = 0;
	while (iter)
	{
		ft_lstadd_back(&tokens, ft_lstnew(a2token(iter->content)));
		iter = iter->next;
	}
	ft_lstclear(&clean_input, free);
	return (tokens);
}

void free_token_list(void *content)
{
	free(((t_token *)content)->text);
	free(content);
}
