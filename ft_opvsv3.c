/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opvsv3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:40:09 by jsandsla          #+#    #+#             */
/*   Updated: 2020/11/28 13:07:08 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mulvs_v3(t_v3 l, float r, t_v3 out)
{
	out[0] = l[0] * r;
	out[1] = l[1] * r;
	out[2] = l[2] * r;
}

void	ft_divvs_v3(t_v3 l, float r, t_v3 out)
{
	out[0] = l[0] / r;
	out[1] = l[1] / r;
	out[2] = l[2] / r;
}

void	ft_addvs_v3(t_v3 l, float r, t_v3 out)
{
	out[0] = l[0] + r;
	out[1] = l[1] + r;
	out[2] = l[2] + r;
}

void	ft_subvs_v3(t_v3 l, float r, t_v3 out)
{
	out[0] = l[0] - r;
	out[1] = l[1] - r;
	out[2] = l[2] - r;
}

void	ft_subsv_v3(float l, t_v3 r, t_v3 out)
{
	out[0] = l - r[0];
	out[1] = l - r[1];
	out[2] = l - r[2];
}
