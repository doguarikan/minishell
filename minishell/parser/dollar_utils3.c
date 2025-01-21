/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:45:16 by darikan           #+#    #+#             */
/*   Updated: 2024/09/24 19:45:18 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_qm(char **new_str, t_exit_status *exit_t)
{
	char	*res;
	char	*temp;

	res = ft_itoa(exit_t->exit_code);
	temp = ft_strjoin(*new_str, res);
	free(*new_str);
	*new_str = temp;
	free(res);
}

char	*remove_quotes_two(t_split **split, t_mini **mini, \
	t_exit_status *exit_t)
{
	int		i;
	char	*new_str;
	char	*str;

	i = 0;
	new_str = malloc(1);
	new_str[0] = 0;
	str = (*split)->node;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] && str[i + 1] == '?')
		{
			get_qm(&new_str, exit_t);
			i++;
		}
		else
			i = update_index(str, &new_str, i, mini);
		i++;
	}
	free(str);
	return (new_str);
}

int	update_index(char *str, char **new_str, int i, t_mini **mini)
{
	char	*temp;
	int		flag;

	flag = 1;
	if (str[i] == '$' && str[i + 1] && \
		(ft_isalnum(str[i + 1]) || str[i + 1] == '_'))
		i = get_dollar(str, i + 1, mini, new_str);
	else if (str[i] == '\'' && flag == 1)
		i = get_single_quote(str, i + 1, new_str);
	else if (str[i] == '\"')
		flag ^= 1;
	else
	{
		temp = ft_calloc(ft_strlen(*new_str) + 2, 1);
		ft_strcpy(temp, *new_str);
		temp[ft_strlen(*new_str)] = str[i];
		temp[ft_strlen(*new_str) + 1] = 0;
		free(*new_str);
		*new_str = ft_strdup(temp);
		free(temp);
	}
	return (i);
}
