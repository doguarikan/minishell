/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:46:19 by darikan           #+#    #+#             */
/*   Updated: 2024/09/24 19:46:21 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_command(t_line *head)
{
	t_line	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free_arg_list(temp->arg);
		free(temp->cmd);
		free_fd_list(temp->right);
		free_fd_list(temp->left);
		free(temp);
	}
}

void	free_fd_list(t_fd *head)
{
	t_fd	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->name);
		free(temp);
	}
}

void	free_ty_list(t_ty *head)
{
	t_ty	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	free_arg_list(char **arg)
{
	int	i;

	i = 0;
	if (arg == NULL)
		return ;
	while (arg[i] != NULL)
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}
