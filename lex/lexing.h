/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   lexing.h                                             ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/04 18:01:12 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/05 01:04:01 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXING_H
# define LEXING_H
# include <ctype.h>
# include <stdio.h>
# include <string.h>

typedef struct s_expr_ast		t_expr_ast;
typedef struct s_pipe_ast		t_pipe_ast;
typedef struct s_quote_lit_ast	t_quote_lit_ast;
typedef struct s_redir_ast		t_redir_ast;
typedef struct s_eof_ast		t_eof_ast;
typedef struct s_ast			t_ast;
typedef union u_quote_ast		t_quote_ast;
typedef union u_node_ast		t_node_ast;
typedef enum e_ast_node_type	t_ast_node_type;
enum							e_redir_type
{
	OUTWARD = 0,
	INWARD,
	OUTWARD_APPEND,
	HEREDOC,
};

enum							e_ast_node_type
{
	EXPRESSION = -2,
	SQUOTE = -3,
	DQUOTE = -4,
	PIPE = -5,
	REDIRECTION = -6,
};

struct							s_expr_ast
{
	char						expr[256];
};

struct							s_pipe_ast
{
	t_node_ast					*origin;
	int							pipe;
	t_node_ast					*target;
};

struct							s_quote_lit_ast
{
	char						content[256];
};

struct							s_redir_ast
{
	t_node_ast					*origin;
	enum e_redir_type			redir_type;
	t_node_ast					*target;
};

struct							s_eof_ast
{
	int							eof;
};

union							u_node_ast
{
	t_expr_ast					generic_expr_ast;
	t_pipe_ast					pipe_ast;
	t_quote_lit_ast				quote_ast;
	t_redir_ast					redir_ast;
	t_eof_ast					eof;
};

struct							s_ast
{
	t_ast_node_type				type;
	t_node_ast					node;
};

enum							e_type
{
	WORD,
	REDIRECTION,
	GREAT,
	LESS,
	PIPELINE,
};
struct							s_type_text
{
	enum e_type					type;
	char						*text;
};

struct							s_cmd_fix
{
	enum e_type					type;
	struct s_type_text			op;
	struct s_type_text			file;
	struct s_type_text			args;
};

struct							s_command
{
	struct s_type_text			name;
	struct s_cmd_fix			**suffix;
	struct s_cmd_fix			**prefix;
};

int								ft_get_char(char const *s);
t_ast							tokenize(char const *s);

#endif
