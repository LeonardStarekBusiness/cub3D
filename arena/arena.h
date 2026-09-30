//#include "../libft/libft.h"
//Replace these with libft functions later
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct	s_arena
{
	void		*memory;
	void		*ptr;
}				t_arena;

typedef struct	s_gaps
{
	void		*addr[16];
	size_t		size[16];
	unsigned char	last;
}				t_gaps;


void	*arena_malloc(size_t n);
void	arena_init();
void	arena_destroy();
void	exception(char *msg);
