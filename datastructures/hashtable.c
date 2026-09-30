/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 14:04:32 by lstarek           #+#    #+#             */
/*   Updated: 2026/09/30 14:04:35 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

t_hashtable	*new_hashtable(unsigned long m)
{
	t_hashtable		*new;
	unsigned long	i;

	i = 0;
	new = malloc(sizeof(t_hashtable));
	if (!new)
		return (NULL);
	new->lists = malloc(m * sizeof(t_list));
	while (i < m)
	{
		new->lists[i] = NULL;
		i++;
	}
	if (!new->lists)
		return (NULL);
	new->size = m;
	return (new);
}

void	delete_hashtable(t_hashtable *table)
{
	unsigned long	i;

	if (!table)
		return ;
	i = 0;
	while (i < table->size)
	{
		ft_lstfree(table->lists[i]);
		i++;
	}
	free(table->lists);
	table->lists = NULL;
	free(table);
}

unsigned long	hash(unsigned long key, unsigned long m)
{
	return key % m;
}

bool	hash_insert(t_hashtable *table, unsigned long key, void *value)
{
	int	i;

	i = hash(key, table->size);
	if (table->lists[i])
		return (ft_lstadd(table->lists[i], key, value));
	else
		table->lists[i] = ft_lstnew(key, value);
	return (0);
}

void	*hash_get(t_hashtable *table, unsigned long key)
{
	int		i;
	t_list	*lst;

	i = hash(key, table->size);
	lst = table->lists[i];
	while (lst)
	{
		if (lst->key == key)
			return lst->value;
		lst = lst->next;
	}
	return (NULL);
}