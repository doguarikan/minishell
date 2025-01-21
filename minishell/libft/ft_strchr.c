/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:43:21 by darikan           #+#    #+#             */
/*   Updated: 2024/09/24 19:43:23 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	while ((*str != '\0') && (*str != (char)ch))
	{
		str++;
	}
	if (*str == (char)ch)
	{
		return ((char *)str);
	}
	return (NULL);
}
