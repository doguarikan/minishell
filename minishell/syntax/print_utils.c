/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:46:05 by darikan           #+#    #+#             */
/*   Updated: 2024/09/24 20:08:28 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	syntax_error_quote(void)
{
	write(2, "minishell: ", 11);
	printf("Syntax error. Unclosed quote.\n");
	return (0);
}

int	syntax_error_pipe(void)
{
	write(2, "minishell: ", 11);
	printf("Syntax error. Invalid pipe using.\n");
	return (0);
}

int	not_allowed_char_error(void)
{
	write(2, "minishell: ", 11);
	printf("Unexpected character using.\n");
	return (0);
}

int	syntax_error_redir(void)
{
	write(2, "minishell: ", 11);
	printf("Mixed redirect using.\n");
	return (0);
}

int	redirect_dollar(t_split *split)
{
	while (split)
	{
		if (is_redir(split) && split->meta != HEREDOC && \
				split->next->meta == DOLLAR)
		{
			write(2, "minishell: ", 11);
			printf("ambiguous redirect\n");
			return (0);
		}
		split = split->next;
	}
	return (1);
}
