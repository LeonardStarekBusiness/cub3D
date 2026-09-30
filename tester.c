#include "cub3D.h"

int main()
{
	//MATH
	u_vec2 vector = {{1,0}};
	vector.complex = c_rotate(vector.complex, 45);
	print_complex(vector.complex);
	vector.vector = vec_add(vector.vector, vector.vector);
	print_complex(vector.complex);
	printf("%f\n", fast_sqrt(9));
	printf("%f, %f\n", ft_floor(420.5), ft_ceil(420.5)); 
	
	//STACK
	t_stack stack1 = stack();
	printf("%d, %d\n", stack1.size, stack1.max_size);
	for (int i = 42; i < 100; i++)
		push(&stack1, i);
	while (!isempty(stack1))
		printf("popped %d\n", pop(&stack1));
	del(&stack1); 

	//HASHTABLE
	t_hashtable *tisch = new_hashtable(10);
	hash_insert(tisch, 1, ft_strdup("funny"));
	hash_insert(tisch, 1, ft_strdup("unfunny"));
	hash_insert(tisch, 11, ft_strdup("DER TOODE NAHHHT"));
	hash_insert(tisch, 22, ft_strdup("book of the dead"));
	printf("1: %s\n", (char *)hash_get(tisch, 1));
	printf("11: %s\n", (char *)hash_get(tisch, 11));
	printf("22: %s\n", (char *)hash_get(tisch, 22));
	delete_hashtable(tisch);
}
