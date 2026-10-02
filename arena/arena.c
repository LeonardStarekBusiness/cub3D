#include "arena.h"

//Shall be called after arena_init().
void	*arena_malloc(size_t n)
{
	static _Bool	initialised;
	static t_arena	*arena;
	static size_t	blocks_added;

	if (!initialised)
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
	if ((arena->inc + n) > 
		(INIT_SIZE + (blocks_added * ADD_SIZE)))
	{
		if (n > ADD_SIZE)
			exception("block too big!");
		arena->add_blocks[blocks_added] = malloc(ADD_SIZE);
		blocks_added++;
	}
	else if (n > INIT_SIZE)
		exception("block too big!");
	arena->inc += n;
	if (arena->inc > MAX_SIZE)
		exception("out of memory!");
	else if (arena->inc < INIT_SIZE)
		return (arena->memory + arena->inc);
	int i = arena->inc - INIT_SIZE;
	int block = (i / ADD_SIZE);
	return (arena->add_blocks[block] + (i % ADD_SIZE));
}

//Shall be called after arena_init()
void	arena_destroy()
{
	static _Bool	initialised;
	static t_arena	*arena;
	size_t			i;
	size_t			n;

	if (!initialised)
	{
		arena = arena_malloc(0);
		initialised = 1;
		return ;
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
}

//The first call initialises the arena and makes arena_init() and arena_free() usable.
//Using them before is undefined behavior.
void	arena_init()
{
	arena_destroy();
}

void	exception(char *msg)
{
	arena_destroy();
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(1);
}
