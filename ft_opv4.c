/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opv4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:23:26 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/27 18:01:29 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mul_v4(t_v4 l, t_v4 r, t_v4 out)
{
	out[0] = l[0] * r[0];
	out[1] = l[1] * r[1];
	out[2] = l[2] * r[2];
	out[3] = l[3] * r[3];
}

void	ft_div_v4(t_v4 l, t_v4 r, t_v4 out)
{
	out[0] = l[0] / r[0];
	out[1] = l[1] / r[1];
	out[2] = l[2] / r[2];
	out[3] = l[3] / r[3];
}

void	ft_add_v4(t_v4 l, t_v4 r, t_v4 out)
{
	out[0] = l[0] + r[0];
	out[1] = l[1] + r[1];
	out[2] = l[2] + r[2];
	out[3] = l[3] + r[3];
}

void	ft_sub_v4(t_v4 l, t_v4 r, t_v4 out)
{
	out[0] = l[0] - r[0];
	out[1] = l[1] - r[1];
	out[2] = l[2] - r[2];
	out[3] = l[3] - r[3];
}
