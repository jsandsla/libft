/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_v.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:32:23 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/27 20:10:41 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_make_v3(t_v3 v, float x, float y, float z)
{
	v[0] = x;
	v[1] = y;
	v[2] = z;
}

void	ft_make_v4(t_v4 v, float x, float y, float z)
{
	v[0] = x;
	v[1] = y;
	v[2] = z;
	v[3] = 0;
}

void	ft_make_m3(t_m3 m, t_v3 c0, t_v3 c1, t_v3 c2)
{
	ft_make_v3(m[0], c0[0], c0[1], c0[2]);
	ft_make_v3(m[1], c1[0], c1[1], c1[2]);
	ft_make_v3(m[2], c2[0], c2[1], c2[2]);
}

void	ft_make_m4(t_m4 m, t_v4 c0, t_v4 c1, t_v4 c2)
{
	ft_make_v4(m[0], c0[0], c0[1], c0[2]);
	ft_make_v4(m[1], c1[0], c1[1], c1[2]);
	ft_make_v4(m[2], c2[0], c2[1], c2[2]);
	ft_make_v4(m[3], 0, 0, 0);
	m[3][3] = 1;
}
