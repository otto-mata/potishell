/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   tokenize.c                                           ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/04 16:15:31 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/04 19:05:21 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "lexing.h"

t_ast tokenize(char const *s)
{
	static int		last_char = ' ';
	static int		setup = 0;
	t_ast			ast;
	char			quote_match;
	char			redir;

	if (!setup)
	{
		last_char = ft_get_char(s);
		setup = 1;
	}
	while (isspace(last_char))
		last_char = ft_get_char(0);
	if (isalnum(last_char) || last_char == '-')
	{
		memset(ast.node.generic_expr_ast.expr, 0, 256);
		ast.node.generic_expr_ast.expr[0] = last_char;
		last_char = ft_get_char(0);
		while (isalnum(last_char)|| last_char == '-')
		{
			strcat(ast.node.generic_expr_ast.expr, (const char *)&last_char);
			last_char = ft_get_char(0);
		}
		ast.type = -2;
		return (ast);
	}
	if (last_char == '\'' || last_char == '"')
	{
		quote_match = last_char;
		ast.node.quote_ast.content[0] = 0;
		last_char = ft_get_char(0);
		while (last_char != quote_match)
		{
			strcat(ast.node.quote_ast.content, (const char *)&last_char);
			last_char = ft_get_char(0);
			if (last_char == EOF)
			{
				ast.node.eof.eof = 1;
				ast.type = EOF;
				return (ast);
			}
		}
		last_char = ft_get_char(0);
		if (quote_match == '\'')
			ast.type = -3;
		else
			ast.type = -4;
		return (ast);
	}
	if (last_char == '|')
	{
		last_char = ft_get_char(0);
		ast.node.pipe_ast.pipe = 1;
		ast.type = -5;
		return (ast);
	}
	if (last_char == '>' || last_char == '<')
	{
		ast.type = -6;
		if (last_char == '<')
			ast.node.redir_ast.redir_type = INWARD;
		else
			ast.node.redir_ast.redir_type = OUTWARD;
		redir = last_char;
		last_char = ft_get_char(0);
		if (last_char == redir)
		{
			if (last_char == '<')
			{
				ast.node.redir_ast.redir_type = HEREDOC;
				last_char = ft_get_char(0);
				return (ast);
			}
			if (last_char == '>')
			{
				ast.node.redir_ast.redir_type = OUTWARD_APPEND;
				last_char = ft_get_char(0);
				return (ast);
			}
		}
		last_char = ft_get_char(0);
		if (redir == '<' || redir == '>')
			return (ast);
	}

	if (last_char == EOF)
	{
		ast.type = EOF;
		ast.node.eof.eof = 1;
		return (ast);
	}
	ast.type = -2;
	ast.node.generic_expr_ast.expr[0] = last_char;
	last_char = ft_get_char(0);
	return (ast);
}
