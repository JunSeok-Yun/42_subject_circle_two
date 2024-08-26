/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_single_quote.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:35:34 by junseyun          #+#    #+#             */
/*   Updated: 2024/07/24 16:56:26 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_header.h"

int	check_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

char	*single_quote_idx(char *s)
{
	s++;
	while (*s != '\'')
		s++;
	s++;
	return (s);
}

int	single_quote_word_len(char *str)
{
	int	len;

	len = 0;
	str++;
	while (*str != '\'')
	{
		str++;
		len++;
	}
	return (len);
}

int	single_quote_count_word(char *str, char c)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str[i] && !(check_sep(str[i], c)))
	{
		if (str[i] == '\'')
		{
			len += single_quote_word_len(str);
			i = i + len + 2;
		}
		else
		{
			i++;
			len++;
		}
	}
	return (len);
}
