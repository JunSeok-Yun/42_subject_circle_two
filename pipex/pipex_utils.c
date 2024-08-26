/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:36:35 by junseyun          #+#    #+#             */
/*   Updated: 2024/07/24 17:40:27 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_header.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (str == 0)
		return (0);
	while (str[len] != 0)
		len++;
	return (len);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == 0)
		return ((char *)big);
	while (big[i] != 0 && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == 0)
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

static char	*strjoin_input(char const *s1, char const *s2, char *new_str)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != 0)
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[i] = 0;
	j = 0;
	while (s2[j] != 0)
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = 0;
	return (new_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	char	*new_str;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = (char *)malloc(sizeof(char) * total_len);
	if (!(new_str))
		return (0);
	return (strjoin_input(s1, s2, new_str));
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (0);
	while (s[i] != 0)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
