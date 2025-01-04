/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:27:06 by tblochet          #+#    #+#             */
/*   Updated: 2025/01/04 17:11:02 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_get_char(char const *);
int tokenize(char const *, char *);

int main(void)
{
	char	*s;
	char	token[256];
	int		ret;
	
	s = "df | grep '/dev/' | grep -v 'boot$' | awk '{used += $3; av += $4} END {printf \"free: %dM, used: %dM\\n\", av / 1024, used / 1024}' > \"$HOME/disk usage report.log\"";
	while ((ret = tokenize(s, token)) != EOF)
		printf("%d => %s\n", ret, token);
}
