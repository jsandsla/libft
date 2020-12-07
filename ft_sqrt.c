/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:02:41 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/07 17:21:58 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** https://en.wikipedia.org/wiki/
** Methods_of_computing_square_roots#Babylonian_method
*/

double	ft_sqrt(double x)
{
	double	result;
	int		i;

	result = 0;
	if (x > 0)
	{
		result = x / 4;
		i = 0;
		while (i < 20)
		{
			result = 0.5 * (result + x / result);
			i += 1;
		}
	}
	return (result);
}

float	ft_sqrtf(float x)
{
	float	result;
	int		i;

	result = 0;
	if (x > 0)
	{
		result = x / 4;
		i = 0;
		while (i < 20)
		{
			result = 0.5f * (result + x / result);
			i += 1;
		}
	}
	return (result);
}
