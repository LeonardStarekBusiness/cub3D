/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 19:26:06 by lstarek           #+#    #+#             */
/*   Updated: 2026/09/13 19:26:08 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "limits.h"

double	ft_min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

double	ft_max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

double	ft_clamp(double num, double min, double max)
{
	if (num < min)
		return (min);
	if (num > max)
		return (max);
	return (num);
}

double	ft_floor(double num)
{
	long long	n;
	double		d;

	if (num >= (double)LLONG_MAX || num <= (double)LLONG_MIN || num != num)
	{
		return num;
	}
	n = (long long)num;
	d = (double)n;
	if (d == num || num >= 0)
		return (d);
	else
		return (d - 1);
}

double	ft_ceil(double num)
{
	long long	n;
	double		d;

	if (num >= (double)LLONG_MAX || num <= (double)LLONG_MIN || num != num)
	{
		return num;
	}
	n = (long long)num;
	d = (double)n;
	if (d == num || num >= 0)
		return (d + 1);
	else
		return (d);
}

//min max clamp floor ceil
