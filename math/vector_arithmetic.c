
#include "complex_math.h"

// Add v2 to v1.
t_vector	vec_add(t_vector v1, t_vector v2)
{
	t_vector	sum;

	sum.x = v1.x + v2.x;
	sum.y = v1.y + v2.y;
	return (sum);
}

// Subtract v2 from v1.
t_vector	vec_sub(t_vector v1, t_vector v2)
{
	t_vector	sum;

	sum.x = v1.x - v2.x;
	sum.y = v1.y - v2.y;
	return (sum);
}

// The absolute value of a vector.
t_vector	vec_abs(t_vector vector)
{
	if (vector.x < 0.0)
		vector.x = -vector.x;
	if (vector.y < 0.0)
		vector.y = -vector.y;
	return (vector);
}

// Represents the angle between two vectors.
// Positive: Acute angle.
// Zero: 90° / orthogonal angle.
// Negative: Obtuse angle.
// Calculated like a.x * b.x + a.y * b.y
double	vec_dot(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y);
}
