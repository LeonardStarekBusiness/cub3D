/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quake_sqrt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 15:35:24 by lstarek           #+#    #+#             */
/*   Updated: 2026/09/13 15:35:26 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex_math.h"

// The fast inverse square root algorithm from Quake III (1999)
// computes 1 / sqrt(x)
static float	Q_rsqrt(float number)
{
	long		i;
	float		x2;
	float		y;

	x2 = number * 0.5F;
	y = number;
	i = *(long *)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float *)&i;
	y = y * (THREEHALFS - (x2 * y * y));
	if (!FASTMATH)
		y = y * (THREEHALFS - (x2 * y * y));
	return (y);
}

// Square root of x.
float	fast_sqrt(float x)
{
	return (x * Q_rsqrt(x));
}
