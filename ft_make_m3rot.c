/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_m3rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:42:19 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/07 17:28:38 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

void	ft_make_m3rot_x(float angle, t_m3 out)
{
	float	c;
	float	s;

	c = cosf(angle);
	s = sinf(angle);
	ft_identity_m3(out);
	out[1][1] = c;
	out[2][1] = -s;
	out[1][2] = s;
	out[2][2] = c;
}

void	ft_make_m3rot_y(float angle, t_m3 out)
{
	float	c;
	float	s;

	c = cosf(angle);
	s = sinf(angle);
	ft_identity_m3(out);
	out[0][0] = c;
	out[0][2] = -s;
	out[2][0] = s;
	out[2][2] = c;
}

void	ft_make_m3rot_z(float angle, t_m3 out)
{
	float	c;
	float	s;

	c = cosf(angle);
	s = sinf(angle);
	ft_identity_m3(out);
	out[0][0] = c;
	out[1][0] = -s;
	out[0][1] = s;
	out[1][1] = c;
}
