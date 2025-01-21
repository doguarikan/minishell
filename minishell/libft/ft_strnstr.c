/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:44:13 by darikan           #+#    #+#             */
/*   Updated: 2024/09/24 19:44:15 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *ndl, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ndl[0] == '\0')
		return ((char *)h);
	while (h[i] != '\0' && i < n)
	{
		if (h[i] == ndl[j])
		{
			while (h[i + j] == ndl[j] && i + j < n)
			{
				if (ndl[j + 1] == '\0')
					return ((char *)h + i);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
