/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 14:24:55 by lstarek           #+#    #+#             */
/*   Updated: 2026/09/13 14:24:57 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_MATH_H
# define COMPLEX_MATH_H
# include <stdio.h>
# include <stdbool.h>
# define PI 3.14159265358979323846
# define HALFPI 1.57079632679
# define TWOPI 6.28318530718
# define PIANDHALF 4.71238898038
# define THREEHALFS 1.5F
# define DEGTORAD 0.01745329251
# define FASTMATH 1


// The vector can be interpreted as a vector or complex number
// depending on the operation.
// This is why a union is used.
// invoke u_vec2.vector for vector math operations
// and u_vec2.complex for complex math operations.
typedef struct	s_complex
{
	double		real;
	double		i;
}				t_complex;

typedef struct	s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef union
{
	t_complex	complex;
	t_vector	vector;
}				u_vec2;

// COMPLEX NUMBER BASIC OPERATIONS
t_complex	c_square(t_complex num);
t_complex	c_multiply(t_complex num1, t_complex num2);
t_complex	c_power(t_complex num, int exp);

// VECTOR MATH
t_vector	vec_add(t_vector num1, t_vector num2);
t_vector	vec_abs(t_vector complex);
t_vector	vec_sub(t_vector v1, t_vector v2);
double		vec_dot(t_vector a, t_vector b);
double		vec_magnitude(t_vector vec);
t_vector	vec_normalize(t_vector vec);

// TRIG AND ROTATIONS
double		ft_sin(double x);
double		ft_cos(double x);
t_complex	c_rotate(t_complex vec, float deg);

// HELPERS
void		print_complex(t_complex num);
bool		is_eq_float(double num1, double num2);
bool		is_eq_complex(t_complex num1, t_complex num2);

// Square root
float		fast_sqrt(float x);

// ROUNDING
double		ft_min(double a, double b);
double		ft_max(double a, double b);
double		ft_clamp(double num, double min, double max);
double		ft_floor(double num);
double		ft_ceil(double num);

#endif //COMPLEX_MATH_H
