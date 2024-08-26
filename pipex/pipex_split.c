/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:35:44 by junseyun          #+#    #+#             */
/*   Updated: 2024/07/24 17:40:18 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_header.h"

static int	count_word(char *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s != 0)
	{
		if (*s == '\'')
		{
			s = single_quote_idx(s);
			cnt++;
		}
		else if (!(check_sep(*s, c)))
		{
			cnt++;
			while (*s != 0 && !(check_sep(*s, c)))
				s++;
		}
		else
			s++;
	}
	return (cnt);
}

static char	*word_strdup(char *str, char c)
{
	char	*new_str;
	int		len;
	int		i;
	int		j;

	len = 0;
	len += single_quote_count_word(str, c);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(new_str))
		return (0);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (str[j] == '\'')
			j++;
		else
		{
			new_str[i] = str[j];
			i++;
			j++;
		}
	}
	new_str[i] = 0;
	return (new_str);
}

static int	free_point(char **res, int i)
{
	free_str(res, i);
	return (0);
}

static	char	**ft_split_res(char **res, char *s, char c)
{
	int		i;

	i = 0;
	while (*s != 0)
	{
		if (*s == '\'')
		{
			res[i++] = word_strdup(s, c);
			s = single_quote_idx(s);
		}
		else if (!(check_sep(*s, c)))
		{
			res[i++] = word_strdup(s, c);
			while (!(check_sep(*s, c)) && *s != 0)
				s++;
		}
		else
			s++;
		if (i > 0 && res[i - 1] == NULL)
			free_point(res, i - 1);
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char *s, char c)
{
	int		word_cnt;
	char	**res;

	word_cnt = count_word(s, c);
	res = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (!(res))
		return (0);
	return (ft_split_res(res, s, c));
}
