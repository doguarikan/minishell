/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:46:30 by darikan           #+#    #+#             */
/*   Updated: 2024/09/24 19:46:32 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	append_ty(t_ty **head, t_ty *new_ty)
{
	t_ty	*current;

	if (*head == NULL)
		*head = new_ty;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_ty;
	}
}

int	add_arg(char ***arg, char *new_arg)
{
	int		i;
	char	**new_arg_list;
	int		j;

	i = 0;
	while ((*arg) && (*arg)[i])
		i++;
	new_arg_list = (char **)malloc(sizeof(char *) * (i + 2));
	if (new_arg_list == NULL)
		return (-1);
	j = -1;
	while (++j < i)
		new_arg_list[j] = (*arg)[j];
	free(*arg);
	new_arg_list[i] = ft_strdup(new_arg);
	if (new_arg_list[i] == NULL)
	{
		free(new_arg_list);
		return (-1);
	}
	new_arg_list[i + 1] = NULL;
	*arg = new_arg_list;
	return (0);
}

int	struct_len(t_line *head)
{
	int		len;
	t_line	*current;

	len = 0;
	current = head;
	while (current != NULL)
	{
		len += 1;
		current = current->next;
	}
	return (len);
}

int	fd_len(t_fd **head)
{
	int		res;
	t_fd	*current;

	res = 0;
	current = *head;
	if (current != NULL)
	{
		res += 1;
		current = current->next;
	}
	return (res);
}
