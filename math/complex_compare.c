/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 14:44:05 by lstarek           #+#    #+#             */
/*   Updated: 2026/09/13 14:44:06 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex_math.h"

void	print_complex(t_complex num)
{
	printf("<%f, %f>\n", num.real, num.i);
}

bool	is_eq_float(double num1, double num2)
{
	if (num1 == num2)
		return (1);
	if ((num1 - num2) > 0.001)
		return (0);
	if ((num2 - num1) > 0.001)
		return (0);
	return (1);
}

bool	is_eq_complex(t_complex num1, t_complex num2)
{
	return (is_eq_float(num1.real, num2.real)
		&& is_eq_float(num1.real, num2.real));
}