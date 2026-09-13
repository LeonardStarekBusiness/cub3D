#include "complex_math.h"

// Represents the length of a vector.
double	vec_magnitude(t_vector vec)
{
	return (fast_sqrt(vec.x * vec.x + vec.y * vec.y));
}

// Creates a vector of same orientation but magnitude 1
t_vector	vec_normalize(t_vector vec)
{
	double	m;

	m = vec_magnitude(vec);
	return ((t_vector){vec.x / m, vec.y / m});
}