/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trig.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 15:12:30 by lstarek           #+#    #+#             */
/*   Updated: 2026/09/13 15:12:31 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex_math.h"

// Limits range, attempts to precompute fixed values,
// then approximates taylor series.
double	ft_sin(double x)
{
	while (x > PI)
		x -= TWOPI;
	while (x < -PI)
		x += TWOPI;
	if (is_eq_float(x, 0))
		return (0);
	if (is_eq_float(x, HALFPI))
		return (1);
	if (is_eq_float(x, PI))
		return (0);
	if (is_eq_float(x, PIANDHALF))
		return (-1);
	return (x
		- ((x * x * x) / 6)
		+ ((x * x * x * x * x) / 120)
		- (x * x * x * x * x * x * x) / 5040);
}

// Limits range, attempts to precompute fixed values,
// then approximates taylor series.
double ft_cos(double x)
{
	while (x > PI)
		x -= TWOPI;
	while (x < -PI)
		x += TWOPI;
	if (is_eq_float(x, 0))
		return (1);
	if (is_eq_float(x, HALFPI))
		return (0);
	if (is_eq_float(x, PI))
		return (-1);
	if (is_eq_float(x, PIANDHALF))
		return (0);
	return (1
		- ((x * x) / 2)
		+ ((x * x * x * x) / 24)
		- ((x * x * x * x * x) / 720));
}
