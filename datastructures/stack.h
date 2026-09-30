/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 17:17:43 by lstarek           #+#    #+#             */
/*   Updated: 2026/09/24 17:17:44 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STACK_H
# define STACK_H
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct	s_stack
{
	int				*content;
	unsigned short	size;
	unsigned short	max_size;
}				t_stack;

bool	push(t_stack *stack, int val);
int		pop(t_stack *stack);
bool	isempty(t_stack stack);
t_stack	stack(void);
void	del(t_stack *stack);


#endif //STACK_H
