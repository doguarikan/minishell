/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:43:15 by darikan           #+#    #+#             */
/*   Updated: 2024/09/24 19:43:17 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	count = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		st;
	char	**str;

	i = 0;
	st = 0;
	if (!s)
		return (NULL);
	str = malloc((ft_count(s, c)) * sizeof(char *));
	if (!str)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			st = 0;
			while (*s && *s != c && ++st)
				++s;
			str[i++] = ft_substr(s - st, 0, st);
		}
		else
			++s;
	}
	str[i] = 0;
	return (str);
}
