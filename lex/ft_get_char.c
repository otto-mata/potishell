/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:04:07 by tblochet          #+#    #+#             */
/*   Updated: 2025/01/04 16:15:00 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_get_char(char const *input)
{
	static size_t		cur = 0;
	static const char	*_str = 0;
	static size_t		input_sz = 0;
	size_t				ret_i;

	if (_str == 0 && input)
	{
		_str = input;
		input_sz = strlen(_str);
	}
	if (cur >= input_sz)
		return (EOF);
	ret_i = cur;
	cur++;
	return (_str[ret_i]);
}
