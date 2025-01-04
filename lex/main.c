/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                               ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/04 16:27:06 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/04 23:06:59 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "lexing.h"

int	main(void)
{
	char *s;
	t_ast ret;

	s = "df | grep '/dev/' | grep -v 'boot$' | awk '{used += $3; av "
		"+= $4} END {printf \"free: %dM, used: %dM\\n\", av / 1024, used"
		"/ 1024}' > \"$HOME/disk usage report.log\"";
	do
	{
		ret = tokenize(s);
		if (ret.type == EXPRESSION)
			printf("GENERIC %s\n", ret.node.generic_expr_ast.expr);
		else if (ret.type == SQUOTE)
			printf("STRING LITERAL SQUOTE %s\n", ret.node.quote_ast.content);
		else if (ret.type == DQUOTE)
			printf("STRING LITERAL DQUOTE %s\n", ret.node.quote_ast.content);
		else if (ret.type == PIPE)
			printf("> PIPE >\n");
		else if (ret.type == REDIRECTION)
		{
			printf("REDIR [");
			if (ret.node.redir_ast.redir_type == OUTWARD)
				printf(" > ]\n");
			if (ret.node.redir_ast.redir_type == INWARD)
				printf(" < ]\n");
			if (ret.node.redir_ast.redir_type == OUTWARD_APPEND)
				printf(" >> ]\n");
			if (ret.node.redir_ast.redir_type == HEREDOC)
				printf(" << ]\n");
		}
	} while (ret.type != EOF);
}
