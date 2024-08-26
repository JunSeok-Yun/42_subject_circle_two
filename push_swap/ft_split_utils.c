/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:47:46 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/17 16:35:18 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = -1;
	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

char	**ft_split_res(char **res, int n, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && check_sep_all(str[i]))
			i++;
		j = i;
		while (str[i] && !(check_sep_all(str[i])))
			i++;
		if (i > j)
		{
			res[n] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(res[n++], &str[j], i - j);
		}
		if (n > 0 && res[n - 1] == NULL)
			free_str(res);
	}
	res[n] = 0;
	return (res);
}

char	**ft_split_arr_res(char **res, int n, int *size, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && check_sep_all(str[i]))
			i++;
		j = i;
		while (str[i] && !(check_sep_all(str[i])))
			i++;
		if (i > j)
		{
			res[n] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(res[n++], &str[j], i - j);
			(*size)++;
		}
		if (n > 0 && res[n - 1] == NULL)
			free_str(res);
	}
	res[n] = 0;
	return (res);
}
