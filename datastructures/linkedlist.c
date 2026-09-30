/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 14:11:28 by lstarek           #+#    #+#             */
/*   Updated: 2026/09/30 14:11:29 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

t_list *ft_lstnew(unsigned long key, void *value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->key = key;
	new->value = value;
	new->next = NULL;
	return (new);
}

bool	ft_lstadd(t_list *list, unsigned long key, void *value)
{
	t_list			*appendix;

	if (!list)
		return (1);
	while (list)
	{
		if (list->key == key)
		{
			free(list->value);
			list->value = value;
			return (0);
		}
		if (!list->next)
			break ;
		list = list->next;
	}
	appendix = malloc(sizeof(t_list));
	if (!appendix)
		return (1);
	appendix->key = key;
	appendix->value = value;
	appendix->next = NULL;
	list->next = appendix;
	return (0);
}

void	ft_lstfree(t_list *ptr)
{
	if (!ptr)
		return ;
	if (ptr->next == NULL)
	{
		free(ptr->value);
		free(ptr);
	}
	else
	{
		ft_lstfree(ptr->next);
		free(ptr->value);
		free(ptr);
	}
}
