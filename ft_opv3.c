/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opv3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:38:48 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/27 17:57:51 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mul_v3(t_v3 l, t_v3 r, t_v3 out)
{
	out[0] = l[0] * r[0];
	out[1] = l[1] * r[1];
	out[2] = l[2] * r[2];
}

void	ft_div_v3(t_v3 l, t_v3 r, t_v3 out)
{
	out[0] = l[0] / r[0];
	out[1] = l[1] / r[1];
	out[2] = l[2] / r[2];
}

void	ft_add_v3(t_v3 l, t_v3 r, t_v3 out)
{
	out[0] = l[0] + r[0];
	out[1] = l[1] + r[1];
	out[2] = l[2] + r[2];
}

void	ft_sub_v3(t_v3 l, t_v3 r, t_v3 out)
{
	out[0] = l[0] - r[0];
	out[1] = l[1] - r[1];
	out[2] = l[2] - r[2];
}
