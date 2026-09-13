/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math_basic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:16:01 by lstarek           #+#    #+#             */
/*   Updated: 2026/09/13 14:31:24 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex_math.h"

t_complex	c_square(t_complex num)
{
	t_complex	square;

	square.real = (num.real * num.real) - (num.i * num.i);
	square.i = (num.real * num.i * 2.0);
	return (square);
}

t_complex	c_multiply(t_complex num1, t_complex num2)
{
	t_complex	multiple;

	multiple.real = num1.real * num2.real - num1.i * num2.i;
	multiple.i = num1.real * num2.i + num1.i * num2.real;
	return (multiple);
}

t_complex	c_power(t_complex num, int exp)
{
	t_complex	orig;

	orig = num;
	while (exp > 1)
	{
		num = c_multiply(num, orig);
		exp--;
	}
	return (num);
}

