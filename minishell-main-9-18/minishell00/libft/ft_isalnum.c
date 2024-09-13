/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcan <rcan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:39:14 by ngulcift          #+#    #+#             */
/*   Updated: 2024/08/23 21:01:40 by rcan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int i)
{
	if ((i >= '0' && i <= '9') || (i >= 'a' && i <= 'z')
		|| (i >= 'A' && i <= 'Z'))
	{
		return (1);
	}
	return (0);
}
