/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:44:40 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/16 14:48:27 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sep_all(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	word_count(char *str)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] && check_sep_all(str[i]))
			i++;
		if (str[i])
			wc++;
		while (str[i] && !(check_sep_all(str[i])))
			i++;
	}
	return (wc);
}

char	**ft_split(char *str)
{
	int		wc;
	char	**res;

	wc = word_count(str);
	res = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!(res))
		return (0);
	res = ft_split_res(res, 0, str);
	return (res);
}

char	**ft_split_arr(char *str, int *size)
{
	int		wc;
	char	**res;

	wc = word_count(str);
	res = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!(res))
		return (0);
	res = ft_split_arr_res(res, 0, size, str);
	return (res);
}
