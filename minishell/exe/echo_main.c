/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:36:48 by darikan           #+#    #+#             */
/*   Updated: 2024/09/24 19:36:49 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	echo_main(char *s)
{
	int	ind;

	if (!s)
	{
		printf("\n");
		return (0);
	}
	ind = echo_index(s);
	printf("%s", &s[ind]);
	if (ind < 3)
		printf("\n");
	return (0);
}
