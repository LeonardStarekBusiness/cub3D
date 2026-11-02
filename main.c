#include "cub3D.h"
#include <stdio.h>

int main(void)
{
	arena_init();
	char *str = arena_malloc(20);
	ft_memcpy(str, "This is BAAL", 14);
	printf("%s\n", str); 
	for (size_t i = INIT_SIZE+1; i > 1; i /= 2)
	{
		void *ptr = arena_malloc(i);
		printf("addr: %zu\n", (size_t)ptr);
		if (i < 10000)
			terminate("This is insane!");
		arena_free(ptr);
	}
	arena_destroy();
}
