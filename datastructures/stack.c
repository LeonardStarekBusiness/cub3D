#include "stack.h"

bool	push(t_stack *stack, int val)
{
	int		*tmp;

	if (stack->size < 0)
		return (false);
	if (stack->size == stack->max_size)
	{
		tmp = calloc(stack->max_size * 2, sizeof(int));
		if (!tmp)
			return (false);
		ft_memcpy(tmp, stack->content, stack->size * sizeof(int));
		free(stack->content);
		stack->content = tmp;
		stack->max_size *= 2;
	}
	stack->content[stack->size] = val;
	stack->size++;
	return (true);
}

int	pop(t_stack *stack)
{
	if (stack->size < 0)
		return (-1);
	stack->size--;
	return (stack->content[stack->size]);
}

bool	isempty(t_stack stack)
{
	return (stack.size == 0);
}

t_stack	stack(void)
{
	t_stack	new;

	new.content = malloc(8 * sizeof(int));
	new.size = 0;
	new.max_size = 8;
	return (new);
}

void	del(t_stack *stack)
{
	free(stack->content);
	stack->content = NULL;
	stack->size = -1;
	stack->max_size = -1;
}
