#include "../libft/libft.h"
#ifndef INIT_SIZE
# define INIT_SIZE 131072
#endif
#ifndef ADD_SIZE
# define ADD_SIZE 65536
#endif
#ifndef MAX_SIZE
# define MAX_SIZE 16777216
#endif


typedef struct	s_arena
{
	void		*memory;
	size_t		inc;
	void		**add_blocks;
}				t_arena;

void	arena_init();
void	*arena_malloc(size_t n);
void	exception(char *msg);
void	arena_destroy();
