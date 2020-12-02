/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_v.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:32:23 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/30 13:00:29 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_make_v3(float x, float y, float z, t_v3 out)
{
	out[0] = x;
	out[1] = y;
	out[2] = z;
}

void	ft_make_v4(float x, float y, float z, t_v4 out)
{
	out[0] = x;
	out[1] = y;
	out[2] = z;
	out[3] = 0;
}

void	ft_make_m3(t_v3 c0, t_v3 c1, t_v3 c2, t_m3 out)
{
	ft_make_v3(c0[0], c0[1], c0[2], out[0]);
	ft_make_v3(c1[0], c1[1], c1[2], out[1]);
	ft_make_v3(c2[0], c2[1], c2[2], out[2]);
}

void	ft_make_m4(t_v4 c0, t_v4 c1, t_v4 c2, t_m4 out)
{
	ft_make_v4(c0[0], c0[1], c0[2], out[0]);
	ft_make_v4(c1[0], c1[1], c1[2], out[1]);
	ft_make_v4(c2[0], c2[1], c2[2], out[2]);
	ft_make_v4(0, 0, 0, out[3]);
	out[3][3] = 1;
}
