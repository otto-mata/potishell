/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   smart_split.c                                        ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/08 03:00:50 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/08 05:45:38 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "lexpar.h"

static int	count_spaces(char *s)
{
	int	i;
	int	acc;

	i = -1;
	acc = 0;
	while (s[++i])
		if (ft_isspace(s[i]))
			acc++;
	return (acc);
}

static int	*mark(char *s, int *idcs)
{
	int	in_quote;
	int	i;
	int	j;

	in_quote = 0;
	i = -1;
	j = 0;
	idcs[j++] = -1;
	while (s[++i])
	{
		if (!in_quote && i > 0 && !ft_isspace(s[i]) && ft_isspace(s[i - 1]))
			idcs[j++] = i - 1;
		if (s[i] == '"' || s[i] == '\'')
			set_quote_state(s[i], &in_quote);
	}
	idcs[j] = ft_strlen(s);
	return (idcs);
}

t_list	*smart_split(char *s)
{
	t_list	*out;
	int		nspaces;
	int		*indices;
	int		i;
	char	*sdup;

	if (!s)
		return (0);
	nspaces = count_spaces(s) + 2;
	indices = malloc(nspaces * sizeof(int));
	if (!indices)
		return (0);
	ft_memset(indices, 0xff, nspaces * sizeof(int));
	out = 0;
	mark(s, indices);
	i = 0;
	while (i < nspaces - 1 && indices[++i] != -1)
	{
		sdup = ft_substr(s, indices[i - 1] + 1, indices[i] - indices[i - 1] - 1);
		ft_lstadd_back(&out, ft_lstnew((void *)sdup));
	}
	free(indices);
	return (out);
}

/* int	main(void)
{
	char	*s;
	t_list	*tok;
	t_list *head;

	s = "ls -al a* | grep me > outfile";
	tok = smart_split(s);
	head = tok;
	while (tok)
	{
		ft_printf("%s\n", (char *)tok->content);
		tok = tok->next;
	}
	ft_lstclear(&head, free);
	return (0);
} */
