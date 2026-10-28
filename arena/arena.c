#include "arena.h"
#include <stdio.h>

void	arena_free(void *ptr)
{
	static _Bool	initialised;
	t_block			*block;
	static t_arena	*arena;

	if (!initialised)
	{
		arena = arena_destroy();
		initialised = 1;
		return ;
	}
	block = ptr - sizeof(t_block);
	if (block->size < 0 || (block->prev < arena->memory && block->prev))
		write(2, "Invalid pointer!", 16);
	else
	{
		block->freed = 1;
	}
}


void	*first_fit(t_arena *arena, size_t n)
{
	if (!arena->inc)
		return (NULL);
	t_block	*block = (void *)arena->memory;
	for (; block->next; block = block->next)
	{
		if (block->freed && block->size >= n)
		{
			return (block);
		}
	}
	return (NULL);
}

//Shall be called after arena_init().
void	*arena_malloc(size_t n)
{
	static _Bool	initialised;
	static t_arena	*arena;
	static size_t	blocks_added;
	static void		*prev_addr;
	t_block			mem_block;
	void			*block_addr;
	void			*r_addr;


	if (!initialised) //initialise arena, reference kept as a static var.
	{
		arena = malloc(sizeof(t_arena));
		arena->memory = malloc(INIT_SIZE);
		arena->add_blocks = ft_calloc(sizeof(void *), (MAX_SIZE / ADD_SIZE));
		if (!(arena->memory))
			exit(1);
		arena->inc = 0;
		initialised = 1;
		return (arena);
	}
	if ((arena->inc + n + sizeof(t_block)) > (INIT_SIZE + (blocks_added * ADD_SIZE)))
	{
		if ((n + sizeof(t_block)) > ADD_SIZE)
			exception("block too big!");
		arena->add_blocks[blocks_added] = malloc(ADD_SIZE);
		blocks_added++;
	}
	else if ((n + sizeof(t_block)) > INIT_SIZE)
		exception("block too big!");
	if (arena->inc > MAX_SIZE)
		exception("out of memory!");
	void *tmp_addr = first_fit(arena, n);
	if (tmp_addr)
		block_addr = tmp_addr;
	else if ((arena->inc + n + sizeof(t_block)) < INIT_SIZE)
	{
		block_addr = arena->memory + arena->inc;
	}
	else
	{
		size_t i = (arena->inc + n + sizeof(t_block)) - INIT_SIZE;
		size_t block = (i / ADD_SIZE);
		block_addr = (arena->add_blocks)[block] + (i % ADD_SIZE);
	}
	if (!tmp_addr) //fresh block
	{
		mem_block.size = n;
		mem_block.freed = 0;
		mem_block.next = block_addr + sizeof(t_block) + n;
		if ((mem_block.next + sizeof(t_block)) >= (arena->memory + INIT_SIZE))
			mem_block.next = NULL; 
		mem_block.prev = prev_addr;
		prev_addr = block_addr;
		if (mem_block.next)
			((t_block *)(mem_block.next))->next = NULL;
		ft_memcpy(block_addr, &mem_block, sizeof(mem_block));
		arena->inc += sizeof(t_block) + n;
	}
	else //reusing block
	{
		((t_block *)tmp_addr)->freed = 0;
	}
	r_addr = block_addr + sizeof(t_block);
	return (r_addr);
}

//Shall be called after arena_init()
void	*arena_destroy()
{
	static _Bool	initialised;
	static t_arena	*arena;
	size_t			i;
	size_t			n;

	if (!initialised)
	{
		arena = arena_malloc(0);
		initialised = 1;
		return (arena);
	}
	i = 0;
	n = MAX_SIZE / ADD_SIZE;
	while (i < n)
	{
		free((arena->add_blocks)[i]);
		i++;
	}
	free(arena->add_blocks);
	free(arena->memory);
	free(arena);
	return (NULL);
}

//The first call initialises the arena and makes arena_init() and arena_free() usable.
//Using them before is undefined behavior.
void	arena_init()
{
	arena_free(NULL);
}

_Noreturn void	exception(char *msg)
{
	arena_destroy();
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(1);
}
