/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 13:58:30 by lstarek           #+#    #+#             */
/*   Updated: 2026/09/30 14:04:28 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

typedef struct	s_list
{
	unsigned long	key;
	void			*value;
	struct s_list	*next;
}				t_list;

typedef struct	s_hashtable
{
	unsigned long	size;
	t_list			**lists;
}				t_hashtable;

t_hashtable	*new_hashtable(unsigned long m);
void		delete_hashtable(t_hashtable *table);
bool		hash_insert(t_hashtable *table, unsigned long key, void *value);
void		*hash_get(t_hashtable *table, unsigned long key);
t_list		*ft_lstnew(unsigned long key, void *value);
bool		ft_lstadd(t_list *list, unsigned long key, void *value);
void		ft_lstfree(t_list *ptr);