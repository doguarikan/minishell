/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcan <rcan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:06:40 by rcan              #+#    #+#             */
/*   Updated: 2024/09/18 14:06:41 by rcan             ###   ########.fr       */
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
