/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   btree_apply_by_level.c                               ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/04 21:54:50 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/04 22:13:01 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	ft_btree_level_count(t_btree *root)
{
	int	count;

	count = 0;
	if (root == 0)
		return (0);
	if (root->left)
		count = ft_max(count, ft_btree_level_count(root->left));
	if (root->right)
		count = ft_max(count, ft_btree_level_count(root->right));
	return (count + 1);
}

static void	call(t_btree *root, int current_level, int *levels,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	is_first_item;

	is_first_item = 1;
	if (levels[current_level] == 1)
		is_first_item = 0;
	else
		levels[current_level] = 1;
	applyf(root->item, current_level, is_first_item);
	if (root->left)
		call(root->left, current_level + 1, levels, applyf);
	if (root->right)
		call(root->right, current_level + 1, levels, applyf);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	int	count;
	int	*levels;
	int	i;

	if (root == 0)
		return ;
	count = ft_btree_level_count(root);
	levels = malloc(sizeof(int) * count);
	if (!levels)
		return ;
	i = 0;
	while (i < count)
		levels[i++] = 0;
	call(root, 0, levels, applyf);
	free(levels);
}
