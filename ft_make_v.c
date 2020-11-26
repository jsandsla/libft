/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_v.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:32:23 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/26 17:15:09 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_v3	ft_make_v3(float x, float y, float z)
{
	t_v3	val;

	val.x = x;
	val.y = y;
	val.z = z;
	return (val);
}

t_v4	ft_make_v4(float x, float y, float z, float w)
{
	t_v4	val;

	val.x = x;
	val.y = y;
	val.z = z;
	val.w = w;
	return (val);
}

t_m3	ft_make_m3(t_v3 r0, t_v3 r1, t_v3 r2)
{
	t_m3	val;

	val.r0 = r0;
	val.r1 = r1;
	val.r2 = r2;
	return (val);
}

t_m4	ft_make_m4(t_v4 r0, t_v4 r1, t_v4 r2, t_v4 r3)
{
	t_m4	val;

	val.r0 = r0;
	val.r1 = r1;
	val.r2 = r2;
	val.r3 = r3;
	return (val);
}
