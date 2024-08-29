/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:59:26 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/26 15:14:42 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (str == 0)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		total_len;
	char	*new_str;
	int		i;
	int		j;

	if (s1 == 0)
		return (ft_strdup(s2));
	total_len = (int)ft_strlen(s1) + (int)ft_strlen(s2) + 1;
	new_str = (char *)malloc(sizeof(char) * total_len);
	if (!(new_str))
		return (0);
	i = -1;
	while (++i < (int)ft_strlen(s1))
		new_str[i] = s1[i];
	j = 0;
	while (j < (int)ft_strlen(s2))
		new_str[i++] = s2[j++];
	free(s1);
	new_str[i] = 0;
	s1 = 0;
	return (new_str);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = (int)ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (0);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = -1;
	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}
