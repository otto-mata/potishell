/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:15:31 by tblochet          #+#    #+#             */
/*   Updated: 2025/01/04 17:10:22 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <string.h>
#include <stdio.h> 

int	ft_get_char(char const *s);

struct	s_tokens
{
	char	identifier_str[256];
};

int tokenize(char const *s, char *token)
{
	static int		last_char = ' ';
	static int		setup = 0;
	char			ret_char;
	char			quote_match;
	char			redir;

	if (!setup)
	{
		last_char = ft_get_char(s);
		setup = 1;
	}
	while (isspace(last_char))
		last_char = ft_get_char(0);
	if (isalpha(last_char))
	{
		memset(token, 0, 256);
		token[0] = last_char;
		last_char = ft_get_char(0);
		while (isalnum(last_char))
		{
			strcat(token, (const char *)&last_char);
			last_char = ft_get_char(0);
		}
		return (-2);
	}
	if (last_char == '\'' || last_char == '"')
	{
		quote_match = last_char;
		if (quote_match == '\'')
			strcpy(token, "SQUOTE_LITERAL_");
		else
			strcpy(token, "DQUOTE_LITERAL_");
		last_char = ft_get_char(0);
		while (last_char != quote_match)
		{
			strcat(token, (const char *)&last_char);
			last_char = ft_get_char(0);
			if (last_char == EOF)
			{
				strcpy(token, "UNCLOSED_STR");
				return (EOF);
			}
		}
		last_char = ft_get_char(0);
		return (-3);
	}
	if (last_char == '|')
	{
		last_char = ft_get_char(0);
		strcpy(token, "PIPE");
		return (-4);
	}
	if (last_char == '-')
	{
		memset(token, 0, 256);
		token[0] = last_char;
		last_char = ft_get_char(0);
		while (!isspace(last_char))
		{
			strcat(token, (const char *)&last_char);
			last_char = ft_get_char(0);
		}
		return (-5);
	}
	if (last_char == '>' || last_char == '<')
	{
		strcpy(token, "REDIRECTION_");
		if (last_char == '<')
			strcat(token, "INWARD");
		else
			strcat(token, "OUTWARD");
		redir = last_char;
		last_char = ft_get_char(0);
		if (last_char == redir)
		{
			if (last_char == '<')
			{
				strcpy(token, "HEREDOC");
				last_char = ft_get_char(0);
				return (-8);
			}
			if (last_char == '>')
			{
				strcat(token, "_APPEND");
				last_char = ft_get_char(0);
				return (-9);
			}
		}
		last_char = ft_get_char(0);
		if (redir == '<')
			return (-6);
		if (redir == '>')
			return (-7);
	}

	if (last_char == EOF)
		return (EOF);
	ret_char = last_char;
	last_char = ft_get_char(0);
	return (ret_char);
}
