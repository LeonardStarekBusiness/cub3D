/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math_rotations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 14:31:37 by lstarek           #+#    #+#             */
/*   Updated: 2026/09/13 14:31:38 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex_math.h"

// Rotates the complex number z by deg degrees.
// Cast a vector to t_complex to rotate it.
t_complex	c_rotate(t_complex z, float deg)
{
	float	rad;

	rad = deg * DEGTORAD;
	return (c_multiply(z, 
		(t_complex){ft_cos(rad), ft_sin(rad)}));
}
