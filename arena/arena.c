#include "arena.h"

//Shall be called after arena_init().
void	*arena_malloc(size_t n)
{
	static _Bool	initialised;
	static t_arena	arena;

	if (!initialised)
	{
		arena.memory = malloc(1073741824);
		if (!arena.memory)
			exit(1);
		arena.ptr = arena.memory;
		initialised = 1;
		return (arena.memory);
	}
	arena.ptr += n;
	return (arena.ptr - n);
}

//Shall be called after arena_init()
void	arena_destroy()
{
	static _Bool	initialised;
	static void	*ptr;

	if (!initialised)
	{
		ptr = arena_malloc(0);
		initialised = 1;
		return ;
	}
	free(ptr);
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
	write(2, msg, strlen(msg));
	write(2, "\n", 1);
	exit(1);
}
