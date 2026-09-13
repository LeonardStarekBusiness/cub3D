#include "math/complex_math.h"

int main()
{
	u_vec2 vector = {1,0};
	//t_complex numbah = {1,0};
	vector.complex = c_rotate(vector.complex, 45);
	print_complex(vector.complex);
	vector.vector = vec_add(vector.vector, vector.vector);
	print_complex(vector.complex);
	printf("%f\n", fast_sqrt(9));
	printf("%f, %f\n", ft_floor(420.5), ft_ceil(420.5));
}